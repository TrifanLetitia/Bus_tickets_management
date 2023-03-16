//
// Created by Leti on 14.05.2022.
//

#include <vector>
#include <sstream>
#include "utils.h"
using namespace std;


vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}
