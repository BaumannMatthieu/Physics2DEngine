#include "PhysicContext.h"

#include "Polygon2D.h"
#include "Rectangle2D.h"
#include "Point2D.h"

#include "Color.h"

PhysicContext::PhysicContext() {
    Polygon2D* poly1 = Polygon2D::CreateRandom(Point(100.f, 100.f),
                                              50.f, 0.1f, 10.f, 5,
                                              Color(1.f, 0.f, 0.f));
    Polygon2D* poly2 = Polygon2D::CreateRandom(Point(500.f, 500.f),
                                              50.f, 0.1f, 10.f, 5,
                                              Color(0.f, 1.f, 0.f));
    PhysicContext::addPhysicObject(poly1);      
    PhysicContext::addPhysicObject(poly2);      
}

PhysicContext::~PhysicContext() {
    this->objects.clear();
    this->physicCollisions.clear();
}

void PhysicContext::addPhysicObject(PhysicObject* physicObject) {
    std::vector<PhysicObject*>::iterator it;
    for(it = this->objects.begin(); it != this->objects.end(); ++it) {
        const PhysicCollision *physicCollision = (*it)->getPhysicCollision(*physicObject);
        this->physicCollisions.insert(std::make_pair(
                        std::make_pair(physicObject, *it), physicCollision));
    }
    this->objects.push_back(physicObject);
}
const std::vector<PhysicObject*>& PhysicContext::getPhysicObjects() const {
    return this->objects;
}

