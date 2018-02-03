#define PLUS(ELEM) ELEM+other.ELEM
#define MINUS(ELEM) ELEM-other.ELEM


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
    
    result.m11 = m11 * other.m11 + m12 * other.m21 + m13 * other.m31 + m14 * other.m41;
    result.m12 = m11 * other.m12 + m12 * other.m22 + m13 * other.m32 + m14 * other.m42;
    result.m13 = m11 * other.m13 + m12 * other.m23 + m13 * other.m33 + m14 * other.m43;
    result.m14 = m11 * other.m14 + m12 * other.m24 + m13 * other.m34 + m14 * other.m44;
    
    result.m21 = m21 * other.m11 + m22 * other.m21 + m23 * other.m31 + m24 * other.m41;
    result.m22 = m21 * other.m12 + m22 * other.m22 + m23 * other.m32 + m24 * other.m42;
    result.m23 = m21 * other.m13 + m22 * other.m23 + m23 * other.m33 + m24 * other.m43;
    result.m24 = m21 * other.m14 + m22 * other.m24 + m23 * other.m34 + m24 * other.m44;
    
    result.m31 = m31 * other.m11 + m32 * other.m21 + m33 * other.m31 + m34 * other.m41;
    result.m32 = m31 * other.m12 + m32 * other.m22 + m33 * other.m32 + m34 * other.m42;
    result.m33 = m31 * other.m13 + m32 * other.m23 + m33 * other.m33 + m34 * other.m43;
    result.m34 = m31 * other.m14 + m32 * other.m24 + m33 * other.m34 + m34 * other.m44;
    
    result.m41 = m41 * other.m11 + m42 * other.m21 + m43 * other.m31 + m44 * other.m41;
    result.m42 = m41 * other.m12 + m42 * other.m22 + m43 * other.m32 + m44 * other.m42;
    result.m43 = m41 * other.m13 + m42 * other.m23 + m43 * other.m33 + m44 * other.m43;
    result.m44 = m41 * other.m14 + m42 * other.m24 + m43 * other.m34 + m44 * other.m44;
    
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