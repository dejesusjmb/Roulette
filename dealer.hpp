#include <deque>

class Dealer
{
public:
    void getBet(uint, uint);
    uint rollRoulette();
    uint giveEarnings();
    std::deque<uint> getRecord();

private:
    bool isNumberInBigBlind();
    bool isNumberEven();
    bool isNumberOdd();
    void calculateEarnings();
    void adjustRecord();
    uint myBetAmount;
    uint myBetCategory;
    uint myEarnings;
    uint myNumber;
    std::deque<uint> myPastNumbers;
};

uint Dealer::giveEarnings()
{
    calculateEarnings();
    return myEarnings;
}

void Dealer::getBet(uint betAmount, uint betCategory)
{
    myBetAmount = betAmount;
    myBetCategory = betCategory;
}

std::deque<uint> Dealer::getRecord()
{
    return myPastNumbers;
}

void Dealer::adjustRecord()
{
    if (myPastNumbers.size() == 8)
    {
        myPastNumbers.pop_back();
    }

    myPastNumbers.push_front(myNumber);
}

uint Dealer::rollRoulette()
{
    srand(time(NULL));
    myNumber = rand() % 36;
    adjustRecord();
    return myNumber;
}

bool Dealer::isNumberInBigBlind()
{
    return myNumber > 18 ? true : false;
}

bool Dealer::isNumberEven()
{
    return myNumber % 2 == 0 && myNumber != 0 ? true : false;
}

bool Dealer::isNumberOdd()
{
    return myNumber % 2 == 1 && myNumber != 0 ? true : false;
}

void Dealer::calculateEarnings()
{
    switch (myBetCategory)
    {
        case 1: myEarnings = !isNumberInBigBlind() ? myBetAmount * 2 : 0;
                break;
        case 2: myEarnings = isNumberInBigBlind() ? myBetAmount * 2 : 0;
                break;
        case 3: myEarnings = isNumberOdd() ? myBetAmount * 2 : 0;
                break;
        case 4: myEarnings = isNumberEven() ? myBetAmount * 2 : 0;
                break;
    }
}