#include "PhysicRectCollision.h"
#include "Rectangle2D.h"

PhysicRectCollision::PhysicRectCollision() {
    
}

PhysicRectCollision::~PhysicRectCollision() {
       
}

/** Collision between a Rectangle and a Rectangle */
bool PhysicRectCollision::Compute(const PhysicObject& firstPhysicObj, 
                                  const PhysicObject& secondPhysicObj) {
    const Rectangle2D& firstRect = static_cast<const Rectangle2D&>(firstPhysicObj);      
    const Rectangle2D& secondRect = static_cast<const Rectangle2D&>(secondPhysicObj);

    return ((firstRect.getPosition().x + firstRect.getWidth() > secondRect.getPosition().x &&
            firstRect.getPosition().y + firstRect.getHeight() > secondRect.getPosition().y) ||
           (secondRect.getPosition().x + secondRect.getWidth() > firstRect.getPosition().x &&
            secondRect.getPosition().y + secondRect.getHeight() > firstRect.getPosition().y));      
}
