#include "doctest.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Point constructor") {
    CHECK_NOTHROW( Point a(1.9876543, 2));
    CHECK_NOTHROW( Point b(-100, -56));
    Point a(1.9876543, 2);
    Point b(-100, -56);
    CHECK_EQ(a.get_x(),1.987654);
    CHECK_EQ(a.get_y(),2); 
    CHECK_EQ(b.get_x(),-100);
    CHECK_EQ(b.get_y(),-56);     
}

TEST_CASE("Point distance") {
    Point a(1, 2);
    Point b(4, 6);
    Point c(8, 7);

    CHECK(a.distance(b)== 5);
    CHECK(a.distance(c)== 8.602325);
    CHECK(a.distance(c)== c.distance(a));
    CHECK(b.distance(c)== 4.123105);
    
}

TEST_CASE("Point moveTowards") {
    Point a(1, 2);
    Point b(4, 6);
    Point c(0, 0);
    Point d(0, 7);
    Point e(1, 1);
    Point f(4, 1);

    
    CHECK_THROWS(Point::moveTowards(a,b,-1));
    Point p1 = Point::moveTowards(a,b,0);
    CHECK_EQ(p1,a);

    Point p2 = Point::moveTowards(a,b,5);
    CHECK_EQ(p2,b);

    Point p3 = Point::moveTowards(a,b,8);
    CHECK_EQ(p3,b);

    Point p4 = Point::moveTowards(c,d,5);
    CHECK_EQ(p4,Point(0,5));

    Point p5 = Point::moveTowards(e,f,2);
    CHECK_EQ(p5,Point(3,1));  
}

TEST_CASE("Ninja simple functions") {

    //___________YountNinja___________
    YountNinja shamla ("Yuval", Point(64,57));
    YountNinja *abi1 = new YountNinja ("abi", Point(0,0));
    Point p1= shamla.getLocation();
    CHECK_EQ(shamla.get_hit_points(),100);
    CHECK_EQ(shamla.get_speed(),14);
    CHECK_EQ(p1,Point(64,57));
    CHECK_EQ(shamla.getName(),"Yuval");
    CHECK_EQ(shamla.isAlive(),true);    

    //___________TrainedNinja___________
    TrainedNinja shamla2 ("Yuval", Point(2,3));
    TrainedNinja *abi2 = new TrainedNinja ("abi", Point(8,7));
    Point p2= shamla2.getLocation();
    CHECK_EQ(shamla2.get_hit_points(),120);
    CHECK_EQ(shamla2.get_speed(),12);
    CHECK_EQ(p2,Point(2,3));
    CHECK_EQ(shamla2.getName(),"Yuval");
    CHECK_EQ(shamla2.isAlive(),true);    

    //___________OldNinja___________
    OldNinja shamla3 ("Yuval", Point(20,-12));
    OldNinja *abi3 = new OldNinja ("abi", Point(0,0));
    Point p3= shamla3.getLocation();
    CHECK_EQ(shamla3.get_hit_points(),150);
    CHECK_EQ(shamla3.get_speed(),8);
    CHECK_EQ(p3,Point(20,-12));
    CHECK_EQ(shamla3.getName(),"Yuval");
    CHECK_EQ(shamla3.isAlive(),true);    
}

TEST_CASE("move() - the Ninja moves the distace that equals to his speed") {

    //___________YountNinja___________
    YountNinja shamla1 ("Yuval", Point(64,57));
    YountNinja *abi1 = new YountNinja ("abi", Point(0,0));
    Point p1= shamla1.getLocation();
    shamla1.move(abi1);
    Point p_after_move1 = shamla1.getLocation();
    CHECK_EQ(p_after_move1.distance(p1),14);

    //___________TrainedNinja___________
    TrainedNinja shamla2 ("Yuval", Point(64,57));
    TrainedNinja *abi2 = new TrainedNinja ("abi", Point(0,0));
    Point p2= shamla2.getLocation();
    shamla2.move(abi2);
    Point p_after_move2 = shamla2.getLocation();
    CHECK_EQ(p_after_move2.distance(p2),12);

    //___________OldNinja___________
    OldNinja shamla3 ("Yuval", Point(64,57));
    OldNinja *abi3 = new OldNinja ("abi", Point(0,0));
    Point p3= shamla3.getLocation();
    shamla3.move(abi3);
    Point p_after_move3 = shamla3.getLocation();
    CHECK_EQ(p_after_move3.distance(p3),8);
}

TEST_CASE("Ninja - slash()") { 

    // if the distance is less then a meter then -40 points
    Point a(1, 2);
    Point b(4, 6);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *jery = new OldNinja("sushi", b);
    jery->slash(tom);
    CHECK_EQ(110,(tom->get_hit_points()+40));

    // if the distance is more then meter no change of the points
    Point c(150,150);
    Cowboy *abi = new Cowboy("Tom", a);
    jery->slash(abi);
    CHECK_EQ(110,tom->get_hit_points());

    // if the enemy is dead throw error
    jery->slash(tom); //30
    jery->slash(tom); //tom is dead
    CHECK_THROWS(jery->slash(tom));
}

TEST_CASE("Cowboy - simple functions") { 
    Point a(-1.5, 2);
    Point c(150,150);
    Cowboy *tom = new Cowboy("Tom", a);
    CHECK_EQ(tom->get_num_bullets(),6);
    CHECK_EQ(tom->get_hit_points(),110);
    CHECK_EQ(tom->hasboolets(),true); 
}


TEST_CASE("Cowboy - reload() and shoot()") { 
    Point a(-1.5, 2);
    Point c(150,150);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *jery = new Cowboy("jery", c);

    CHECK_THROWS(tom->reload());//tom still has bullets
    for (int i=0;i<6;i++){
        tom->shoot(jery);//5 , -10
    }      
    CHECK_THROWS(tom->shoot(jery));//no bullets
    CHECK_EQ(tom->hasboolets(),false);
    CHECK_EQ(jery->get_hit_points(),50);
    tom->reload();
    for (int i=0;i<5;i++){
        tom->shoot(jery);//5 , -10
    } 
    CHECK_THROWS(tom->shoot(jery));//jery is dead

}

TEST_CASE("Team - simple functions") { 
    
    //______team_A______
    Point a(0, 20);
    Cowboy *tom = new Cowboy("Tom", a);
    Team team_A(tom); 
    CHECK_EQ(team_A.get_leader(),tom);
    CHECK_THROWS(team_A.attack(&team_A)); //TOM CANT BE IN TWO TEAMS
    CHECK_THROWS(Team (tom)); //TOM CANT BE IN TWO TEAMS
    for (int i=0;i<9;i++){
        team_A.add(new YountNinja("Tom", Point(0,i)));
    }
    CHECK_EQ(team_A.stillAlive(),10);
    CHECK_THROWS(team_A.add(new YountNinja("Tom", Point(10,0))));//team is full
    
    //______team_B______
    Point b(0,-1);
    Cowboy *jery = new Cowboy("jery", b);
    Team team_B(jery);
    for (int i=0;i<9;i++){
        team_B.add(new YountNinja("jery", Point(0,-2-i)));
    }

    for(int i=0;i<9;i++){
        CHECK_EQ(team_B.stillAlive(),10-i);
        team_A.attack(&team_B);

    }
    CHECK_THROWS(team_A.attack(&team_B));//TEAM B IS DEFETED
}
