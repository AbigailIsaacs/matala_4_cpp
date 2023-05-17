#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "YountNinja.hpp"
using namespace std ;
namespace ariel{
    YountNinja::YountNinja(std::string _name ,Point _point) : Ninja(_name ,_point,100,14){}
    int YountNinja::get_speed(){
        return 0;
    }
}