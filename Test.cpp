#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("Game initialization") {//Checking the first initialization #1
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game game(p1, p2));//checking no errors while starting the game
}
TEST_CASE("Stack initialization") {//Checking the stacks split equally #2
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK(p1.stacksize() == 26);//checking first player stack size 26
    CHECK(p2.stacksize() == 26);//checking second player stack size 26
    CHECK(p1.cardesTaken() == 0);//checking first player cards taken size 0
    CHECK(p2.cardesTaken() == 0);//checking second player cards taken size 0
}

TEST_CASE("No error while winning") {//Checking if the the winner is printing without any errors #3
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK_NOTHROW(game.playAll());//start the game untill they finish
    CHECK_NOTHROW(game.printWiner());//checking the winner is printing
}
TEST_CASE("Checking the middle of the Game"){//checking for 9 rounds no errors #4
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i = 0; i < 9; i++) {
        CHECK_NOTHROW(game.playTurn());
    }
}

TEST_CASE("Checking the functions work propely"){//Checking all the functions provided by Demo #5
Player p1("Alice");
Player p2("Bob");
Game game(p1,p2);
CHECK_NOTHROW(game.printWiner());// prints the name of the winning player
CHECK_NOTHROW(game.printStats());// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
CHECK_NOTHROW(game.printLog());// prints all the turns played one line per turn (same format as game.printLastTurn())
CHECK_NOTHROW(game.printLastTurn());//prints last turn
}




