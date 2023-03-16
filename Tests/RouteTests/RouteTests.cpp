//
// Created by Leti on 16.04.2022.
//

#include <cassert>
#include "RouteTests.h"
#include "../../Route/Route.h"

void testRoute(){
    Route p(1, "CJ-SB", "Luni", 50);
    assert(p.getId() == 1);
    assert(p.getCode() == "CJ-SB");
    assert(p.getDay() == "Luni");
    assert(p.getPrice() == 50);
    p.setCode("CJ-BV");
    p.setDay("Luni");
    p.setPrice(65);
    assert(p.getCode() == "CJ-BV");
    assert(p.getDay() == "Luni");
    assert(p.getPrice() == 65);

    Route r1;
    r1 = p;
    assert(r1 == p);
    Route r2(3, "CJ-BV", "Joi", 100);
    assert(r1 < r2);
}