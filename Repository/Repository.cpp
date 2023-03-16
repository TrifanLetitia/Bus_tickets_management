//
// Created by Leti on 16.04.2022.
//

#include <algorithm>
#include "Repository.h"
#include "../MyException.h"

using namespace std;

Repository::Repository()= default;

void Repository::addRoute(const Route& r) {
    for (int i = 0; i < routes.size(); i++) {
        if (r.getId() == getAll()[i].getId()) {
            throw MyException("There is already a ticket with the given id!");
        }
    }
    this->routes.push_back(r);
}

vector<Route> Repository::getAll() {
    return routes;
}

int Repository::getSize() const {
    return routes.size();
}

void Repository::deleteRoute(const Route& r) {
    int nr = 0;
    for (int i = 0; i < routes.size(); i++) {
        if (r.getId() == getAll()[i].getId()) {
            nr++;
        }
    }
    if (nr == 0) throw MyException("No ticket with specified id found!");
    Route toDelete = getRoute(r.getId());
    auto it = std::find(routes.begin(), routes.end(), toDelete);
    this->routes.erase(it);
}

Repository::~Repository() = default;;


Route& Repository::getRoute(int id) {
    if(id <= 0) {throw MyException("Id must be a positive integer!");}
    for (Route& p: routes) {
        if(p.getId() == id){
            return p;
        }
    }
    throw MyException("No ticket with specified id found");
}

void Repository::updateRoute(int id, const Route& r) {
    if(id <= 0) {throw MyException("Id must be a positive integer!");}
    for (int i = 0; i < routes.size(); i++) {
        if (routes[i].getId() == id) {
            std::replace(routes.begin(), routes.end(), routes[i], r);
            return;
        }
    }
    throw MyException("No ticket with specified id found!");
}

void Repository::clear() {
    routes.empty();
}
