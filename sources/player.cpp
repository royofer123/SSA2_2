#include "player.hpp"
#include "card.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace ariel{
    Player::Player(string name){ //Constructor for the Player class, Initializes a player with a given name and initializes their statistics to 0
        this->name=name;
        this->stack.clear();
        this->numOfWins=0;
        this->numOfRounds=0;
        this->numOfCardTaken=0;
    }
    Card Player::playCard(){// Removes and returns the top card from the player's stack
        Card card = stack.back();
        stack.pop_back();
        return card;

    }
    int Player::stacksize(){// Returns the size of the player's stack
        return stack.size();
    }
    int Player::cardesTaken(){// Returns the number of cards the player has taken in total
        return this->numOfCardTaken;
        }
    void Player::addRound(int cardsWon){// Updates the player's statistics after a round is won or lost
        this->numOfRounds+=1;
        if(cardsWon>0){
            this->numOfCardTaken+=cardsWon;
            this->numOfWins+=1;
        }
    }
    void Player::addCard(Card card){ // Adds a card to the player's stack
        this->stack.push_back(card);
    }
    string Player::getName(){// Returns the player's name
        return this->name;
    }
    string Player::turnStats(Card card){ // Returns a string containing the player's name and the card they played in their turn
        return this->name + " played " + card.toString();
    }
    void Player::printStats(){// Prints out the player's statistics
        cout<< "~~~~~~~~~~~~~~~~~~~~" << "\n";
        cout << this->name << " statistics:" << "\n";
        cout << "Number of cards taken: "<< this->numOfCardTaken << "\n";
        cout << "Number of rounds win: "<< this->numOfWins << "\n";
        cout << "Number of rounds played :"<< this->numOfRounds << "\n";
        double winRatio = this->numOfWins;
        winRatio /= this->numOfRounds;
        winRatio*=100;
        cout<< "Win rate: " << winRatio << "%\n";
        cout << "Cards won: " << this->numOfCardTaken <<"\n";
        cout<< "~~~~~~~~~~~~~~~~~~~~" << "\n";
    }
    }    
    


