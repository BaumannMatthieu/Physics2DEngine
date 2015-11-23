#ifndef __PHYSIC_OBJECT_H_
#define __PHYSIC_OBJECT_H_

#include <vector>
#include "Vector2.h"
#include "Point.h"
#include "PhysicDrawable.h"

typedef enum PhysicObjectType {
            POLYGON, 
            RECTANGLE, 
            POINT, 
            SEGMENT, 
            CIRCLE
        } PhysicObjectType;

class PhysicCollision;

class PhysicObject : public PhysicDrawable {
    public:
        PhysicObject(const Point& position, const Color& color);
        virtual ~PhysicObject();
        
        virtual void Translate(const Vector2<float>& t);
    
        Vector2<float> getPosition() const;
        const PhysicObjectType getObjectType() const;

        virtual const PhysicCollision* getPhysicCollision(const PhysicObject& physicObject) const = 0;
        virtual void draw() const = 0;

    protected:
        Point position;
        Vector2<float> velocity;
        Vector2<float> acceleration;

        PhysicObjectType objectType;
};

#endif
