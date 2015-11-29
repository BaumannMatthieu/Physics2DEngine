#ifndef __PHYSIC_COLLISION_H_
#define __PHYSIC_COLLISION_H_

#include "PhysicObject.h"

class PhysicCollision {
    public:
        PhysicCollision();
        virtual ~PhysicCollision();
        
        virtual bool Compute(const PhysicObject& firstPhysicObj, 
                             const PhysicObject& secondPhysicObj) = 0;
        const Vector2<float>& getMinimunTranslationVector() const;

    protected:
        Vector2<float> minimumTranslation;
};

#endif
