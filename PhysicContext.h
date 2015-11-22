#ifndef __PHYSIC_CONTEXT_H_
#define __PHYSIC_CONTEXT_H_

#include "PhysicObject.h"
#include "PhysicCollision.h"
#include <map>

class PhysicContext {
    public:
        PhysicContext();
        ~PhysicContext();

        const std::vector<PhysicObject>& getPhysicObjects() const;
    private:
        void addPhysicObject(const PhysicObject& physicObject);
        
        std::vector<PhysicObject> objects;
        std::map<std::pair<const PhysicObject*, const PhysicObject*>,
                const PhysicCollision*> physicCollisions;
};

#endif
