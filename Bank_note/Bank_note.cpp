//
// Created by Leti on 06.05.2022.
//

#include <sstream>
#include <cmath>
#include "Bank_note.h"
#include "../MyException.h"
#include "../utils.h"

Bank_note::Bank_note() {
    this->no = 0;
    this->value = 0;
}

Bank_note::~Bank_note() {
    this->no = 0;
    this->value = 0;
}

Bank_note::Bank_note(int n, float v) {
    this->no = n;
    this->value = v;
}

Bank_note::Bank_note(const Bank_note &b) {
    this->no = b.no;
    this->value = b.value;
}

int Bank_note::getNo() const {
    return this->no;
}

void Bank_note::setNo(int n) {
    this->no = n;
}

float Bank_note::getValue() const {
    return this->value;
}

void Bank_note::setValue(float v) {
    this->value = v;
}

Bank_note &Bank_note::operator=(const Bank_note &b) {
    if (this != &b) {
        this->setNo(b.no);
        this->setValue(b.value);
    }
    return *this;
}

bool Bank_note::operator==(const Bank_note &b) const {
    return (this->no == b.no) && ( abs(this->value - (b.value)) < 1e-9);//this->value == b.value);
}

std::ostream &operator<<(std::ostream &os, const Bank_note &b) {
    os << "No: " << b.no <<" Value: " << b.value;
    return os;
}

void Bank_note::loadFromString(const string &args, char sep) {
    vector<string> elements = split(args, sep);
    if (elements.size() == 2){
        stringstream i(elements[0]);
        i >> this->no;
        this->value = std::stof(elements[1]);
    }
    else{
        throw MyException("Nr. invalid de argumente in stringul ce trebuie parsat");
    }
}

string Bank_note::toStringDelimiter(char sep) {
    return std::to_string(this->no) + sep + std::to_string(this->value);
}

Bank_note::Bank_note(std::string args, char sep) {
    this->loadFromString(args, sep);
}


