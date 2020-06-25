#include "economy.hpp"

void Economy::showBalance()
{
    cout << "Balance: ";
    balance>0? textColor(LIGHT_GREEN): textColor(LIGHT_RED) ;
    cout << balance << "$     ";
    textColorRestore();
}
