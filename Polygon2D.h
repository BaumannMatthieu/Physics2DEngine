#ifndef __POLYGON2D_H
#define __POLYGON2D_H

#include "PhysicObject.h"

class Polygon2D : public PhysicObject {
    public:
        Polygon2D(const std::vector<Point>& points, const Point& position);
        virtual ~Polygon2D();

        static Polygon2D CreateRandom(const Point& position, const float dimension, 
                                    const float epsilon, const float rho, 
                                    const unsigned int n);
        virtual void Translate(const Vector2<float>& t);
        void Rotate(const float angle);
    
    private:
        std::vector<Point> points;
        float angle;
};

#endif
