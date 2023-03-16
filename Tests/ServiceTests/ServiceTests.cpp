//
// Created by Leti on 21.04.2022.
//

#include <cassert>
#include "ServiceTests.h"
#include "../../Service/Service.h"
#include "../../Repository/RepositoryMoney.h"
RepoInFileTXT repo(R"(C:\Users\Leti\OneDrive\Documente\Bus_tickets_management\RepoTestsIn.txt)");
RepoInFileMoneyTXT repo1;
RouteValidator rV;
Service s(repo, rV);

void RunAllServiceTests(){
    Bank_note b1(20, 100);
    Bank_note b2(50, 50);
    Bank_note b3(50, 20);
    Bank_note b4(100, 10);
    Bank_note b5(100, 5);
    Bank_note b6(100, 1);
    Bank_note b7(100, 0.5);
    Bank_note b8(100, 0.1);
    Bank_note b9(100, 0.05);
    Bank_note b10(100, 0.01);
    repo1.addMoney(b1);
    repo1.addMoney(b2);
    repo1.addMoney(b3);
    repo1.addMoney(b4);
    repo1.addMoney(b5);
    repo1.addMoney(b6);
    repo1.addMoney(b7);
    repo1.addMoney(b8);
    repo1.addMoney(b9);
    repo1.addMoney(b10);
    testAddRouteS();
    testGetAllS();
    testDeleteRouteS();
    testUpdateRouteS();
    testBuyTicket();
    s.clearfile(R"(C:\Users\Leti\OneDrive\Documente\Bus_tickets_management\RepoTestsIn.txt)");
}



void testAddRouteS(){
    Route r1(1, "CJ-SB", "Luni", 50);
    Route r2(2, "CJ-BV", "Vineri", 65);
    Route r3(3, "NT-CJ", "Luni", 100);
    s.addRoute(r1);
    s.addRoute(r2);
    s.addRoute(r3);
    assert(s.getSize() == 3);
    assert(s.getRoute(1) == r1);
    assert(s.getRoute(2) == r2);
    assert(s.getRoute(3) == r3);
}

void testGetAllS(){
    Route r1(1, "CJ-SB", "Luni", 50);
    Route r2(2, "CJ-BV", "Vineri", 65);
    Route r3(3, "NT-CJ", "Luni", 100);
    assert(s.getSize() == 3);
    assert(s.getAll()[0] == r1);
    assert(s.getAll()[1] == r2);
    assert(s.getAll()[2] == r3);
}

void testDeleteRouteS(){
    assert(s.getSize() == 3);
    s.deleteRoute(1);
    s.deleteRoute(2);
    assert(s.getSize() == 1);
}

void testUpdateRouteS(){
    Route r4(3, "SV-BT", "Luni", 50);
    s.updateRoute(3, r4);
    assert(s.getRoute(3) == r4);
    s.deleteRoute(3);
    assert(s.getSize() == 0);
}

void testBuyTicket(){
    /*
    Bank_note b1(20, 100);
    Bank_note b2(50, 50);
    Bank_note b3(50, 20);
    Bank_note b4(100, 10);
    Bank_note b5(100, 5);
    Bank_note b6(100, 1);
    Bank_note b7(100, 0.5);
    Bank_note b8(100, 0.1);
    Bank_note b9(100, 0.05);
    Bank_note b10(100, 0.01);
    repo1.addMoney(b1);
    repo1.addMoney(b2);
    repo1.addMoney(b3);
    repo1.addMoney(b4);
    repo1.addMoney(b5);
    repo1.addMoney(b6);
    repo1.addMoney(b7);
    repo1.addMoney(b8);
    repo1.addMoney(b9);
    repo1.addMoney(b10);
     */
    //map<float, int, greater<float>> money = repo1.getAll();
    assert(s.getSize() == 0);
    Route r5(3, "SB-CJ", "Luni", 50);
    Route r6(4, "SB-CJ", "Luni", 65);
    s.addRoute(r5);
    s.addRoute(r6);
    map<vector<Route>, float> result;
    map<float, int, greater<float>> bnc;
    vector<int> ticktes;
    ticktes.push_back(3);
    ticktes.push_back(4);
    s.buyTicket(2, 120, "SB-CJ", "Luni", result, bnc, repo1.getAll());
    assert(bnc[5] == 1);
}