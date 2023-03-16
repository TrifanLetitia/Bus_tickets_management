//
// Created by Leti on 21.04.2022.
//

#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <limits>
#include "UI.h"
#include "../MyException.h"

void UI::PrintMenu() {
    std::cout << "\n";
    std::cout << "Choose an option: " << std::endl;
    std::cout << "(1): Add ticket." << std::endl;
    std::cout << "(2): Show tickets." << std::endl;
    std::cout << "(3): Delete ticket." << std::endl;
    std::cout << "(4): Update ticket." << std::endl;
    std::cout << "(5): Get ticket." << std::endl;
    std::cout << "(6): Buy ticket." << std::endl;
    std::cout << "(7): Money." << std::endl;
    std::cout << "(8): Add more money." << std::endl;
    std::cout << "(9): Withdraw money from vending machine." << std::endl;
    std::cout << "(10): Exit." << std::endl;
}

void UI::RunMenu() {
    int opt;
    do {
        PrintMenu();
        try {
            std::cin >> opt;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw MyException("INVALID INPUT!");
            }
        }
        catch (MyException &ex) {
            std::cout << "An exception occurred." << "->";
            std::cout << ex.getMessage();
            continue;
        }
        switch (opt) {
            case 1: {
                addRouteUI();
                break;
            }
            case 2: {
                showRoutesUI();
                break;
            }
            case 3: {
                deleteRouteUI();
                break;
            }
            case 4: {
                updateRouteUI();
                break;
            }
            case 5: {
                getRouteUI();
                break;
            }
            case 6: {
                buyTicket();
                break;
            }
            case 7: {
                showMoney();
                break;
            }
            case 8: {
                addMoneyUI();
                break;
            }
            case 9: {
                withdrawMoney();
                break;
            }
            case 10: {
                exit(0);
            }
            default: {
                std::cout << "ERROR!You have selected an invalid choice." << std::endl;
                break;
            }
        }
    } while (opt != 10);
}

void UI::addRouteUI() {
    try {
        int id;
        string name;
        string code;
        float price;
        std::cout << "Give id:";
        cin >> id;
        std::cout << "Give ticket code: ";
        cin >> code;
        std::cout << "Give ticket day: ";
        cin >> name;
        std::cout << "Give ticket price: ";
        cin >> price;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        Route r(id, code, name, price);
        s.addRoute(r);
    }
    catch (MyException &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
}

void UI::showRoutesUI() {
    cout << "TICKETS: " << endl;
    cout
            << left
            << setw(16)
            << "Id"
            << left
            << setw(16)
            << "Code"
            << left
            << setw(14)
            << "Day"
            << left
            << setw(14)
            << "Price"
            << left
            << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < s.getSize(); i++) {
        cout
                << left
                << setw(15)
                << s.getAll()[i].getId()
                << left
                << setw(15)
                << s.getAll()[i].getCode()
                << left
                << setw(17)
                << s.getAll()[i].getDay()
                << left
                << setw(14)
                << s.getAll()[i].getPrice()
                << endl;
        cout << "-----------------------------------------------------" << endl;
    }
    map<string, int> stock;
    for(int i = 0; i < s.getSize(); i++){
        int nr = 0;
        for(int j = 0; j < s.getSize(); j++){
            if(s.getAll()[i].getDay() == s.getAll()[j].getDay() and s.getAll()[i].getCode() == s.getAll()[j].getCode()){
                string c = s.getAll()[i].getCode() + " ";
                string d = s.getAll()[i].getDay();
                string t = c.append(d);
                nr++;
                stock.insert(std::make_pair(t, nr));
                stock[t] = nr;
            }
        }
    }
    std::cout << "STOCK:" << std::endl;
    for (auto const &pair: stock) {
        std::cout << "Ticket : " << "Code & Day: " << pair.first << " Stock: " << pair.second << endl;
    }
}

