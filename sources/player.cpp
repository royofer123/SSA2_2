#include <iostream>
#include "player.hpp"

using namespace std;


Player :: Player (string name){
    this -> name = name;
}

int Player :: stacksize(){
    return 26;
}

int Player :: cardesTaken(){
    return 0;
    
}