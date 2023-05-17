#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

#include "Point.hpp"
#include "Character.hpp"


namespace ariel{
    class Cowboy : public Character {
        private:
            int num_bullets =6;

        public:
            Cowboy(std::string _name ,Point _p);
            void shoot(Character *enemy);
            bool hasboolets();
            void reload();
            std::string print() override;
            int get_num_bullets();

            ~Cowboy() = default;
    };
   
    
        




}