//
// Created by Leti on 16.04.2022.
//

#include <vector>
#include <sstream>
#include "Route.h"
#include "../utils.h"
#include "../MyException.h"

Route::Route() {
    this->id = 0;
    this->code = "";
    this->day = "";
    this->price = 0;
}

Route::Route(int id1, const string& c, const string& n, float p) {
    this->id = id1;
    this->code = c;
    this->day = n;
    this->price = p;
}

Route::~Route() {
    this-> id = 0;
    this->code = "";
    this->day = "";
    this->price = 0;
}

Route::Route(const Route &p) {
    this-> id = p.id;
    this->code = p.code;
    this->day = p.day;
    this->price = p.price;
}

void Route::setCode(const string& c) {
    this->code = c;
}

void Route::setDay(const string& d) {
    this->day = d;
}

void Route::setPrice(float p) {
    this->price = p;
}

string Route::getCode() const {
    return this->code;
}

string Route::getDay() const {
    return this->day;
}

float Route::getPrice() const {
    return this->price;
}

Route &Route::operator=(const Route &r) {
    if (this != &r) {
        this->setId(r.id);
        this->setCode(r.code);
        this->setDay(r.day);
        this->setPrice(r.price);
    }
    return *this;
}

bool Route::operator==(const Route &r) {
    return (this->id == r.id) && (this->code == r.code) && (this->day == r.day) && (abs(this->price - r.price) < 1e-9);
}

bool Route::operator<(const Route &r) const {
    return (this->code == r.code) && (this->price < r.price);
}

bool Route::operator<=(const Route &r) {
    return (this->code == r.code) && (this->price <= r.price);
}

bool Route::operator>(const Route &r) {
    return (this->code == r.code) && (this->price > r.price);
}

bool Route::operator>=(const Route &r) {
    return (this->code == r.code) && (this->price >= r.price);
}

std::ostream &operator<<(ostream &os, Route r) {
    os <<"Id: "<<r.id<< " Code: " << r.code << " Day: " << r.day << " Price: " << r.price;
    return os;
}

void Route::setId(int id1) {
    this->id = id1;
}

int Route::getId() const {
    return this->id;
}

void Route::loadFromString(const string& args, char sep) {
    vector<string> elements = split(args, sep);
    if (elements.size() == 4){
        stringstream i (elements[0]);
        i >> this->id;
        this->code = elements[1];
        this->day = elements[2];
        this->price = std::stof(elements[3]);
    }
    else{
        throw MyException("Nr. invalid de argumente in stringul ce trebuie parsat");
    }
}

string Route::toStringDelimiter(char sep) {
    return to_string(this->id) + sep + (this->code) + sep + (this->day) + sep + to_string(this->price);
}




