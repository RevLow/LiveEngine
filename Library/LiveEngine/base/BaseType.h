//
//  Rect.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Rect__
#define __LiveEngine__Rect__

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

namespace live
{
    struct Vertex
    {
        Vec3 position;
        Vec2 uv;
        Vec4 color;
    };

    class Shape
    {
    public:
        virtual const bool isContain(const Vec3&) const = 0;
    };

    class Triangle : public Shape
    {
    public:
        static constexpr ssize_t VERTEX_SIZE() { return 3; }
        Triangle() : vertices {
                                {{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}},
                                {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}},
                                {{1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}
                              } {}
        Triangle(const Vertex& v1,const Vertex& v2,const Vertex& v3) : vertices {v1, v2, v3} {}
        virtual const bool isContain(const Vec3& v) const
        {
            Vec3 c1 = (vertices[1].position - vertices[0].position).cross(v - vertices[1].position);
            Vec3 c2 = (vertices[2].position - vertices[1].position).cross(v - vertices[2].position);
            Vec3 c3 = (vertices[0].position - vertices[2].position).cross(v - vertices[0].position);
            
            float dot_12 = c1 * c2;
            float dot_13 = c1 * c3;
            
            return dot_12 >= 0 && dot_13 >= 0;
        }

        Vertex vertices[3];
    };

    /**
     *  v[0]-------v[2]
     *   |           |
     *  v[1]-------v[3]
     */                                                                                    
    class Rect : public Shape
    {
      public:
        Rect() : vertices {
            {{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}},
            {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}},
            {{1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}},
            {{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}}
        } {}
        Rect(const Vertex& v1,const Vertex& v2,const Vertex& v3, const Vertex& v4) : vertices {v1, v2, v3, v4} {}
        
        virtual const bool isContain(const Vec3& v) const
        {
            Vec3 c1 = (vertices[1].position - vertices[0].position).cross(v - vertices[1].position);
            Vec3 c2 = (vertices[3].position - vertices[1].position).cross(v - vertices[3].position);
            Vec3 c3 = (vertices[2].position - vertices[3].position).cross(v - vertices[2].position);
            Vec3 c4 = (vertices[0].position - vertices[2].position).cross(v - vertices[0].position);
            
            float dot_12 = c1 * c2;
            float dot_13 = c1 * c3;
            float dot_14 = c1 * c4;
            
            return dot_12 >= 0 && dot_13 >= 0 && dot_14 >= 0;
        }
        
        std::array<Triangle, 2> split() const
        {
            Triangle t1 = {vertices[0], vertices[1], vertices[2] };
            Triangle t2 = {vertices[2], vertices[1], vertices[3] };

            return {t1, t2};
        }
        
        Vertex vertices[4];
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

        template <typename... Args>
        Matrix4D(float head, Args&&... args)
            : m{head, static_cast<float>(args)...}
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
                float m11, m21, m31, m41,
                      m12, m22, m32, m42,
                      m13, m23, m33, m43,
                      m14, m24, m34, m44;
            };

            float m[ROW * COLUMN];
        };
        
        // コピーコンストラクタ
        Matrix4D(const Matrix4D& mat) noexcept { *this = mat; }
        Matrix4D& operator=(const Matrix4D& other) noexcept
        {
            if(this != &other)
            {
                memcpy(this->m, other.m, sizeof(float) * ROW * COLUMN);
            }
            
            return *this;
        }
    };

#include "Matrix4D.inl"
}

#endif /* defined(__LiveEngine__Rect__) */
