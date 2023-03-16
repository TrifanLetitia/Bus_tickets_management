//
// Created by Leti on 14.05.2022.
//

#include "MoneyService.h"

MoneyService::MoneyService(RepoInFileMoneyTXT &r, Bank_noteValidator &bV) {
    this->repo = r;
    this->bV = bV;
}

void MoneyService::addMoney(const Bank_note &b) {
    bV.ValidateBank_note(const_cast<Bank_note &>(b));
    repo.addMoney(b);
}

int MoneyService::getSize() {
    return repo.size();
}

std::map<float, int, std::greater<float>>& MoneyService::getAll() {
    return repo.getAll();
}

void MoneyService::deleteMoney(float value, int no) {
    repo.deleteMoney(value, no);
}

void MoneyService::increaseNo(float value, int no) {
    repo.increaseNo(value, no);
}

MoneyService::MoneyService() = default;
