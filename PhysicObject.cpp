#include<iostream>

#include "PhysicObject.h"

PhysicObject::PhysicObject(const Point& position, const Color& color)
 : PhysicDrawable(color) {
    this->position = position;
    this->velocity = Vector2<float>(0.f, 0.f); 
    this->acceleration = Vector2<float>(0.f, 0.f); 
}

PhysicObject::~PhysicObject() {

}

void PhysicObject::move() {
    this->Translate(this->velocity);
}

Vector2<float> PhysicObject::getPosition() const {
    return this->position;
}

void PhysicObject::Translate(const Vector2<float>& t) {
    this->position = this->position + t;
}
        
const PhysicObjectType PhysicObject::getObjectType() const {
    return this->objectType;
}

void PhysicObject::setVelocity(const Vector2<float>& velocity) {
    this->velocity = velocity;
}
