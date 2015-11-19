#include <vector>
#include <iostream>

#include "Polygon2D.h"

Polygon2D::Polygon2D(const std::vector<Point>& points, const Point& position) :
PhysicObject(position) {
    this->points = points;
    this->angle = 0.f;
}

Polygon2D::~Polygon2D() {
    this->points.clear();
}

void Polygon2D::Translate(const Vector2<float>& t) {
    std::vector<Point>::iterator it;

    for(it = this->points.begin(); it != this->points.end(); it++) {
        *it = *it + t;
    }

    PhysicObject::Translate(t);
}

void Polygon2D::Rotate(const float angle) {
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


