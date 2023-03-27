#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;
namespace ariel {};
using namespace ariel;

class Player {
private:     
     
public:
        string name;
        
        Player(){};//empty constructor
        
        Player(string name);//paramater constructor

        ~Player();//destructor

        void setName(string);

        string getName();


        int stacksize(); 
        int cardesTaken(); 
        

        string toString();
        

};

#endif