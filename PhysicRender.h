#ifndef __PHYSIC_RENDER_H_
#define __PHYSIC_RENDER_H_

#include "PhysicContext.h"

class PhysicRender {
    public:
        PhysicRender(PhysicContext *physicContext);
        ~PhysicRender();
    
        void draw(SDL_Window* window) const;
    private:
        PhysicContext *physicContext;
};

#endif
