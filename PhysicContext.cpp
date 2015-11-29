#include "PhysicContext.h"

#include "PhysicObject.h"
#include "PhysicCollision.h"

#include "Polygon2D.h"
#include "Rectangle2D.h"
#include "Point2D.h"

#include "Color.h"

PhysicContext::PhysicContext() {

    for(int i = 0; i < 20; i++) {
        Polygon2D* poly = Polygon2D::CreateRandom(Point(Math::random(0.f, 800.f),
                                                      Math::random(0.f, 600.f)),
                                                50.f, 0.1, 10.f, 3, 
                                                Color(1.f, 0.f, 0.f));
        poly->setVelocity(Vector2<float>(Math::random(-1.f, 1.f), Math::random(-1.f, 1.f)));
        PhysicContext::addPhysicObject(poly);      
    }
    /*Polygon2D* poly1 = Polygon2D::CreateRandom(Point(100.f, 100.f),
                                              50.f, 0.1f, 10.f, 3,
                                              Color(1.f, 0.f, 0.f));
    Polygon2D* poly2 = Polygon2D::CreateRandom(Point(500.f, 500.f),
                                              50.f, 0.1f, 10.f, 3,
                                              Color(0.f, 1.f, 0.f));
    poly2->setVelocity(Vector2<float>(-0.7f, -0.7f));


    PhysicContext::addPhysicObject(poly2);   */    
}

void PhysicContext::update() {
    /** Move all objects of the context */
    std::vector<PhysicObject*>::iterator it;
        for(it = this->objects.begin(); it != this->objects.end(); ++it) {
            (*it)->move();
        }

    /** Analyze if there are collisions between objects and correct them */
    std::map<std::pair<PhysicObject*, PhysicObject*>,
             PhysicCollision*>::iterator it_collisions;
    for(it_collisions = this->physicCollisions.begin();
        it_collisions != this->physicCollisions.end(); ++it_collisions) {
        PhysicCollision* collision = it_collisions->second;

        PhysicObject* firstObj = it_collisions->first.first;        
        PhysicObject* secondObj = it_collisions->first.second;        

        if(collision->Compute(*firstObj, *secondObj)) {
            const Vector2<float>& mtv = collision->getMinimunTranslationVector();
            std::cout << mtv.norme() << std::endl;
            secondObj->Translate(mtv*1.01f);

            const Vector2<float>& secondObjVel = secondObj->getVelocity();
            const Vector2<float>& firstObjVel = firstObj->getVelocity();
            Vector2<float> mtvbis = mtv;
            mtvbis.normalize();
            
            secondObj->setVelocity(mtvbis*secondObjVel.norme());  
            firstObj->setVelocity(Vector2<float>::opposite(mtvbis)*firstObjVel.norme());  
            
            std::cout << "two objects collide !" << std::endl;
        }
    }
}

PhysicContext::~PhysicContext() {
    this->objects.clear();
    this->physicCollisions.clear();
}

void PhysicContext::addPhysicObject(PhysicObject* physicObject) {
    std::vector<PhysicObject*>::iterator it;
    for(it = this->objects.begin(); it != this->objects.end(); ++it) {
        PhysicCollision *physicCollision = (*it)->getPhysicCollision(*physicObject);
        this->physicCollisions.insert(std::make_pair(
                        std::make_pair(physicObject, *it), physicCollision));
    }
    this->objects.push_back(physicObject);
}
const std::vector<PhysicObject*>& PhysicContext::getPhysicObjects() const {
    return this->objects;
}

