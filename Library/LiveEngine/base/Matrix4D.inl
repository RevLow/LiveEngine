#define PLUS(ELEM) ELEM+other.ELEM
#define MINUS(ELEM) ELEM-other.ELEM

namespace __MATRIX_OPERATION__ {
    template<int R, int C>
    struct Outer
    {
        static void f(Matrix4D& dst, const Matrix4D& src, const Matrix4D& other)
        {
            dst.m[Matrix4D::ROW * C + R] = Inner<0>::f(src, other);
            Outer<R, C+1>::f(dst, src, other);
        }
        
        template<int N, class U = void>
        struct Inner
        {
            static float f(const Matrix4D& src, const Matrix4D& other)
            {
                return src.m[Matrix4D::ROW * N + R] * other.m[Matrix4D::ROW * C + N] + Inner<N+1, U>::f(src, other);
            }
        };
        
        template<class U>
        struct Inner<4, U>
        {
            static float f(const Matrix4D& src, const Matrix4D& other)
            {
                return 0.0f;
            }
        };
    };
    
    template<int R>
    struct Outer<R, 4>
    {
        static void f(Matrix4D&,const Matrix4D&, const Matrix4D&) {}
    };
    

    template<int R>
    struct EntryCalc
    {
        static void f(Matrix4D& dst, const Matrix4D& src, const Matrix4D& other)
        {
            Outer<R, 0>::f(dst, src, other);
            EntryCalc<R+1>::f(dst, src, other);
        }
    };

    template<>
    struct EntryCalc<4>
    {
        static void f(Matrix4D&, const Matrix4D&, const Matrix4D&) {}
    };
}

inline Matrix4D Matrix4D::operator-() const
{
    return {
        -m11, -m21, -m31, -m41,
        -m12, -m22, -m32, -m42,
        -m13, -m23, -m33, -m43,
        -m14, -m24, -m34, -m44
    };
};

inline Matrix4D Matrix4D::operator+(const Matrix4D& other) const
{
    
    return {
        PLUS(m11), PLUS(m21), PLUS(m31), PLUS(m41),
        PLUS(m12), PLUS(m22), PLUS(m32), PLUS(m42),
        PLUS(m13), PLUS(m23), PLUS(m33), PLUS(m43),
        PLUS(m14), PLUS(m24), PLUS(m34), PLUS(m44)
    };
    
}

inline Matrix4D Matrix4D::operator-(const Matrix4D& other) const
{
    return {
        MINUS(m11), MINUS(m21), MINUS(m31), MINUS(m41),
        MINUS(m12), MINUS(m22), MINUS(m32), MINUS(m42),
        MINUS(m13), MINUS(m23), MINUS(m33), MINUS(m43),
        MINUS(m14), MINUS(m24), MINUS(m34), MINUS(m44)
    };
}

inline Matrix4D Matrix4D::operator*(const Matrix4D& other) const
{
    Matrix4D result;

    __MATRIX_OPERATION__::EntryCalc<0>::f(result, *this, other);

    return result;
}

inline Matrix4D& Matrix4D::operator+=(const Matrix4D& other)
{
    *this = *this + other;
    return *this;
}

inline Matrix4D& Matrix4D::operator-=(const Matrix4D& other)
{
    *this = *this - other;
    return *this;
}

inline Matrix4D& Matrix4D::operator*=(const Matrix4D& other)
{
    *this = *this * other;
    return *this;
}

inline Vec4 Matrix4D::operator*(const Vec3& vec) const
{
    float x = m[0] * vec.x() + m[4] * vec.y() + m[8] * vec.z() + m[12];
    float y = m[1] * vec.x() + m[5] * vec.y() + m[9] * vec.z() + m[13];
    float z = m[2] * vec.x() + m[6] * vec.y() + m[10] * vec.z() + m[14];
    float w = m[3] * vec.x() + m[7] * vec.y() + m[11] * vec.z() + m[15];

    return {x, y, z, w};
}

inline Vec4 Matrix4D::operator*(const Vec4& vec) const
{
    float x = m[0] * vec.x() + m[4] * vec.y() + m[8] * vec.z() + m[12] * vec.w();
    float y = m[1] * vec.x() + m[5] * vec.y() + m[9] * vec.z() + m[13] * vec.w();
    float z = m[2] * vec.x() + m[6] * vec.y() + m[10] * vec.z() + m[14] * vec.w();
    float w = m[3] * vec.x() + m[7] * vec.y() + m[11] * vec.z() + m[15] * vec.w();
    
    return {x, y, z, w};
}


#undef MINUS
#undef PLUS