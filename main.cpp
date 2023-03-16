#include <cmath>
#include "UI/UI.h"
#include "Tests/RepoTests/RepoTests.h"
#include "Tests/ServiceTests/ServiceTests.h"
#include "Tests/RouteTests/RouteTests.h"
#include "Repository/RepositoryMoney.h"
#include "Repository/RepoInFileMoneyTXT.h"
#include "Tests/ServiceTests/MoneyServiceTests.h"


int main() {
    testAddMoney();
    RunAllServiceTests();
    RunAllRepoTests();
    testRoute();
    RouteValidator r2;
    Bank_noteValidator bV;
    RepoInFileTXT R(R"(C:\Users\Leti\OneDrive\Documente\Bus_tickets_management\TicketsIn.txt)");
    RepoInFileMoneyTXT RM(R"(C:\Users\Leti\OneDrive\Documente\Bus_tickets_management\Money.txt)");
    MoneyService MS(RM, bV);
    Bank_note b(20, 100);
    Service s(R, r2);
    UI ui(s, MS);
    ui.RunMenu();
}
