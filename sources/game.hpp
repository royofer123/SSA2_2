#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "card.hpp"
using namespace std;

namespace ariel{
    class Game{
        private:
        Player& p1;
        Player& p2;
        int rounds;
        int draws;
        vector<string> stats;
       
        public:
        Game(Player& _p1, Player& _p2);
        void deckInit(vector<Card>& deck);
        void shuffleDeck(vector<Card>& deck);
        void dealCards(vector<Card>& deck, Player& _p1, Player& _p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
};
#endif