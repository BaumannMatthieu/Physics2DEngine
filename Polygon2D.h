#ifndef __POLYGON2D_H
#define __POLYGON2D_H

#include <vector>
#include <cmath>
#include <iostream>
#include <vector>

#include "Matrix22.h"
#include "PhysicObject.h"
#include "Point.h"
#include "Math.h"

class Polygon2D : public PhysicObject {
    public:
        Polygon2D(const std::vector<Point>& points, const Point& position);
        virtual ~Polygon2D();

        static Polygon2D CreateRandom(const Point& position, const float dimension, 
                                    const float epsilon, const float rho, 
                                    const unsigned int n) {
        
            float* dtheta = new float[n];
            float* k = new float[n];
            float* theta = new float[n];
            float* rad = new float[n];
 
            float sum_dtheta = 0.f;

            for(unsigned int i = 0; i < n; i++) {
                dtheta[i] = Math::random<float>(2*M_PI/n - epsilon, 2*M_PI/n + epsilon);
                rad[i] = Math::random<float>(dimension - rho, dimension + rho);
                
                sum_dtheta += dtheta[i];
            }

            std::vector<Point> points;

            for(unsigned int i = 0; i < n; i++) {
                k[i] = sum_dtheta/(2*M_PI);
                if(i == 0) {
                    theta[0] = dtheta[0]/k[0];
                } else {
                    theta[i] = theta[i - 1] + dtheta[i]/k[i];
                }
                points.push_back(Point(position.x + Math::cos(theta[i])*rad[i],
                                       position.y + Math::sin(theta[i])*rad[i]));
            }

            delete[] dtheta;
            delete[] k;
            delete[] theta;
            delete[] rad;
            
            return Polygon2D(points, position);
        }

        virtual void Translate(const Vector2<float>& t);
        void Rotate(const float angle);
    
    private:
        std::vector<Point> points;
        float angle;
};

#endif
