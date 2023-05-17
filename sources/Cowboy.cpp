#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Cowboy.hpp"


using namespace std ;

namespace ariel{
    Cowboy::Cowboy(std::string _name ,Point _point) : Character(_name ,_point,110){

    }
    void Cowboy::shoot(Character *enemy){}
    bool Cowboy::hasboolets(){
        return true;
    }
    void Cowboy::reload(){}
    std::string Cowboy::print(){
        return "";
    }
    int Cowboy::get_num_bullets(){
        return 0;
    }

}