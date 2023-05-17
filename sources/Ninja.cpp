#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include "Ninja.hpp"
using namespace std ;
namespace ariel{
    Ninja::Ninja(std::string _name ,Point _point, int _speed,int _hit_points) : Character(_name ,_point,_hit_points), speed(_speed){}
    
    void Ninja::move(Character* enemy){}
    void Ninja::slash(Character* enemy){}
    std::string Ninja::print(){
        return "";
    }
    

}