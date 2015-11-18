#ifndef __MATRIX22_H_
#define __MATRIX22_H_

#include <cmath>
#include <iostream>

#include "Vector2.h"

/** Classe which describes the behaviour of a vector in 2D */
template<typename T>
class Matrix22 {
    public:
        Matrix22(T a, T b, T c, T d) {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
        }

        Matrix22(const Vector2<T>& l1, const Vector2<T>& l2) {
            this->a = l1.x;
            this->b = l1.y;
            this->c = l2.x;
            this->d = l2.y;
        }

        Matrix22(const Matrix22<T>& matrix) {
            *this = matrix;
        }
       
        inline void log() {
            std::cout << a << " " << b << std::endl;
            std::cout << c << " " << d << std::endl;
        }

        inline Matrix22<T> operator-(const Matrix22<T>& m) {
            return Matrix22<T>(this->a - m.a, this->b - m.b,
                               this->c - m.c, this->d - m.d);
        }        
        
        inline Matrix22<T> operator+(const Matrix22<T>& m) {
            return Matrix22<T>(this->a + m.a, this->b + m.b,
                               this->c + m.c, this->d + m.d);
        }        
        
        inline Vector2<T> operator*(const Vector2<T>& v) {
            return Vector2<T>(this->a*v.x + this->b*v.y, this->c*v.x + this->d*v.y);
        }        
        
        inline Matrix22<T> operator*(const T& lambda) {
            return Matrix22<T>(this->a*lambda, this->b*lambda, this->c*lambda, this->d*lambda);
        }

        inline bool operator==(const Matrix22<T>& m) {
            return (this->a == m.a) && (this->b == m.b) &&
                   (this->c == m.c) && (this->d == m.d);
        }
        
        inline bool operator!=(const Matrix22<T>& m) {
            return !(*this == m);
        }

    public:
        T a;
        T b;
        T c;
        T d;
};

#endif
