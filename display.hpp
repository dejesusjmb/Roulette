#include <iostream>
#include <stdlib.h>

class Display
{
public:
    void printTable();
    void printGameDetails(Dealer*, User*);
};

void Display::printTable()
{
    system("clear");
    std::cout << "                        ROULETTE" << std::endl;
    for(int num : {3, 2, 1})
    {
        std::cout << " ----------------------------------------------------------" << std::endl;
        std::cout << " | ";
        for (int column = 0; column < 12; ++column, num+=3)
        {
            std::cout << num << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << " ----------------------------------------------------------" << std::endl << std::endl;
    std::cout << " BET CATEGORIES: [1] 1-18    [2] 19-36   [3] ODD   [4] EVEN" << std::endl;
}

void Display::printGameDetails(Dealer* dealer, User* user)
{
    std::cout << " BALANCE: " << user->getBalance()
            << "   NUMBER: " << *(dealer->getRecord().begin())
            << "   HISTORY: ";

    for (const uint x : dealer->getRecord())
    {
        std::cout << x << " " ;
    }
    std::cout << std::endl;
    

    //foreach
}