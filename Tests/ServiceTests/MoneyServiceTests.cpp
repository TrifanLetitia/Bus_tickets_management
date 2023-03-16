//
// Created by Leti on 17.05.2022.
//

#include <cassert>
#include "MoneyServiceTests.h"
#include "../../Service/MoneyService.h"
RepoInFileMoneyTXT M(R"(C:\Users\Leti\OneDrive\Documente\Bus_tickets_management\MoneyTests.txt)");
Bank_noteValidator V;
MoneyService MS(M, V);
void testAddMoney(){
    Bank_note b(20, 100);
    Bank_note b1(50, 50);
    Bank_note b2(10, 200);
    MS.addMoney(b);
    MS.addMoney(b1);
    MS.addMoney(b2);
    assert(MS.getSize() == 3);
    MS.deleteMoney(100, 20);
    assert(MS.getAll()[100] == 0);
}