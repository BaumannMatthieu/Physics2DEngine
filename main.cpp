#include<iostream>
#include "Vector2.h"


#include "Point.h"

int main(void) {
    Vector2<float> a(3.5f, 2.f);
    Vector2<float> b(3.f, 1.f);

    a.log();
    Vector2<float> f = a - b;

    Vector2<float> c = a*2.0f;
    Vector2<float> d = c/1.0f;

    a.log();
    b.log();
    f.log();
    c.log();
    d.log();

    if(c != d) {
        std::cout << "ok" << std::endl;
    }
          

    return 0;
}
