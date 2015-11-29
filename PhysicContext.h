#ifndef __PHYSIC_CONTEXT_H_
#define __PHYSIC_CONTEXT_H_

#include <map>
#include <vector>

#include "PhysicCollision.h"
#include "PhysicObject.h"

class PhysicContext {
    public:
        PhysicContext();
        ~PhysicContext();

        void update();
        const std::vector<PhysicObject*>& getPhysicObjects() const;
    private:
        void addPhysicObject(PhysicObject* physicObject);
        
        std::vector<PhysicObject*> objects;
        std::map<std::pair<PhysicObject*, PhysicObject*>,
                 PhysicCollision*> physicCollisions;
};

#endif
