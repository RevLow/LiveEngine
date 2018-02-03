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
    template<int N, typename T>
    class _Vec_ : Uncopyable
    {
        template<int NN, typename TT> friend struct plus;
        template<int NN, typename TT> friend struct minus;
        template<int NN, typename TT> friend struct dot;
    public:
        template<typename... Args>
        _Vec_(Args&&... args) : v { args... } {}
        virtual ~_Vec_() = default;

        inline T operator+(const T& other) const;
        inline T operator-(const T& other) const;
        inline float operator*(const T& other) const;
    protected:
        float v[N];
        
        DEFINE_DEFAULT_MOVE_CONSTRUCTOR(_Vec_);
    };
    
    class Vec3 : public _Vec_<3, Vec3>
    {
    public:
        Vec3() : _Vec_(0.0f, 0.0f, 0.0f) {}
        Vec3(float _x, float _y, float _z) : _Vec_(_x, _y, _z) {}
        inline Vec3 cross(const Vec3& other) const;
        float& x = v[0];
        float& y = v[1];
        float& z = v[2];
    };
    
    class Vec4 : public _Vec_<4, Vec4>
    {
    public:
        Vec4() : _Vec_(0.0f, 0.0f, 0.0f, 0.0f) {}
        Vec4(float _x, float _y, float _z, float _w) : _Vec_(_x, _y, _z, _w) {}
        float& x = v[0];
        float& y = v[1];
        float& z = v[2];
        float& w = v[3];
    };
    
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
        
        inline Matrix4D& operator*(const Vec3& vec) const;
        inline Matrix4D& operator*(const Vec4& vec) const;
    public:
        Matrix4D transpose() const;
        Matrix4D inverse() const;
        float eigenValue() const;
        Vec4 eigenVector() const;
        float determinant() const;

        DEFINE_DEFAULT_MOVE_CONSTRUCTOR(Matrix4D);
    };
    
    #include "Vec.inl"
    #include "Matrix4D.inl"
}

#endif /* defined(__LiveEngine__Rect__) */
