#ifndef __PHYSIC_DRAWABLE_H_
#define __PHYSIC_DRAWABLE_H_

#include <GL/gl.h>
#include <GL/glu.h>

#include "Color.h"

class PhysicDrawable {
    public:
        PhysicDrawable(const Color& color) {
            this->color = color;
        }
        virtual ~PhysicDrawable() {

        }
    
        virtual void draw() const = 0;
    protected:
        Color color;
};

#endif
