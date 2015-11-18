#ifndef __POLYGON_H
#define __POLYGON_H

#include <vector>
#include <cmath>
#include <iostream>
#include <vector>

#include "Matrix22.h"
#include "PhysicObject.h"
#include "Point.h"
#include "Math.h"

class Polygon : public PhysicObject {
    public:
        Polygon(const std::vector<Point>& points, const Point& position);
        Polygon();
        virtual ~Polygon();

        static Polygon CreateRandom(const Point& position, const float dimension, 
                                    const float epsilon, const float rho, 
                                    const unsigned int n) {
            Polygon polygon;
            
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

            for(unsigned int i = 0; i < n; i++) {
                k[i] = sum_dtheta/(2*M_PI);
                if(i == 0) {
                    theta[0] = dtheta[0]/k[0];
                } else {
                    theta[i] = theta[i - 1] + dtheta[i]/k[i];
                }
                polygon.points.push_back(Point(position.x + Math::cos(theta[i])*rad[i],
                                               position.y + Math::sin(theta[i])*rad[i]));
            }

            polygon.position = position;

            delete[] dtheta;
            delete[] k;
            delete[] theta;
            delete[] rad;
            
            return polygon; 
        }

        virtual void Translate(const Vector2<float>& t);
        void Rotate(const float angle);
    
    private:
        std::vector<Point> points;
};

#endif
