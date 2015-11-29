#ifndef __POINT2D_H
#define __POINT2D_H

#include <iostream>

#include "PhysicObject.h"
#include "Point.h"

class Point2D : public PhysicObject {

    public:
        Point2D(const Point& position, const Color& color);
        virtual ~Point2D();

        virtual void Translate(const Vector2<float>& t);
        virtual PhysicCollision* getPhysicCollision(const PhysicObject& physicObject) const;
        virtual void draw() const {

        }
    private:
        Point point;
};

#endif
