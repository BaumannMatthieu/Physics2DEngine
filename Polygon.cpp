#include <vector>
#include <iostream>

#include "Polygon.h"

Polygon::Polygon(const std::vector<Point>& points, const Point& position) : PhysicObject(position) {
    this->points = points;
}

Polygon::Polygon() {

}

Polygon::~Polygon() {
    this->points.clear();
}

void Polygon::Translate(const Vector2<float>& t) {
    std::vector<Point>::iterator it;

    for(it = this->points.begin(); it != this->points.end(); it++) {
        *it = *it + t;
    }
}

void Polygon::Rotate(const float angle) {
    this->angle += angle;
    Matrix22<float> rotationMatrix(Math::cos(this->angle), Math::sin(this->angle),
                                   -Math::sin(this->angle), Math::cos(this->angle));
    
    std::vector<Point>::iterator it;
   
    for(it = this->points.begin(); it != this->points.end(); it++) {
        *it = *it - this->position;
        Point p(*it);
            
        *it = rotationMatrix*p;
        
        *it = *it + this->position;
    } 
}


