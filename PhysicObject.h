#ifndef __PHYSIC_OBJECT_H_
#define __PHYSIC_OBJECT_H_

#include <vector>
#include "Vector2.h"
#include "Point.h"

class PhysicObject {
    public:
        PhysicObject(const Point& position);
        PhysicObject();
        virtual ~PhysicObject();
        
        virtual void Translate(const Vector2<float>& t) = 0;

        void setPosition(const Point& position);

    protected:
        Point position;
        Vector2<float> velocity;
        Vector2<float> acceleration;

        float angle;
};

#endif
