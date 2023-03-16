//
// Created by Leti on 27.04.2022.
//

#include <fstream>
#include "RepoInFileCSV.h"
#include "../MyException.h"

RepoInFileCSV::RepoInFileCSV(const string& filename) {
    this->loadFromFile();
}

void RepoInFileCSV::saveToFile() {
    ofstream f(this->fileNameOut);
    for (Route route : this->routes) {
        f << route.toStringDelimiter(',') << endl;
    }
    f.close();
}

void RepoInFileCSV::loadFromFile() {
    string line;
    ifstream f(this->fileNameIn);
    while (std::getline(f, line)) {
        try{
            Route r;
            r.loadFromString(line, ',');
            this->routes.push_back(r);
        }
        catch(MyException ex){
            cout << "some pb: " << ex.getMessage() << endl;
            throw ex;
        }
    }
}

RepoInFileCSV::~RepoInFileCSV() = default;
