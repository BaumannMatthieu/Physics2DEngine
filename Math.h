#ifndef __MATH_H_
#define __MATH_H_

#include <cmath>
#include <cstdlib>
#include <ctime>

#define M_PI 3.14159265358979323846

namespace Math {
    float cos(const float alpha) {
        return std::cos(alpha);    
    }
    
    float sin(const float alpha) {
        return std::sin(alpha);    
    }
    
    template<typename T>
    T random(const T min, const T max) {
        return min + (max - min)*static_cast<T>(std::rand())/(static_cast<T>(RAND_MAX));
    }

    void initializeRandom() {
        std::srand(static_cast<unsigned>(time(0)));
    }
};

#endif
