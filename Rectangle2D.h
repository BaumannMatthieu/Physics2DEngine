#ifndef __RECTANGLE2D_H
#define __RECTANGLE2D_H

#include "PhysicObject.h"

class Rectangle2D : public PhysicObject {
    public:
        Rectangle2D();
        Rectangle2D(const Vector2<float>& position,
                    const float width, const float height);
        virtual ~Rectangle2D();

        virtual void Translate(const Vector2<float>& t);

        Rectangle2D operator=(const Rectangle2D& rect);

        float getWidth() const;
        float getHeight() const;

    private:
        float width;
        float height;

        Point points[4];
};

#endif

