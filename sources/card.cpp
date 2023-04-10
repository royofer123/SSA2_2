#include "card.hpp"
#include <string>
using namespace std;
namespace ariel{
    Card::Card(){//Empty constructor
    this->number=0;
    this->suit=Club;
    }

    Card::Card(int number, Suit suit){//Parameter constructor
        this->number=number;
        this->suit=suit;
    }

    string Card::getSuitType(){//Determine the type of card
        
            if (this->suit==Heart) return "Hearts";
            else if (this->suit==Spade) return "Spades";
            else if (this->suit==Club) return "Clubs";
            else return "Diamonds";
       }
    string Card::getFaceCard(){//Return the face of the card, if it is not a special card then its value
        if(this->number==1) return "ace";
        else if(this->number==11) return "Prince";
        else if(this->number==12) return "Queen";
        else if(this->number==13) return "King";
        return to_string(this->number);
    }
    int Card::getNumber(){
        return this->number;
    }
    string Card::toString(){//Prints the card and its type
        return getFaceCard()+ " of "+ getSuitType();
    }

    }
    