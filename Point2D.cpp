#include <iostream>

#include "PhysicObject.h"
#include "Point2D.h"

Point2D::Point2D(const Point& position) : PhysicObject(position) {
    this->point = position;
}

Point2D::~Point2D() {

}

void Point2D::Translate(const Vector2<float>& t) {
    this->point = this->point + t;
    PhysicObject::Translate(t);
}
   

