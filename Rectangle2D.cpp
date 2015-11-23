#include <iostream>
#include "Rectangle2D.h"

Rectangle2D::Rectangle2D(const Vector2<float>& position, const float width,
                         const float height,
                         const Color& color) : PhysicObject(position, color) {
    this->width = width;
    this->height = height;
    
    this->points[0] = position;
    this->points[1] = Point(position.x + width, position.y);
    this->points[2] = Point(position.x + width, position.y + height);
    this->points[3] = Point(position.x, position.y + height);
    
    this->objectType = RECTANGLE;
}

void Rectangle2D::Translate(const Vector2<float>& t) {
    for(unsigned int i = 0; i < 4; i++) {
        this->points[i] = this->points[i] + t;
    }    

    PhysicObject::Translate(t);
}

const PhysicCollision* Rectangle2D::getPhysicCollision(const PhysicObject& physicObject) const {
    return NULL;
}

float Rectangle2D::getWidth() const {
    return this->width;
}

float Rectangle2D::getHeight() const {
    return this->height;
}

Rectangle2D Rectangle2D::operator=(const Rectangle2D& rect) {
    this->width = rect.width;
    this->height = rect.height;
    for(unsigned int i = 0; i < 4; i++) {
        this->points[i] = rect.points[i];
    }
    return *this;
}

Rectangle2D::~Rectangle2D() {

}
