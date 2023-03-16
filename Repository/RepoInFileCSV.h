//
// Created by Leti on 27.04.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_REPOINFILECSV_H
#define BUS_TICKETS_MANAGEMENT_REPOINFILECSV_H


#include "Repository.h"

class RepoInFileCSV: public Repository{
private:
    string fileNameIn;
    string fileNameOut;
public:
    RepoInFileCSV(const string&);
    void saveToFile();
    void loadFromFile();
    ~RepoInFileCSV();
};


#endif //BUS_TICKETS_MANAGEMENT_REPOINFILECSV_H
