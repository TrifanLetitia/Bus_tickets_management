//
// Created by Leti on 21.04.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_SERVICE_H
#define BUS_TICKETS_MANAGEMENT_SERVICE_H


#include <map>
#include <unordered_map>
#include "../Repository/Repository.h"
#include "../Route/Route.h"
#include "../Repository/RepoInFileTXT.h"
#include "../Repository/RepositoryMoney.h"
#include "../RouteValidator/RouteValidator.h"
#include "../Repository/RepoInFileMoneyTXT.h"
#include "MoneyService.h"

class Service {
private:
    RepoInFileTXT repo;
    RouteValidator r2;
public:
    explicit Service(RepoInFileTXT &r, RouteValidator &r2);

    Service();

    void addRoute(const Route &r);

    std::vector<Route> getAll();

    void deleteRoute(int code);

    void updateRoute(int id, const Route& r);

    int getSize();

    Route getRoute(int code);

    void clearfile(const string& fn);

    void setRepo(RepoInFileTXT& R);

    map<vector<Route>, float> buyTicket(int nr, float sum, const string& code, const string& day, map<vector<Route>, float>& result, map<float, int, greater<float>> &bnc, map<float, int, greater<float>>& money);

    void giveChange(int i, float r, vector<int>& id, map<float, int, greater<float>>& bnc, map<float, int, greater<float>>& money);

    RepoInFileMoneyTXT repo1;
};


#endif //BUS_TICKETS_MANAGEMENT_SERVICE_H
