//
// Created by Leti on 27.04.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_REPOINFILETXT_H
#define BUS_TICKETS_MANAGEMENT_REPOINFILETXT_H


#include "Repository.h"

class RepoInFileTXT: public Repository{
protected:
    string fileName;
public:
    RepoInFileTXT();
    RepoInFileTXT(const string& fileName);
    ~RepoInFileTXT();
    void loadFromFile();
    void saveToFile();
    void addRoute(const Route& r) override;
    void deleteRoute(const Route& r) override;
    void UpdateRoute(int id, const Route& r);
    Route& getRoute(int id) override;
    vector<Route> getAll() override;
    void clearFile(const string& fileName);
};


#endif //BUS_TICKETS_MANAGEMENT_REPOINFILETXT_H
