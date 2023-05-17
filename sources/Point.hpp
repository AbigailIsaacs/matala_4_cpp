#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>


namespace ariel{
    class Point {
        private:
        double x_cord;
        double y_cord;
    
        public:
            Point(double x_cord,double y_cord);
            double distance (Point p);
            void print();
            static Point moveTowards (Point p1, Point p2, double distance);
            double get_x ();
            double get_y ();
            friend bool operator==(const Point& p1,const Point& p2);
            
            ~Point() = default;



    };
}