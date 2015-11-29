#include "PhysicPolygonCollision.h"

#include "Math.h"
#include <limits>

PhysicPolygonCollision::PhysicPolygonCollision() {
    this->minimumTranslation = Vector2<float>(0.f, 0.f);  
}

PhysicPolygonCollision::~PhysicPolygonCollision() {
       
}

/** Collision between a Convex Polygon and a Convex Polygon */
bool PhysicPolygonCollision::Compute(const PhysicObject& firstPhysicObj, 
                                     const PhysicObject& secondPhysicObj) {
    const Polygon2D& firstPoly = static_cast<const Polygon2D&>(firstPhysicObj);      
    const Polygon2D& secondPoly = static_cast<const Polygon2D&>(secondPhysicObj);
    
    const std::vector<Vector2<float> > axisFirstPoly = computeAxis(firstPoly);
    const std::vector<Vector2<float> > axisSecondPoly = computeAxis(secondPoly);

    
    this->minimumTranslation = Vector2<float>(0.f, 0.f);
    float inter = 0.f;
    float normeMTV = std::numeric_limits<float>::max();
    const Vector2<float>* axisMTV = &axisFirstPoly[0];

    for(unsigned int i = 0; i < axisFirstPoly.size(); i++) {
        std::pair<float, float> p1 = projection(firstPoly, axisFirstPoly[i]);
        std::pair<float, float> p2 = projection(secondPoly, axisFirstPoly[i]);

        if(!intersection(p1, p2, inter)) {
            return false; 
        } else {
            if(inter < normeMTV) {
                normeMTV = inter;
                axisMTV = &axisFirstPoly[i];
            } 
        }
    }
    
    for(unsigned int i = 0; i < axisSecondPoly.size(); i++) {
        std::pair<float, float> p1 = projection(firstPoly, axisSecondPoly[i]);
        std::pair<float, float> p2 = projection(secondPoly, axisSecondPoly[i]);

        if(!intersection(p1, p2, inter)) {
            return false; 
        } else {
            if(inter < normeMTV) {
                normeMTV = inter;
                axisMTV = &axisSecondPoly[i];
            }
        }
    }
    
    this->minimumTranslation = *axisMTV;//Vector2<float>(-axisMTV->y, axisMTV->x);
    this->minimumTranslation = this->minimumTranslation*normeMTV;

    return true;
}

const std::vector<Vector2<float> > PhysicPolygonCollision::computeAxis(
const Polygon2D& polygon) const {
    const std::vector<Point>& points = polygon.getPoints();
    std::vector<Vector2<float> > axis;
    Vector2<float> current_axis;

    for(unsigned int i = 0; i < points.size() - 1; i++) {
        current_axis = points[i + 1] - points[i];
        current_axis.normalize();

        axis.push_back(Vector2<float>(-current_axis.y, current_axis.x));
    }

    current_axis = points[0] - points.back();
    current_axis.normalize();

    axis.push_back(Vector2<float>(-current_axis.y, current_axis.x));

    return axis;
}

std::pair<float, float> PhysicPolygonCollision::projection(const Polygon2D& polygon,
                                                           const Vector2<float>& axis) const {
    const std::vector<Point>& points = polygon.getPoints();
    
    float min = Vector2<float>::cross(points[0], axis);
    float max = min;

    for(unsigned int i = 1; i < points.size(); i++) {
        float dot = Vector2<float>::cross(points[i], axis);
        if(dot > max) {
            max = dot;
        } else if(dot < min) {
            min = dot;
        }
    }

    return std::pair<float, float>(min, max);
}

bool PhysicPolygonCollision::intersection(const std::pair<float, float>& p1,
                                          const std::pair<float, float>& p2,
                                          float& inter) const {
    if(std::max(Math::abs(p2.second - p1.first), Math::abs(p2.first - p1.second)) <= p1.second - p1.first + p2.second - p2.first) {
        inter = std::min(Math::abs(p2.second - p1.first), Math::abs(p2.first - p1.second));
        return true; 
    }

    return false;
}

