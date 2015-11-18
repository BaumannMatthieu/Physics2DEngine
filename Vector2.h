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

        inline Vector2<T> operator-(const Vector2<T>& v) {
            return Vector2<T>(this->x - v.x, this->y - v.y);
        }        
        
        inline Vector2<T> operator+(const Vector2<T>& v) {
            return Vector2<T>(this->x + v.x, this->y + v.y);
        }        
        
        inline Vector2<T> operator*(const T& lambda) {
            return Vector2<T>(this->x*lambda, this->y*lambda);
        }

        inline Vector2<T> operator/(const T& lambda) {
            return Vector2<T>(this->x/lambda, this->y/lambda);
        }
        
        inline float norme() {
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

        inline bool operator==(const Vector2<T>& v) {
            return (this->x == v.x) && (this->y == v.y);
        }
        
        inline bool operator!=(const Vector2<T>& v) {
            return !(*this == v);
        }

    public:
        T x;
        T y;
};

#endif
