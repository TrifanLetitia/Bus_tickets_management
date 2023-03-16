//
// Created by Leti on 16.04.2022.
//

#ifndef LAB9_ROUTE_H
#define LAB9_ROUTE_H
#include <iostream>
using namespace std;

class Route {
private:
    int id;
    string code;
    string day;
    float price;
public:
    Route();

    Route(int id1, const string& c, const string& d, float p);

    ~Route();

    Route(const Route &p);

    void setId(int id);

    void setCode(const string& c);

    void setDay(const string& d);

    void setPrice(float p);

    string getCode() const;

    string getDay() const;

    float getPrice() const;

    int getId() const;

    Route &operator=(const Route &p);

    bool operator==(const Route &p);

    bool operator<(const Route &p) const;

    bool operator<=(const Route &p);

    bool operator>(const Route &p);

    bool operator>=(const Route &p);

    friend std::ostream &operator<<(std::ostream &os, Route p);

    void loadFromString(const string& args, char sep);

    string toStringDelimiter(char sep);
};


#endif //BUS_TICKETS_MANAGEMENT_ROUTE_H
