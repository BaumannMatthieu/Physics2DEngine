#ifndef __VECTOR2F_H_
#define __VECTOR2F_H_

#include <cmath>
#include <iostream>

/** Classe which describes the behaviour of a vector in 2D */
template<typename T>
class Vector2 {
    public:
        Vector2(T x, T y) {
            this->x = x;
            this->y = y;
        }

        Vector2(const Vector2<T>& v) {
            this->x = v.x;
            this->y = v.y;
        }
 
        Vector2() {
        
        }
       
        inline void log() {
            std::cout << "X : " << x << " " << "Y : " << y << std::endl;
        }

        inline Vector2<T> operator-(const Vector2<T>& v) const {
            return Vector2<T>(this->x - v.x, this->y - v.y);
        }        
        
        inline Vector2<T> operator+(const Vector2<T>& v) const {
            return Vector2<T>(this->x + v.x, this->y + v.y);
        }        
        
        inline Vector2<T> operator*(const T& lambda) const {
            return Vector2<T>(this->x*lambda, this->y*lambda);
        }

        inline Vector2<T> operator/(const T& lambda) const {
            return Vector2<T>(this->x/lambda, this->y/lambda);
        }
        
        inline float norme() const {
            return (float)std::sqrt(this->x*this->x + this->y*this->y);
        }

        inline void normalize() {
            float norme = this->norme();
            *this = *this/norme;
        }

        inline void limits(float norme) {
            if(this->norme() > norme) {
                normalize();
                *this = *this*norme;
            }
        }

        inline bool operator==(const Vector2<T>& v) const {
            return (this->x == v.x) && (this->y == v.y);
        }
        
        inline bool operator!=(const Vector2<T>& v) const {
            return !(*this == v);
        }

        inline static float cross(const Vector2<T>& v1, const Vector2<T>& v2) {
            return v1.x*v2.x + v1.y*v2.y;
        }
        
        inline static const Vector2<float> opposite(const Vector2<T>& v) {
            return Vector2<float>(-v.x, -v.y);
        }

    public:
        T x;
        T y;
};

#endif
