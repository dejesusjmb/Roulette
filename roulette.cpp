#include <iostream>
#include <stdlib.h>
#include <user.hpp>
#include <display.hpp>

int main()
{
    User* user = new User();
    user->setInitialBalance();
    Dealer* dealer = new Dealer();
    Display display;
    
    while (user->getBalance() > 0)
    {
        display.printTable();
        display.printGameDetails(dealer, user);
        user->play(dealer);
    }

    display.printTable();
    display.printGameDetails(dealer, user);
    delete dealer;
    delete user;
}