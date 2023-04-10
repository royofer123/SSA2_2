#include "game.hpp"
#include <algorithm>
#include <iostream>
using namespace std;
namespace ariel{
Game::Game(Player& p1, Player& p2): p1(p1),p2(p2){//Initializes the counters, creates and shuffles the deck, and deals the cards.
    this->draws = 0;
    this->rounds = 0;
    vector<Card> deck;
    deckInit(deck);
    shuffleDeck(deck);
    dealCards(deck,p1,p2);
}

void Game::deckInit(vector<Card>& deck){//Initializes a deck of cards with one card for each rank and suit.
    deck.clear();
    for(int i=1;i<14;i++){
        deck.push_back(Card(i,Heart));
        deck.push_back(Card(i,Diamond));
        deck.push_back(Card(i,Club));
        deck.push_back(Card(i,Spade));
    }

}
void Game::shuffleDeck(vector<Card>& deck){// Shuffles the given deck of cards.
    srand(time(NULL)); 
    random_shuffle(deck.begin(), deck.end());//Algo taken from:https://cplusplus.com/reference/algorithm/random_shuffle/
}
void Game::dealCards(vector<Card>& deck, Player& p1, Player& p2){// Deals the deck of cards between the two players.
    for(size_t i=0;i<26;i++){
        p1.addCard(deck[i]);
        p2.addCard(deck[26+i]);
    }
}
void Game::playTurn(){// Plays a single turn of the game.
    if(&p1==&p2)
    throw "Need two diffrent players in order to play";
    if(p1.stacksize() == 0 || p2.stacksize() == 0)
    throw "Cant play! no more card left";

    string stat="";
    int flag=1;
    int cardsWon=0;
    while(flag){
        this->rounds+=1;
        flag=0;
        Card p1card;
        Card p2card;
        if(this->p1.stacksize() > 0 && this->p2.stacksize()>0){
                p1card = this->p1.playCard();
                p2card = this->p2.playCard();
                cardsWon+=2;
    }
        else{
                if(cardsWon == 0){
                    throw "No more card left to play";
                }
                p1.addRound(cardsWon/2);
                p2.addRound(cardsWon/2);
                break;
            }
            stat += p1.turnStats(p1card) + " " + p2.turnStats(p2card) + ". ";
            if(p1card.getNumber() == p2card.getNumber())
            {
                flag = 1;
                stat += "Draw.";
                this->draws++;
                if(this->p1.stacksize() > 0 && this->p2.stacksize()>0){
                    this->p1.playCard();
                    this->p2.playCard();
                    cardsWon+=2;
                }
                else{
                    p1.addRound(cardsWon/2);
                    p2.addRound(cardsWon/2);
                    flag = 0;
                }
            }
            else if((p1card.getNumber() == 1 && p2card.getNumber() != 2) || (p1card.getNumber() > p2card.getNumber())){
                stat += this->p1.getName() + " wins.";
                p1.addRound(cardsWon);
                p2.addRound(0);
            }
            else
            {
                stat += this->p2.getName() + " wins.";
                p2.addRound(cardsWon);
                p1.addRound(0);
            }   
        }
        stat+="\n";
        this->stats.push_back(stat);
    }   
void Game::playAll(){// Plays the game until one player has no cards left.
    while(this->p1.stacksize()>0&&this->p2.stacksize()>0)
    playTurn();
}
void Game::printLastTurn(){// Prints the statistics of the last turn played.
    cout<<this->stats.back();
    cout<<this->stats.back();
}
void Game::printWiner(){//Prints the winner of the game
     if(p1.cardesTaken() > p2.cardesTaken()){
            cout << p1.getName() + " won" << endl;
        }
        else if(p1.cardesTaken() < p2.cardesTaken()){
            cout << p2.getName() + " won" << endl;
        }
        else cout << "Tie!!! no winner" << endl;
    }

void Game::printLog(){// Prints the log of all turns played.
    for(string stat:this->stats)
    cout<<stat;
}
void Game::printStats(){// Prints the statistics for the whole game
        this->p1.printStats();
        this->p2.printStats();
        double drawRatio = draws;
        drawRatio /= rounds;
        drawRatio*=100;
        cout << "game stats:" << "\n";
        cout << "draw rate:" << drawRatio <<"%\n";
        cout << "draws amount:" << this->draws << "\n";
    }
}










