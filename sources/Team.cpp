#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Team.hpp"
using namespace std ;

namespace ariel{
            
    Team::Team(Character* newcaracter):leader(newcaracter){
    }
    void Team::add(Character* newcaracter){}
    void Team::attack(Team *Team_b){}
    int Team::stillAlive(){
        return 0;
    }
    void Team::print(){}

    Character* Team::get_leader(){
        Cowboy *tom = new Cowboy("Tom", Point(1,1));
        return tom;
    }

}
