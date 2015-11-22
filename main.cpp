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
     
    return 0;
}
