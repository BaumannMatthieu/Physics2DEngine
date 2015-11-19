#include <iostream>
#include "Rectangle2D.h"

Rectangle2D::Rectangle2D() : PhysicObject(Point(0.f, 0.f)) {

}

Rectangle2D::Rectangle2D(const Vector2<float>& position, const float width,
                         const float height) : PhysicObject(position) {
    this->width = width;
    this->height = height;
    
    this->points[0] = position;
    this->points[1] = Point(position.x + width, position.y);
    this->points[2] = Point(position.x + width, position.y + height);
    this->points[3] = Point(position.x, position.y + height);
}

void Rectangle2D::Translate(const Vector2<float>& t) {
    for(unsigned int i = 0; i < 4; i++) {
        this->points[i] = this->points[i] + t;
    }    

    PhysicObject::Translate(t);
}

Rectangle2D::~Rectangle2D() {

}
