//
// Created by Leti on 13.05.2022.
//

#include <fstream>
#include <iostream>
#include <cmath>
#include "RepoInFileMoneyTXT.h"
#include "../Bank_noteValidator/Bank_noteValidator.h"
#include "../MyException.h"

RepoInFileMoneyTXT::RepoInFileMoneyTXT() {
    this->fileName = "";
}

RepoInFileMoneyTXT::RepoInFileMoneyTXT(const std::string &fileName){
    this->fileName = fileName;
    loadFromFile();
}

RepoInFileMoneyTXT::~RepoInFileMoneyTXT() = default;

void RepoInFileMoneyTXT::loadFromFile() {
    std::string line;
    std::ifstream f(this->fileName);
    while (std::getline(f, line)) {
        try {
            Bank_note b(line, ' ');
            Bank_noteValidator bV;
            bV.ValidateBank_note(b);
            RepositoryMoney::addMoney(b);
        }
        catch (MyException &ex) {
            std::cout << "An exception occurred." << "->";
            std::cout << ex.getMessage();
        }
    }
}

void RepoInFileMoneyTXT::saveToFile() {
    std::ofstream f(this->fileName);
    for (auto const &pair: money) {
        Bank_note b(pair.second, pair.first);
        f << b.toStringDelimiter(' ') << std::endl;
    }
    f.close();
}

void RepoInFileMoneyTXT::addMoney(const Bank_note &r) {
    RepositoryMoney::addMoney(r);
    saveToFile();
}

void RepoInFileMoneyTXT::deleteMoney(float value, int no) {
    RepositoryMoney::deleteMoney(value, no);
    saveToFile();
}

std::map<float, int, std::greater<float>> &RepoInFileMoneyTXT::getAll() {
    return RepositoryMoney::getAll();
}

void RepoInFileMoneyTXT::clearFile(const std::string &fileName) {
    std::ofstream ofs;
    ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

void RepoInFileMoneyTXT::increaseNo(float value, int no) {
    RepositoryMoney::increaseNo(value, no);
    saveToFile();
}
