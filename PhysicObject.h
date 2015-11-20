#ifndef __PHYSIC_OBJECT_H_
#define __PHYSIC_OBJECT_H_

#include <vector>
#include "Vector2.h"
#include "Point.h"

class PhysicObject {
    public:
        PhysicObject(const Point& position);
        virtual ~PhysicObject();
        
        virtual void Translate(const Vector2<float>& t);
    
        Vector2<float> getPosition() const;

    protected:
        Point position;
        Vector2<float> velocity;
        Vector2<float> acceleration;
};

#endif
