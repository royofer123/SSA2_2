#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <vector>
#include "card.hpp"

using namespace std;
namespace ariel{
    class Player{
        private:
         string name;
         vector<Card> stack;
         int numOfWins;
         int numOfCardTaken;
         int numOfRounds;
        
        public:
        Player(string name);
        Card playCard();
        int stacksize();
        int cardesTaken();
        void addRound(int cardsWon);
        void addCard(Card card);
        void printStats();
        string getName();
        string turnStats(Card card);
    };
};
#endif 