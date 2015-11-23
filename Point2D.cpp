#include <iostream>

#include "PhysicObject.h"
#include "Point2D.h"

Point2D::Point2D(const Point& position, const Color& color) : PhysicObject(position, color) {
    this->point = position;
    this->objectType = POINT;
}

Point2D::~Point2D() {

}

void Point2D::Translate(const Vector2<float>& t) {
    this->point = this->point + t;
    PhysicObject::Translate(t);
}
   
const PhysicCollision* Point2D::getPhysicCollision(const PhysicObject& physicObject) const {
    return NULL;
}
