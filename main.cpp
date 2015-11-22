#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL2/SDL.h>
#include <iostream>

#include "Polygon2D.h"
#include "PhysicPolygonCollision.h"

#include "System.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


int main(void) {
    System system(SCREEN_WIDTH, SCREEN_HEIGHT, "PhysicEngine2D");
    system.start();

    Polygon2D poly1 = Polygon2D::CreateRandom(Point(100.f, 100.f),
                                              50.f, 0.1f, 10.f, 5);
    Polygon2D poly2 = Polygon2D::CreateRandom(Point(1000.f, 1000.f),
                                              50.f, 0.1f, 10.f, 5);
    
    PhysicPolygonCollision polyCollision;

    if(polyCollision.Compute(poly1, poly2)) {
        std::cout << "collision !" << std::endl;
    }
     
    return 0;
}
