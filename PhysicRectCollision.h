#ifndef __PHYSIC_RECT_COLLISION_H_
#define __PHYSIC_RECT_COLLISION_H_

#include "PhysicCollision.h"

class PhysicRectCollision : public PhysicCollision {
    public:
        PhysicRectCollision();
        virtual ~PhysicRectCollision();
        
        virtual bool Compute(const PhysicObject& firstPhysicObj, 
                             const PhysicObject& secondPhysicObj);
};

#endif
