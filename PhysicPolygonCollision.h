#ifndef __PHYSIC_POLY_COLLISION_H_
#define __PHYSIC_POLY_COLLISION_H_

#include "PhysicCollision.h"
#include "Polygon2D.h"

class PhysicPolygonCollision : public PhysicCollision {
    public:
        PhysicPolygonCollision();
        virtual ~PhysicPolygonCollision();
        
        virtual bool Compute(const PhysicObject& firstPhysicObj, 
                             const PhysicObject& secondPhysicObj);
   
        const Vector2<float>& getMinimunTranslationVector() const;
 
    private:
        const std::vector<Vector2<float> > computeAxis(const Polygon2D& polygon) const;
        std::pair<float, float> projection(const Polygon2D& polygon,
                                           const Vector2<float>& axis) const;
        bool intersection(const std::pair<float, float>& p1,
                          const std::pair<float, float>& p2,
                          float& inter) const;      

        Vector2<float> minimumTranslation;
};

#endif
