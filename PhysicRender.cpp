#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>

#include "PhysicRender.h"

PhysicRender::PhysicRender(PhysicContext *physicContext) {
    this->physicContext = physicContext; 
}

PhysicRender::~PhysicRender() {
    this->physicContext = NULL;
}
   
void PhysicRender::draw(SDL_Window* window) const {
    //Clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    const std::vector<PhysicObject>& physicObjects = this->physicContext->getPhysicObjects();
    std::cout << "ok " << physicObjects.size() << std::endl;
    for(unsigned int i = 0; i < physicObjects.size(); i++) {
        physicObjects[i].draw();
    }
    //Update screen
    SDL_GL_SwapWindow(window);
}
