#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <vector>

#include "Cowboy.hpp"
#include "Point.hpp"
#include "OldNinja.hpp"
#include "YountNinja.hpp"
#include "TrainedNinja.hpp"


namespace ariel{
    class Team{
        private:
            std::vector<Character> characters();
            Character* leader;
        public:
            Team(Character* newcaracter);
            void add(Character* newcaracter);
            void attack(Team *Team_b);
            int stillAlive();
            virtual void print();
            Character* get_leader();

            ~Team() = default;

            
            
    };
   
    
        




}