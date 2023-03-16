//
// Created by Leti on 06.05.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_REPOSITORYMONEY_H
#define BUS_TICKETS_MANAGEMENT_REPOSITORYMONEY_H


#include <map>
#include "../Bank_note/Bank_note.h"

class RepositoryMoney {
protected:
    std::map<float, int, std::greater<float>> money;
public:
    /// constructor
    RepositoryMoney();

    explicit RepositoryMoney(const std::map<float, int, std::greater<float>> &money);

    /// destructor
    ~RepositoryMoney();

    /// Adds a ticket to the repo
    virtual void addMoney(const Bank_note& r);
    void increaseNo(float value, int no);
    virtual /// return the tickets
    std::map<float, int, std::greater<float>>& getAll();

    virtual void deleteMoney(float value, int no);
    int size();
};


#endif //BUS_TICKETS_MANAGEMENT_REPOSITORYMONEY_H
