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
    class Vec2
    {
    public:
        union {
            int x, y;
        };
    };
    class Vec3;
    class Vec4;
    
    class Position
    {
    public:
        int x;
        int y;
    };

    class Size
    {
    public:
        int width;
        int height;
    };
    
    class Rect {
    public:
        Position position;
        Size size;
    };
    
    class Circle
    {
    public:
        
    };

    class Matrix4D : Uncopyable
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
        
        Matrix4D();
        
        template<typename... Args>
        Matrix4D(Args&&... args) : m { args... }
        {
        }
        
        virtual ~Matrix4D() = default;
    public:
        inline Matrix4D operator-() const;
        inline Matrix4D operator+(const Matrix4D& other) const;
        inline Matrix4D operator-(const Matrix4D& other) const;
        inline Matrix4D operator*(const Matrix4D& other) const;
        
        inline Matrix4D& operator+=(const Matrix4D& other);
        inline Matrix4D& operator-=(const Matrix4D& other);
        inline Matrix4D& operator*=(const Matrix4D& other);
        
        inline Matrix4D& operator*(const Vec2& vec) const;
        inline Matrix4D& operator*(const Vec3& vec) const;
        inline Matrix4D& operator*(const Vec4& vec) const;
        
        Matrix4D operator+() const = delete;
        Matrix4D operator/(const Matrix4D& other) = delete;
        Matrix4D& operator/=(const Matrix4D& other) = delete;
    public:
        Matrix4D transpose() const;
        Matrix4D inverse() const;
        float eigenValue() const;
        Vec4 eigenVector() const;
        float determinant() const;

        DEFINE_DEFAULT_MOVE_CONSTRUCTOR(Matrix4D);
    };
    
    #include "Matrix4D.inl"
    
    
}

#endif /* defined(__LiveEngine__Rect__) */
