//
// Created by Leti on 07.05.2022.
//

#include <string>

#ifndef BUS_TICKETS_MANAGEMENT_MYEXCEPTION_H
#define BUS_TICKETS_MANAGEMENT_MYEXCEPTION_H

#endif //BUS_TICKETS_MANAGEMENT_MYEXCEPTION_H

class MyException {
protected:
    const char* message;
public:
    explicit MyException(const char* m) : message(m) {
    }
    const char* getMessage() {
        return message;
    }
};