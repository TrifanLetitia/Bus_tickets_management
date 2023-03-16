//
// Created by Leti on 27.04.2022.
//

#include <fstream>
#include "RepoInFileTXT.h"
#include "../RouteValidator/RouteValidator.h"
#include "../MyException.h"

RepoInFileTXT::RepoInFileTXT() {
    this->fileName = "";
}

RepoInFileTXT::~RepoInFileTXT() {
    //this->Repository::routes.clear();
    //clearFile(fileName);
}

/*
RepoInFileTXT::RepoInFileTXT(const char *fileNameIn, const char *fileNameOut) {
    this->fileNameIn = new char[strlen(fileNameIn) + 1];
    strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
    this->loadFromFile();
}

void RepoInFileTXT::setFileNameIn(const char *fileNameIn) {
    if (this->fileNameIn != NULL)
    {
        delete[]this->fileNameIn;
    }
    this->fileNameIn = new char[strlen(fileNameIn) + 1];
    strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

void RepoInFileTXT::setFileNameOut(const char *fileNameIOut) {
    if (this->fileNameOut != NULL)
    {
        delete[]this->fileNameOut;
    }
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}
*/
void RepoInFileTXT::loadFromFile() {
    /*
    if (!this->fileNameIn.empty()) {
        ifstream f;
        f.open(fileNameIn, std::fstream::in);
        int id;
        string code;
        string day;
        float price;
        while (!f.eof())
        {
            f >> id >> code >> day >> price;
            if (id > 0)
            {
                this->Repository::addRoute(Route(id, code, day, price));
            }
        }
        f.close();
    }
    */
    string line;
    ifstream f(this->fileName);
    while (std::getline(f, line)) {
        try {
            Route r;
            r.loadFromString(line, ' ');
            RouteValidator rV;
            rV.ValidateRoute(r);
            this->routes.push_back(r);
        }
        catch (MyException &ex) {
            std::cout << "An exception occurred." << "->";
            std::cout << ex.getMessage();
        }
    }
    //clearFile(fileNameIn, fileNameOut);
    //f.close();
}

void RepoInFileTXT::saveToFile() {
    /*
    if (!this->fileNameOut.empty()) {
        ofstream f(this->fileNameOut);
        f.open(fileNameOut);
        for (auto &route: this->Repository::routes) {
            f << route << endl;
        }
        f.close();
    }
     */
    ofstream f(this->fileName);
    for (Route route: this->routes) {
        f << route.toStringDelimiter(' ') << endl;
    }
    f.close();
}

void RepoInFileTXT::addRoute(const Route &r) {
    Repository::addRoute(r);
    saveToFile();
}

void RepoInFileTXT::deleteRoute(const Route &r) {
    Repository::deleteRoute(r);
    saveToFile();
}

void RepoInFileTXT::UpdateRoute(int id, const Route &r) {
    Repository::updateRoute(id, r);
    saveToFile();
}

Route& RepoInFileTXT::getRoute(int id) {
    return Repository::getRoute(id);
}

RepoInFileTXT::RepoInFileTXT(const string &fileName) {
    this->fileName = fileName;
    loadFromFile();
}

vector<Route> RepoInFileTXT::getAll() {
    return Repository::getAll();
}

void RepoInFileTXT::clearFile(const string &fileName) {
    std::ofstream ofs;
    ofs.open(fileName, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

