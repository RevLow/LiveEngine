//
//  Rect.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Rect__
#define __LiveEngine__Rect__

#include "Uncopyable.h"

namespace live
{
    struct Rect {
        int x;
        int y;
        int width;
        int height;
    };

    class Matrix4D : public Uncopyable
    {
    public:
        static constexpr int ROW = 4;
        static constexpr int COLUMN = 4;
        static Matrix4D Identity()
        {
            return {1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f};
        }
    public:
        union {
            struct {
                float m11, m12, m13, m14,
                      m21, m22, m23, m24,
                      m31, m32, m33, m34,
                      m41, m42, m43, m44;
            };
            
            float m[ROW * COLUMN];
        };
        
        template <typename... Args>
        Matrix4D(Args&&... args) : m { args... }
        {
            static_assert(sizeof...(args)==ROW*COLUMN, "Matrix Size Length is Invalid. Please check element length");
        }
        
        inline float at(const unsigned short row, const unsigned short column)
        {
            return m[row * ROW + column];
        }
        
        inline Matrix4D& operator+() { return *this; }
        inline Matrix4D operator-() {
            return {
                -m11, -m12, -m13, -m14,
                -m21, -m22, -m23, -m24,
                -m31, -m32, -m33, -m34,
                -m41, -m42, -m43, -m44
            };
        };
        
        inline Matrix4D operator+(const Matrix4D& other)
        {
        #define PLUS(ELEM) ELEM+other.ELEM
            return {
                PLUS(m11), PLUS(m12), PLUS(m13), PLUS(m14),
                PLUS(m21), PLUS(m22), PLUS(m23), PLUS(m24),
                PLUS(m31), PLUS(m32), PLUS(m33), PLUS(m34),
                PLUS(m41), PLUS(m42), PLUS(m43), PLUS(m44)
            };
        #undef PLUS
        }
        inline Matrix4D operator-(const Matrix4D& other)
        {
        #define MINUS(ELEM) ELEM-other.ELEM
            return {
                MINUS(m11), MINUS(m12), MINUS(m13), MINUS(m14),
                MINUS(m21), MINUS(m22), MINUS(m23), MINUS(m24),
                MINUS(m31), MINUS(m32), MINUS(m33), MINUS(m34),
                MINUS(m41), MINUS(m42), MINUS(m43), MINUS(m44)
            };
        #undef MINUS
        }
        
        Matrix4D operator*(const Matrix4D& other)
        {

        }
        
        Matrix4D(Matrix4D&&) = default;
        Matrix4D& operator=(Matrix4D&&) = default;
    };
}

#endif /* defined(__LiveEngine__Rect__) */
