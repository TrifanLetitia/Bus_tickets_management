//
// Created by Leti on 21.04.2022.
//
#include <vector>
#include <cmath>
#include "Service.h"
#include "../Repository/RepositoryMoney.h"
#include "../MyException.h"

void Service::addRoute(const Route &r) {
    r2.ValidateRoute(r);
    repo.addRoute(r);
}

std::vector<Route> Service::getAll() {
    return repo.getAll();
}

void Service::deleteRoute(int id) {
    Route r = getRoute(id);
    repo.deleteRoute(r);
}

void Service::updateRoute(int id, const Route &r) {
    r2.ValidateRoute(r);
    repo.UpdateRoute(id, r);
}

int Service::getSize() {
    return repo.getSize();
}

Route Service::getRoute(int id) {
    return repo.getRoute(id);
}

Service::Service(RepoInFileTXT &r, RouteValidator &r2) : r2(r2) {
    this->repo = r;
}

void Service::setRepo(RepoInFileTXT &R) {
    this->repo = R;
}

Service::Service()= default;;

void Service::clearfile(const string &fn) {
    repo.clearFile(fn);
}

map<vector<Route>, float>
Service::buyTicket(int nr, float sum, const string &code, const string &day, map<vector<Route>, float> &result,
                   map<float, int, greater<float>> &bnc, map<float, int, greater<float>>& money) {

    vector<int> ids;
    for (int j = 0; j < repo.getSize(); j++) {
        if (code == repo.getAll()[j].getCode() and day == repo.getAll()[j].getDay()) {
            ids.push_back(repo.getAll()[j].getId());
        }
    }
    vector<int> id;
    for (int j = 0; j < nr; j++) {
        {
            id.push_back(ids[j]);
        }
    }
    float sum1;
    for (int i = 0; i < id.size(); i++) {
        sum1 = sum1 + repo.getRoute(id[i]).getPrice();
    }
    vector<Route> tickets;
    for (int j = 0; j < id.size(); j++) {
        tickets.push_back(repo.getRoute(id[j]));
    }
    if (sum < sum1) {
        throw MyException("Not enough money!");
    } else {
        float rest = sum - sum1;
        result.insert(std::make_pair(tickets, rest));
        if (rest == 0) {
            for (int z: id) {
                repo.deleteRoute(repo.getRoute(z));
            }
            return result; }
        else {
            giveChange(0, rest, id, bnc, money);
        }
    }
    return result;
}

void Service::giveChange(int i, float r, vector<int> &id, map<float, int, greater<float>> &bnc, map<float, int, greater<float>>& money) {
    vector<float> elem;
    elem.reserve(money.size());
    for (auto const &pair:money) {
        elem.push_back(pair.first);
    }
    int sumOfElem = 0;
    for (auto const &pair:money) {
        sumOfElem = sumOfElem + pair.first * pair.second;
    }
    if (r > sumOfElem) {
        throw MyException("Not enough money in the vending machine at the moment!Try later!");
    }
    while (i < elem.size()) {
        int div = r / elem[i];
        float rest1 = r - div * elem[i];
        float rest = round(rest1 * 100) / 100;
        if (div == 0) {
            i++;
        } else if (div != 0 and rest == 0) {
            //if (repo1.getAll()[elem[i]] * elem[i] >= r){
             if(money[elem[i]] * elem[i] >= r){
                //repo1.deleteMoney(elem[i], div);
                money[elem[i]] = money[elem[i]] - div;
                bnc.insert(std::make_pair(elem[i], div));
                for (int z: id) {
                    repo.deleteRoute(repo.getRoute(z));
                }
                break;
            } else i++;
        } else if (div != 0 and rest != 0) {
            //if (repo1.getAll()[elem[i]] * elem[i] >= r) {
            if(money[elem[i]] * elem[i] >= r){
                //repo1.deleteMoney(elem[i], div);
                money[elem[i]] = money[elem[i]] - div;
                bnc.insert(std::make_pair(elem[i], div));
                giveChange(i++, rest, id, bnc, money);
                break;
            } else i++;
        }
        if(i == elem.size()-1){throw MyException("Not enough money in the vending machine at the moment!");}
    }
}
