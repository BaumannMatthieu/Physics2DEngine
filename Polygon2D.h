#ifndef __POLYGON2D_H
#define __POLYGON2D_H

#include <vector>
#include "PhysicObject.h"
#include "Math.h"

class Polygon2D : public PhysicObject {
    public:
        Polygon2D(const std::vector<Point>& points, const Point& position,
                  const Color& color);
        virtual ~Polygon2D();

        static Polygon2D* CreateRandom(const Point& position, const float dimension, 
                                    const float epsilon, const float rho, 
                                    const unsigned int n,
                                    const Color& color);
        virtual void Translate(const Vector2<float>& t);
        void Rotate(const float angle);
        
        virtual void move();

        virtual PhysicCollision* getPhysicCollision(const PhysicObject& physicObject) const;
        virtual void draw() const;

        const std::vector<Point>& getPoints() const;    
    private:
        std::vector<Point> points;
        float angle;
};

#endif
