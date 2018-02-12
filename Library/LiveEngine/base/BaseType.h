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
    template<int N>
    class _Vec_
    {
        template<int M, int NN> friend struct plus;
        template<int M, int NN> friend struct minus;
        template<int M, int NN> friend struct dot;
    public:
        _Vec_()
        {
            memset(_v, 0, sizeof(float) * N);
        }
        
        template<typename ...Args>
        _Vec_(float f, Args&&... args) : _v { f, args... } {}
        
        virtual ~_Vec_() = default;

        template<typename DerivedClass>
        inline DerivedClass operator+(const DerivedClass& other) const;
        template<typename DerivedClass>
        inline DerivedClass operator-(const DerivedClass& other) const;
        inline float operator*(const _Vec_<N>& other) const;
        inline _Vec_<N> operator+=(const _Vec_<N>& other) const;
        inline _Vec_<N> operator-=(const _Vec_<N>& other) const;
        
        float _v[N];
    };
    
    class Vec2 : public _Vec_<2>
    {
    public:
        Vec2() : _Vec_<2>(0.0f, 0.0f){}
        Vec2(const _Vec_<2>& other) : _Vec_<2>(other) {}
        Vec2(float _u, float _v) : _Vec_<2>(_u, _v) {}
        
        float u() const { return _v[0]; }
        float v() const { return _v[1]; }
    
        void setU(float value) { _v[0] = value; }
        void setV(float value) { _v[1] = value; }
    };
    
    class Vec3 : public _Vec_<3>
    {
    public:
        Vec3() : _Vec_<3>(0.0f, 0.0f, 0.0f){}
        Vec3(const _Vec_<3>& other) : _Vec_<3>(other) {}
        Vec3(float _x, float _y, float _z) : _Vec_<3>(_x, _y, _z) {}
        inline Vec3 cross(const Vec3& other) const;

        float x() const { return _v[0]; }
        float y() const { return _v[1]; }
        float z() const { return _v[2]; }
        
        void setX(float value) { _v[0] = value; }
        void setY(float value) { _v[1] = value; }
        void setZ(float value) { _v[2] = value; }
    };
    
    class Vec4 : public _Vec_<4>
    {
    public:
        Vec4() : _Vec_<4>(0.0f, 0.0f, 0.0f, 0.0f) {}
        Vec4(const _Vec_<4>& other) : _Vec_<4>(other) {}
        Vec4(float _x, float _y, float _z, float _w) : _Vec_<4>(_x, _y, _z, _w) {}

        float x() const { return _v[0]; }
        float y() const { return _v[1]; }
        float z() const { return _v[2]; }
        float w() const { return _v[3]; }
        
        void setX(float value) { _v[0] = value; }
        void setY(float value) { _v[1] = value; }
        void setZ(float value) { _v[2] = value; }
        void setW(float value) { _v[2] = value; }
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

    class Matrix4D
    {
    public:
        static constexpr uint8_t ROW = 4;
        static constexpr uint8_t COLUMN = 4;
        static Matrix4D Identity()
        {
            return {1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
                    0.0f, 0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f};
        }
    public:
        Matrix4D();
        
        template<typename... Args>
        Matrix4D(float head, Args&&... args) : m { head, static_cast<float>(args)... }
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
        
        inline Vec4 operator*(const Vec3& vec) const;
        inline Vec4 operator*(const Vec4& vec) const;
    public:
        Matrix4D transpose() const;
        Matrix4D inverse() const;
        float eigenValue() const;
        Vec4 eigenVector() const;
        const float determinant() const;
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
        
        Matrix4D(Matrix4D&& mat) noexcept
        {
            *this = std::move(mat);
        };
        Matrix4D& operator=(Matrix4D&& other) noexcept
        {
            if(this != &other )
            {
                *this = std::move(other);
            }
            return *this;
        };
    };
    
    #include "Vec.inl"
    #include "Matrix4D.inl"
}

#endif /* defined(__LiveEngine__Rect__) */
