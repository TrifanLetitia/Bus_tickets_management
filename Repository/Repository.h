//
// Created by Leti on 16.04.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_REPOSITORY_H
#define BUS_TICKETS_MANAGEMENT_REPOSITORY_H
#include <iostream>
#include <vector>
#include "../Route/Route.h"

using namespace std;

class Repository {
protected:
     std::vector<Route> routes;
public:
    /// constructor
    Repository();

    /// destructor
    ~Repository();

    /// Adds a ticket to the repo
    virtual void addRoute(const Route& r);

    int getSize() const;

    virtual void deleteRoute(const Route& r);

    virtual Route& getRoute(int id);

    void updateRoute(int id, const Route& r);

    virtual /// return the tickets
    vector<Route> getAll();

    void clear();
};


#endif //BUS_TICKETS_MANAGEMENT_REPOSITORY_H
