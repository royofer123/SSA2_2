#ifndef MAIN_CARD_H
#define MAIN_CARD_H

#include <iostream>

using namespace std;
namespace ariel {
    class Card {
        int card_number;//1-13
        string shape;//4 shapes

    public:
        Card(int card_number, string shape);//parameter construcor

        Card();//empty constructor

        ~Card();//destructor

        string toString();

        int getCard_number();

        string getShape();

        int compare(Card other);

    };
}


#endif