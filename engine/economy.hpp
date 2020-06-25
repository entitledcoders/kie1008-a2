#ifndef ECONOMY_HPP
#define ECONOMY_HPP

#include "iomanager.hpp"

class Economy
{
    public:

        void load(int m_temp) { balance = m_temp; }

        void showBalance();
        void deductBalance(int cost) { balance-=cost; }
        void addBalance(int profit) { balance+=profit; }

        int balance;
};

#endif // ECONOMY_HPP
