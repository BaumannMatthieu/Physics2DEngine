#ifndef __POINT2D_H
#define __POINT2D_H

#include <iostream>

#include "PhysicObject.h"
#include "Point.h"

class Point2D : public PhysicObject {

    public:
        Point2D(const Point& position);
        virtual ~Point2D();

        virtual void Translate(const Vector2<float>& t);
        virtual const PhysicCollision* getPhysicCollision(const PhysicObject& physicObject) const;
    
    private:
        Point point;
};

#endif
