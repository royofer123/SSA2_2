#ifndef CARD_HPP
#define CARD_HPP

#include <string>

using namespace std;
namespace ariel{

enum Suit {Heart=1, Diamond, Spade, Club};

class Card{
    private:
    int number;
    Suit suit;
    string getSuitType();
    string getFaceCard();

    public:
    Card();
    Card(int number, Suit suit);
    string toString();
    int getNumber();

};
};
#endif
