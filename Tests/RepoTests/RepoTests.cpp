//
// Created by Leti on 16.04.2022.
//

#include <cassert>
#include "RepoTests.h"
#include "../../Repository/Repository.h"
#include "../../Repository/RepoInFileTXT.h"

void RunAllRepoTests(){
    testRepoInFile();
    testAddRoute();
    testDeleteRoute();
    testUpdateRoute();
    testGetAll();
}
void testAddRoute(){
    Repository r;
    Route r1(1, "CJ-SB", "Luni", 50);
    Route r2(2, "CJ-BV", "Vineri", 65);
    Route r3(3, "NT-CJ", "Luni", 100);
    r.addRoute(r1);
    r.addRoute(r2);
    assert(r.getSize() == 2);
    assert(r.getAll()[0] == r1);
    assert(r.getAll()[1] == r2);
}

void testDeleteRoute(){
    Repository r;
    Route r1(1, "CJ-SB", "Luni", 50);
    Route r2(2, "CJ-BV", "Vineri", 65);
    Route r3(3, "NT-CJ", "Luni", 100);
    r.addRoute(r1);
    r.addRoute(r2);
    r.addRoute(r3);
    assert(r.getSize() == 3);
    r.deleteRoute(r1);
    assert(r.getSize() == 2);
}

void testUpdateRoute(){
    Repository r;
    Route r1(1, "CJ-SB", "Luni", 50);
    Route r2(2, "CJ-BV", "Vineri", 65);
    Route r3(3, "NT-CJ", "Luni", 100);
    r.addRoute(r1);
    r.addRoute(r2);
    Route r4(1, "CJ-NT", "Sambata", 100);
    r.updateRoute(1, r4);
    assert(r.getRoute(1) == r4);
}

void testGetAll(){
    Repository r;
    Route r1(1, "CJ-SB", "Luni", 50);
    Route r2(2, "CJ-BV", "Vineri", 65);
    Route r3(3, "NT-CJ", "Luni", 100);
    r.addRoute(r1);
    r.addRoute(r2);
    r.addRoute(r3);
    assert(r.getAll()[0] == r1);
    assert(r.getAll()[1] == r2);
    assert(r.getAll()[2] == r3);
}

void testRepoInFile(){
    RepoInFileTXT R(R"(C:\Users\Leti\OneDrive\Documente\Bus_tickets_management\Output.txt)");
    Route r1(2, "CJ-SV", "Luni", 50);
    R.addRoute(r1);
    assert(R.getSize() == 1);
    assert(R.getAll()[0] == R.getRoute(2));
    R.deleteRoute(r1);
    assert(R.getSize() == 0);
    R.clear();
}

