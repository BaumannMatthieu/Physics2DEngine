#include<iostream>

#include "Polygon2D.h"
#include "PhysicPolygonCollision.h"

int main(void) {
    Polygon2D poly1 = Polygon2D::CreateRandom(Point(100.f, 100.f),
                                              50.f, 0.1f, 10.f, 5);
    Polygon2D poly2 = Polygon2D::CreateRandom(Point(-20.f, -20.f),
                                              50.f, 0.1f, 10.f, 5);
    
    PhysicPolygonCollision polyCollision;

    if(polyCollision.Compute(poly1, poly2)) {
        std::cout << "collision !" << std::endl;
    }
     
    return 0;
}
