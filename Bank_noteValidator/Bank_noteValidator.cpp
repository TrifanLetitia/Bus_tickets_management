//
// Created by Leti on 07.05.2022.
//

#include <vector>
#include "Bank_noteValidator.h"
#include "../MyException.h"

Bank_noteValidator::Bank_noteValidator() {

}

Bank_noteValidator::~Bank_noteValidator() {

}

void Bank_noteValidator::ValidateBank_note(Bank_note &b) {
    vector<float> values;
    values.push_back(500);
    values.push_back(200);
    values.push_back(100),
    values.push_back(50);
    values.push_back(20);
    values.push_back(10);
    values.push_back(5);
    values.push_back(1);
    values.push_back(0.5);
    values.push_back(0.1);
    values.push_back(0.05);
    values.push_back(0.01);
    int nr = 0;
    for(float value : values){
        if(abs(b.getValue() - value) < 1e-9){
            nr++;
           // throw MyException("BANKNOTES CAN ONLY BE 500/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");
        }
    }
    if(nr == 0){throw MyException("BANKNOTES CAN ONLY BE 500/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");}
    /*
    if((abs(b.getValue() - 500) >= 1e-9) and (abs(b.getValue() - 200) >= 1e-9) and (abs(b.getValue() - 100) >= 1e-9) and
    (abs(b.getValue() - 50) >= 1e-9) and  (abs(b.getValue() - 20) >= 1e-9) and  (abs(b.getValue() - 10) >= 1e-9) and
    (abs(b.getValue() - 5) >= 1e-9) and  (abs(b.getValue() - 1) >= 1e-9) and  (abs(b.getValue() - 0.5) >= 1e-9) and
    (abs(b.getValue() - 0.1) >= 1e-9) and  (abs(b.getValue() - 0.01) >= 1e-9) and  (abs(b.getValue() - 0.05) >= 1e-9)){
        throw MyException("BANKNOTES CAN ONLY BE 500/100/50/20/10/5/1/0.5/0.1/0.05/0.01!");
    }
     */
}
