#include <iostream>
#include "Rectangle2D.h"
#include "PhysicRectCollision.h"

PhysicRectCollision::PhysicRectCollision() {
    
}

PhysicRectCollision::~PhysicRectCollision() {
       
}

/** Collision between a Rectangle and a Rectangle */
bool PhysicRectCollision::Compute(const PhysicObject& firstPhysicObj, 
                                  const PhysicObject& secondPhysicObj) {
    /*
    Rectangle2D firstRect = static_cast<Rectangle2D>(firstPhysicObj);      
    Rectangle2D secondRect = static_cast<Rectangle2D>(secondPhysicObj);

    return ((firstRect.position.x + firstRect.width > secondRect.position.x &&
            firstRect.position.y + firstRect.height > secondRect.position.y) ||
           (secondRect.position.x + secondRect.width > firstRect.position.x &&
            secondRect.position.y + secondRect.height > firstRect.position.y));      
    */
    return true;
}
