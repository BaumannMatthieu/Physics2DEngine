#ifndef __MATHH_H_
#define __MATHH_H_

#include <cmath>
#include <cstdlib>
#include <ctime>

#define M_PI 3.14159265358979323846

namespace Math {
    inline float cos(const float alpha) {
        return std::cos(alpha);    
    }
    
    inline float sin(const float alpha) {
        return std::sin(alpha);    
    }

    inline float abs(const float var) {
        return std::abs(var);
    }
    
    template<typename T>
    inline T random(const T min, const T max) {
        return min + (max - min)*static_cast<T>(std::rand())/(static_cast<T>(RAND_MAX));
    }

    inline void initializeRandom() {
        std::srand(static_cast<unsigned>(time(0)));
    }
};

#endif
