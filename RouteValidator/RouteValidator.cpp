//
// Created by Leti on 07.05.2022.
//

#include <vector>
#include "RouteValidator.h"
#include "../MyException.h"

RouteValidator::RouteValidator() {

}

RouteValidator::~RouteValidator() {

}

void RouteValidator::ValidateRoute(const Route &r) {
    vector<string> days;
    days.emplace_back("Luni");
    days.push_back("Marti");
    days.push_back("Miercuri");
    days.push_back("Joi");
    days.push_back("Vineri");
    days.push_back("Sambata");
    days.push_back("Duminica");
    if (r.getId() <= 0) { throw MyException("Id must be a positive integer!"); }
    if (r.getPrice() <= 0) {
        throw MyException("Price must be positive!");
    }
    int nr = 0;
    for(string day : days){
        if(r.getDay() == day){
            nr++;
        }
    }
    if(nr == 0){throw MyException("Day must be : Luni/Marti/Miercuri/Joi/Vineri/Sambata/Duminica!");}
}
