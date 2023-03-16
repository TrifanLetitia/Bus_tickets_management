//
// Created by Leti on 06.05.2022.
//

#include <cmath>
#include "RepositoryMoney.h"
#include "../MyException.h"

RepositoryMoney::RepositoryMoney() = default;

RepositoryMoney::RepositoryMoney(const std::map<float, int, std::greater<float>> &money) {
    this->money = money;
}

void RepositoryMoney::addMoney(const Bank_note &r) {
    if(money.count(r.getValue()) == 1) {
        money[r.getValue()] = money[r.getValue()] + r.getNo();
    }
    else {
        this->money.insert(std::make_pair(r.getValue(), r.getNo()));
    }
}

std::map<float, int, std::greater<float>>& RepositoryMoney::getAll() {
    return money;
}

void RepositoryMoney::deleteMoney(float value, int no) {
    if((abs(value - 500) >= 1e-9) and (abs(value - 200) >= 1e-9) and (abs(value - 100) >= 1e-9) and
       (abs(value - 50) >= 1e-9) and  (abs(value - 20) >= 1e-9) and  (abs(value - 10) >= 1e-9) and
       (abs(value - 5) >= 1e-9) and  (abs(value - 1) >= 1e-9) and  (abs(value - 0.5) >= 1e-9) and
       (abs(value - 0.1) >= 1e-9) and  (abs(value - 0.01) >= 1e-9) and  (abs(value - 0.05) >= 1e-9)){
        throw MyException("VALUE CAN ONLY BE 500/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");
    }
    if(no <= 0){throw MyException("The number of bank-notes must be positive!");}
    money[value] = money[value] - no;
}

int RepositoryMoney::size() {
    return money.size();
}

void RepositoryMoney::increaseNo(float value, int no) {
    if(money.count(value) == 1){
        money[value] = money[value] + no;
    }
}

RepositoryMoney::~RepositoryMoney() = default;
