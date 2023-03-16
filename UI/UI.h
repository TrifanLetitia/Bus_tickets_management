//
// Created by Leti on 21.04.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_UI_H
#define BUS_TICKETS_MANAGEMENT_UI_H


#include "../Service/Service.h"
#include "../Service/MoneyService.h"

class UI {
private:
    Service s;
    MoneyService MS;
public:
    void PrintMenu();
    void RunMenu();
    void addRouteUI();
    void showRoutesUI();
    void deleteRouteUI();
    void updateRouteUI();
    void getRouteUI();
    void showMoney();
    void addMoneyUI();
    void withdrawMoney();
    ~UI();
    UI();
    UI(Service& s, MoneyService& MS);
    void buyTicket();

};


#endif //BUS_TICKETS_MANAGEMENT_UI_H
