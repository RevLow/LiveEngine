#define PLUS(ELEM) ELEM+other.ELEM
#define MINUS(ELEM) ELEM-other.ELEM

namespace {
    template<int R, int C, int N>
    struct multiple{
        inline static float f(const Matrix4D& src, const Matrix4D& other)
        {
            constexpr int NN = N-1;
            return src.m[R * Matrix4D::COLUMN + NN] * other.m[NN * Matrix4D::COLUMN + C] + multiple<R, C, NN>::f(src, other);
        }
    };
    template<int R, int C>
    struct multiple<R, C, 0> {
        inline static float f(const Matrix4D& src, const Matrix4D& other) { return 0.0f; }
    };
    
    template<int R, int C>
    struct assign{
        inline static void f(Matrix4D& dst, const Matrix4D& src, const Matrix4D& other)
        {
            constexpr int RR = R - 1;
            constexpr int CC = C - 1;
            
            dst.m[RR * Matrix4D::COLUMN + CC] = multiple<RR, CC, Matrix4D::COLUMN>::f(src, other);
            assign<R, CC>::f(dst, src, other);
        }
    };
    
    template<int R>
    struct assign<R, 0>{
        inline static void f(Matrix4D&, const Matrix4D&, const Matrix4D&)
        {
            
        }
    };
}


inline Matrix4D Matrix4D::operator-() const
{
    return {
        -m11, -m12, -m13, -m14,
        -m21, -m22, -m23, -m24,
        -m31, -m32, -m33, -m34,
        -m41, -m42, -m43, -m44
    };
};

inline Matrix4D Matrix4D::operator+(const Matrix4D& other) const
{
    
    return {
        PLUS(m11), PLUS(m12), PLUS(m13), PLUS(m14),
        PLUS(m21), PLUS(m22), PLUS(m23), PLUS(m24),
        PLUS(m31), PLUS(m32), PLUS(m33), PLUS(m34),
        PLUS(m41), PLUS(m42), PLUS(m43), PLUS(m44)
    };
    
}

inline Matrix4D Matrix4D::operator-(const Matrix4D& other) const
{
    return {
        MINUS(m11), MINUS(m12), MINUS(m13), MINUS(m14),
        MINUS(m21), MINUS(m22), MINUS(m23), MINUS(m24),
        MINUS(m31), MINUS(m32), MINUS(m33), MINUS(m34),
        MINUS(m41), MINUS(m42), MINUS(m43), MINUS(m44)
    };
}

inline Matrix4D Matrix4D::operator*(const Matrix4D& other) const
{
    Matrix4D result;

    assign<1, COLUMN>::f(result, *this, other);
    assign<2, COLUMN>::f(result, *this, other);
    assign<3, COLUMN>::f(result, *this, other);
    assign<4, COLUMN>::f(result, *this, other);
    
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


#undef MINUS
#undef PLUS