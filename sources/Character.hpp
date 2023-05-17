#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string>

#include "Point.hpp"



namespace ariel{
    class Character {
        private:
            Point point;
            int hit_points;
            std::string name;

    
        public:
            Character ( std::string _name, Point _point, int _hit_points);
            bool isAlive();
            double distance (Character &outher);
            void hit (int num_points);
            std::string getName();
            Point getLocation();
            int get_hit_points();
            virtual std::string print() =0;

            ~Character() = default;



    };
}