#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Point.hpp"
using namespace std ;
namespace ariel{

    Point::Point(double x_cord,double y_cord){}
    double Point::distance (Point p){
        return 0;
    }
    void Point::print(){}
    Point Point::moveTowards (Point p1, Point p2, double distance){
        Point p (1,1);
        return p ;
    }
    double Point::get_x (){
        return 0;
    }
    double Point::get_y (){
        return 0;
    }

    bool operator==(const Point& p1,const Point& p2){
        return true;
    }
}