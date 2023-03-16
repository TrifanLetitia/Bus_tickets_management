//
// Created by Leti on 13.05.2022.
//

#ifndef BUS_TICKETS_MANAGEMENT_REPOINFILEMONEYTXT_H
#define BUS_TICKETS_MANAGEMENT_REPOINFILEMONEYTXT_H

#include "RepositoryMoney.h"

class RepoInFileMoneyTXT: public RepositoryMoney{
        protected:
        std::string fileName;
        public:
        RepoInFileMoneyTXT();
        explicit RepoInFileMoneyTXT(const std::string &fileName);
        ~RepoInFileMoneyTXT();
        void loadFromFile();
        void saveToFile();
        void addMoney(const Bank_note& r) override ;
        void deleteMoney(float value, int no) ;
        std::map<float, int, std::greater<float>>& getAll() override;
        void increaseNo(float value, int no);
        void clearFile(const std::string& fileName);
};


#endif //BUS_TICKETS_MANAGEMENT_REPOINFILEMONEYTXT_H
