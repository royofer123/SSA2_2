#ifndef MAIN_CARD_H
#define MAIN_CARD_H

#include <iostream>

using namespace std;
namespace ariel {};
using namespace ariel;
    class Card {
        int card_number;//1-13
        string shape;//4 shapes
        string color;

    public:
        Card(int card_number, string shape, string color);//parameter construcor

        Card();//empty constructor

        //~Card();//destructor

        string toString();
        int getCard_number();
        string getShape();
        int compare(Card other);
    };
#endif