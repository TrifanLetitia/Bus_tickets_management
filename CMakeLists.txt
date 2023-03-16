cmake_minimum_required(VERSION 3.21)
project(Bus_tickets_management)

set(CMAKE_CXX_STANDARD 11)

add_executable(Bus_tickets_management main.cpp Route/Route.cpp Route/Route.h Repository/Repository.cpp Repository/Repository.h Tests/RouteTests/RouteTests.cpp Tests/RouteTests/RouteTests.h Tests/RepoTests/RepoTests.cpp Tests/RepoTests/RepoTests.h Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Tests/ServiceTests/ServiceTests.cpp Tests/ServiceTests/ServiceTests.h Repository/RepoInFileTXT.cpp Repository/RepoInFileTXT.h utils.h Repository/RepoInFileCSV.cpp Repository/RepoInFileCSV.h Bank_note/Bank_note.cpp Bank_note/Bank_note.h Repository/RepositoryMoney.cpp Repository/RepositoryMoney.h MyException.h RouteValidator/RouteValidator.cpp RouteValidator/RouteValidator.h Bank_noteValidator/Bank_noteValidator.cpp Bank_noteValidator/Bank_noteValidator.h Repository/RepoInFileMoneyTXT.h Repository/RepoInFileMoneyTXT.cpp utils.cpp Service/MoneyService.cpp Service/Service.h Tests/ServiceTests/MoneyServiceTests.cpp Tests/ServiceTests/MoneyServiceTests.h)
