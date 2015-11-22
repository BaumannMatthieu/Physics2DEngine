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

    glBegin(GL_QUADS);
        glColor3f(1.f, 1.f, 0.f);
        glVertex2f(0.0f, 50.0f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex2f(100.f, 0.f);
        glColor3f(0.f, 1.f, 1.f);
        glVertex2f(100.f,  100.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex2f(0.f,  100.f);
    glEnd();

    //Update screen
    SDL_GL_SwapWindow(window);
}
