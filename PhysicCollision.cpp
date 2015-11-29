#include <iostream>
#include "PhysicCollision.h"

PhysicCollision::PhysicCollision() {

}

PhysicCollision::~PhysicCollision() {

}

const Vector2<float>& PhysicCollision::getMinimunTranslationVector() const {
    return this->minimumTranslation;
}
