#include<iostream>

#include "PhysicObject.h"

PhysicObject::PhysicObject(const Point& position) {
    this->position = position;
    this->velocity = Vector2<float>(0.f, 0.f); 
    this->acceleration = Vector2<float>(0.f, 0.f); 
}

PhysicObject::~PhysicObject() {

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

const PhysicCollision* PhysicObject::getPhysicCollision(const PhysicObject& physicObject) const {
    return NULL;
}
