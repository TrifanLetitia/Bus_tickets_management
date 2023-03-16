//
// Created by Leti on 14.05.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_MONEYSERVICE_H
#define BUS_TICKETS_MANAGEMENT_MONEYSERVICE_H


#include "../Repository/RepoInFileMoneyTXT.h"
#include "../Bank_noteValidator/Bank_noteValidator.h"
#include "Service.h"

class MoneyService {
private:
    RepoInFileMoneyTXT repo;
    Bank_noteValidator bV;
public:
    MoneyService(RepoInFileMoneyTXT &r, Bank_noteValidator &bV);

    MoneyService();

    void addMoney(const Bank_note &b);

    std::map<float, int, std::greater<float>>& getAll();

    void increaseNo(float value, int no);

    void deleteMoney(float value, int no);

    int getSize();

    void clearfile(const string& fn);

    void setRepo(RepoInFileMoneyTXT& R);

};


#endif //BUS_TICKETS_MANAGEMENT_MONEYSERVICE_H
