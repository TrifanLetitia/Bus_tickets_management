//
// Created by Leti on 07.05.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_BANK_NOTEVALIDATOR_H
#define BUS_TICKETS_MANAGEMENT_BANK_NOTEVALIDATOR_H


#include "../Bank_note/Bank_note.h"

class Bank_noteValidator {
public:
    Bank_noteValidator();
    ~Bank_noteValidator();
    static void ValidateBank_note(Bank_note &b);
};


#endif //BUS_TICKETS_MANAGEMENT_BANK_NOTEVALIDATOR_H
