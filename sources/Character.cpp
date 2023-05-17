#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Character.hpp"

using namespace std ;
namespace ariel{

    Character::Character (std::string _name, Point _point, int _hit_points):name(_name) , point(_point), hit_points(_hit_points){
    }
    bool Character::isAlive(){
        return true;
    }
    double Character::distance (Character &outher){
        return 0;
    }
    void hit (int num_points){}

    std::string Character::getName(){
        return "";
    }
    Point Character::getLocation(){
        Point p (1,1);
        return p;
    }
    int Character::get_hit_points(){
        return 0;
    }

}