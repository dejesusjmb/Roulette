#include <string>
#include <algorithm>
#include <dealer.hpp>

class User
{
public:
    uint getBalance();
    void setInitialBalance();
    void play(Dealer*);

private:
    void placeBet();
    bool isInputNumeric(std::string);
    bool isValidCategory(std::string);
    bool isValidBet(std::string);
    uint myBalance;
    uint myBetAmount;
    uint myBetCategory;
};

uint User::getBalance()
{
    return myBalance;
}

void User::setInitialBalance()
{
    std::string balance;

    do
    {
        std::cout << "INITIAL BALANCE: ";
        std::getline(std::cin, balance);
    } while (!isInputNumeric(balance) || atoi(balance.c_str()) == 0);

    myBalance = atoi(balance.c_str());
}

bool User::isInputNumeric(std::string input)
{
    for (int i=0; i < input.size(); ++i)
    {
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

bool User::isValidBet(std::string input)
{
    int bet = atoi(input.c_str());
    return bet != 0 && myBalance >= bet;
}

bool User::isValidCategory(std::string input)
{
    int category = atoi(input.c_str());
    return category > 0 && category < 5;
}

void User::placeBet()
{
    std::string amount, category;

    do
    {
        std::cout << " BET: ";
        std::getline(std::cin, amount);
        if (amount == "x")
            exit(0);
    } while (!isInputNumeric(amount) || !isValidBet(amount));

    do
    {
        std::cout << " CATEGORY: ";
        std::getline(std::cin, category);
    } while (!isInputNumeric(category) || !isValidCategory(category));

    myBetAmount = atoi(amount.c_str());
    myBetCategory = atoi(category.c_str());
    myBalance -= myBetAmount;
}

void User::play(Dealer* dealer)
{
    placeBet();
    dealer->getBet(myBetAmount, myBetCategory);
    int num = dealer->rollRoulette();
    myBalance += dealer->giveEarnings();
}