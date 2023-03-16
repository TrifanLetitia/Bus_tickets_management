//
// Created by Leti on 06.05.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_BANK_NOTE_H
#define BUS_TICKETS_MANAGEMENT_BANK_NOTE_H
#include <iostream>
using namespace std;

class Bank_note {
private:
    int no;
    float value;
public:
    Bank_note();
    ~Bank_note();
    Bank_note(int n, float v);
    Bank_note(const Bank_note &b);
    int getNo() const;
    void setNo(int n);
    float getValue() const;
    void setValue(float v);
    Bank_note &operator=(const Bank_note &b);
    bool operator==(const Bank_note &b) const;
    friend std::ostream &operator<<(ostream &os, const Bank_note &b);
    void loadFromString(const std::string& args, char sep);
    std::string toStringDelimiter(char sep);
    Bank_note(std::string args, char sep);
};


#endif //BUS_TICKETS_MANAGEMENT_BANK_NOTE_H
