//
// Created by Leti on 07.05.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_ROUTEVALIDATOR_H
#define BUS_TICKETS_MANAGEMENT_ROUTEVALIDATOR_H


#include "../Route/Route.h"

class RouteValidator {
public:
    RouteValidator();
    ~RouteValidator();
    virtual void ValidateRoute(const Route &r);
};


#endif //BUS_TICKETS_MANAGEMENT_ROUTEVALIDATOR_H