void UI::deleteRouteUI() {
    try {
        int id;
        cout << "Give id: ";
        cin >> id;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        if(id <= 0){throw MyException("Id must be a positive integer!");}
        int nr = 0;
        for(int i = 0; i < s.getSize(); i++){
            if(id == s.getAll()[i].getId()){
                nr++;
            }
        }
        if(nr == 0){ throw MyException("No ticket with specified id found");}
        s.deleteRoute(id);
    }
    catch (MyException &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
    /*
    catch (MyException &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
     */
}

void UI::updateRouteUI() {
    int id;
    string name;
    string code;
    float price;
    try {
        cout << "Give id: ";
        cin >> id;
        cout << "Give new code: ";
        cin >> code;
        cout << "Give new day: ";
        cin >> name;
        cout << "Give new price: ";
        cin >> price;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        Route r(id, code, name, price);
        s.updateRoute(id, r);
    }
    catch (MyException &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
}

void UI::getRouteUI() {
    int id;
    try {
        cout << "Give id: ";
        cin >> id;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        cout << s.getRoute(id);
    }
    catch (MyException &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
}

UI::UI(Service &s, MoneyService& MS) {
    this->s = s;
    this->MS = MS;
}

UI::UI() = default;

void UI::buyTicket() {
    /*
    for (auto const &pair: MS.getAll()) {
        std::cout << "Bancnote: " << pair.first << " Nr.: " << pair.second << endl;
    }
    cout << "---------------------------------------------------------------------" << endl;
     */
    try {
        string code;
        string day;
        cout << "Give code: ";
        cin >> code;
        cout << "Give day: ";
        cin >> day;
        if (day != "Luni" and day != "Marti" and day != "Miercuri" and day != "Joi" and
            day != "Vineri" and day != "Sambata" and day != "Duminica") {
            throw MyException("Day must be : Luni/Marti/Miercuri/Joi/Vineri/Sambata/Duminica!");
        }
        float sum;
        int nr1;
        vector<int> tickets;
        vector<int> id;
        map<float, int, greater<float>> bnc;
        vector<float> sums;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        int nr = 0;
        float sum1 = 0;
        for (int j = 0; j < s.getSize(); j++) {
            if (code == s.getAll()[j].getCode() and day == s.getAll()[j].getDay()) {
                nr++;
                tickets.push_back(s.getAll()[j].getId());
            }
        }
        if (nr == 0) {throw MyException("There are no tickets with the required dates!");}
        cout << "Tickets in stock: " << nr << endl;
        cout << "How many tickets do you want?: ";
        cin >> nr1;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        if(nr1 <= 0){throw MyException("Enter a positive number!");}
        map<vector<Route>, float> result;
        if (nr1 > nr) {
            throw MyException("Not enough tickets!");
        } else {
            for(int i = 0; i < nr1; i++){
                sum1 = sum1 + s.getRoute(tickets[i]).getPrice();
                id.push_back(tickets[i]);
            }
            cout << "Enter money to pay for the ticket ( " << sum1 << " ): ";
            cin >> sum;
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// and remove the bad input
                throw MyException("INVALID INPUT!");
            }
            sum = roundf(sum*100)/100;
            sums.push_back(sum);
            /*
            if(sum != 500 and sum != 200 and sum != 100 and sum != 50 and sum != 20 and sum != 10 and sum != 5 and sum != 1 and sum != 0.5 and sum != 0.1 and sum != 0.05 and sum != 0.01){
                throw MyException("BANKNOTES CAN ONLY BE 500/200/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");
            }
             */
            if((abs(sum - 500) >= 1e-9) and (abs(sum - 200) >= 1e-9) and (abs(sum - 100) >= 1e-9) and
               (abs(sum - 50) >= 1e-9) and  (abs(sum - 20) >= 1e-9) and  (abs(sum - 10) >= 1e-9) and
               (abs(sum - 5) >= 1e-9) and  (abs(sum - 1) >= 1e-9) and  (abs(sum - 0.5) >= 1e-9) and
               (abs(sum - 0.1) >= 1e-9) and  (abs(sum - 0.01) >= 1e-9) and  (abs(sum - 0.05) >= 1e-9)){
                throw MyException("BANKNOTES CAN ONLY BE 500/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");
            }
            float sum2;
            while(sum < sum1){
                cout << "Enter more money: ";
                cin >> sum2 ;
                if (!std::cin)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw MyException("INVALID INPUT!");
                }
                sum2 = roundf(sum2*100)/100;
                sums.push_back(sum2);
                /*
                if(sum2 != 500 and sum2 != 200 and sum2 != 100 and sum2 != 50 and sum2 != 20 and sum2 != 10 and sum2 != 5 and sum2 != 1 and sum2 != 0.5 and sum2 != 0.1 and sum2 != 0.05 and sum2 != 0.01){
                    throw MyException("BANKNOTES CAN ONLY BE 500/200/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");
                }
                 */
                if((abs(sum2 - 500) >= 1e-9) and (abs(sum2 - 200) >= 1e-9) and (abs(sum2 - 100) >= 1e-9) and
                   (abs(sum2 - 50) >= 1e-9) and  (abs(sum2 - 20) >= 1e-9) and  (abs(sum2 - 10) >= 1e-9) and
                   (abs(sum2 - 5) >= 1e-9) and  (abs(sum2 - 1) >= 1e-9) and  (abs(sum2 - 0.5) >= 1e-9) and
                   (abs(sum2 - 0.1) >= 1e-9) and  (abs(sum2 - 0.01) >= 1e-9) and  (abs(sum2 - 0.05) >= 1e-9)){
                    throw MyException("BANKNOTES CAN ONLY BE 500/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");
                }
                sum = sum + sum2;
            }
            s.buyTicket(nr1, sum, code, day, result, bnc, MS.getAll());
            for(float & sum1 : sums){
                MS.increaseNo(sum1, 1);
            }
            for (auto const &pair: result) {
                std::cout << "Your tickets: ";
                vector<Route> inVect = (pair).first;
                for (auto & j : inVect) {
                    cout << j << endl;}
                cout << " // Change: " << pair.second << " (";
                for (auto const &pair1: bnc) {
                    std::cout << pair1.first << " x " << pair1.second << " + ";
                }
                cout << " )";
                cout << endl;
            }
        }
    }
    catch (MyException &ex) {
        //std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
}

void UI::showMoney() {
    for (auto const &pair: MS.getAll()) {
        std::cout << "Bancnote: " << pair.first << " Nr.: " << pair.second << endl;
    }
}

void UI::addMoneyUI() {
    try {
        int no;
        float value;
        std::cout << "Give the value of the banknote:";
        cin >> value;
        std::cout << "Give the number of banknotes: ";
        cin >> no;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        Bank_note b(no, value);
        MS.addMoney(b);
    }
    catch (MyException &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
}

void UI::withdrawMoney() {
    try {
        float value;
        int no;
        cout << "Bank-note value: ";
        cin >> value;
        cout << "Number of bank-notes: ";
        cin >> no;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw MyException("INVALID INPUT!");
        }
        MS.deleteMoney(value, no);
    }
    catch (MyException &ex) {
        std::cout << "An exception occurred." << "->";
        std::cout << ex.getMessage();
    }
}

UI::~UI() = default;
