#include "Matrix22.h"
#include "Math.h"

#include "Polygon2D.h"
#include "PhysicPolygonCollision.h"

Polygon2D::Polygon2D(const std::vector<Point>& points, const Point& position) :
PhysicObject(position) {
    this->points = points;
    this->angle = 0.f;
    this->objectType = POLYGON;
}

Polygon2D::~Polygon2D() {
    this->points.clear();
}

Polygon2D Polygon2D::CreateRandom(const Point& position, const float dimension, 
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

void Polygon2D::Translate(const Vector2<float>& t) {
    std::vector<Point>::iterator it;

    for(it = this->points.begin(); it != this->points.end(); ++it) {
        *it = *it + t;
    }

    PhysicObject::Translate(t);
}

void Polygon2D::Rotate(const float angle) {
    this->angle += angle;
    Matrix22<float> rotationMatrix(Math::cos(this->angle), Math::sin(this->angle),
                                   -Math::sin(this->angle), Math::cos(this->angle));
    
    std::vector<Point>::iterator it;
   
    for(it = this->points.begin(); it != this->points.end(); ++it) {
        *it = *it - this->position;
        Point p(*it);
            
        *it = rotationMatrix*p;
        
        *it = *it + this->position;
    } 
}


const PhysicCollision* Polygon2D::getPhysicCollision(const PhysicObject& physicObject) const {
    const PhysicObjectType objectType = physicObject.getObjectType();
    PhysicCollision* physicCollision = NULL;
    
    if(objectType == POLYGON || objectType == RECTANGLE) {
        physicCollision = new PhysicPolygonCollision();
    } else if(objectType == POINT) {
        
    } else if(objectType == SEGMENT) {

    } else { /* circle */

    }

    return physicCollision;
}

const std::vector<Point>& Polygon2D::getPoints() const {
    return this->points;
}


