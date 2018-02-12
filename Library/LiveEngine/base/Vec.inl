namespace {
    template<int N, int NN>
    struct plus
    {
        inline static void f(_Vec_<N>& dst, const _Vec_<N>& src, const _Vec_<N>& other)
        {
            dst._v[NN-1] = src._v[NN - 1] + other._v[NN - 1];
            plus<N, NN - 1>::f(dst, src, other);
        }
    };
    template<int N>
    struct plus<N, 0>
    {
        inline static void f(_Vec_<N>& dst, const _Vec_<N>& src, const _Vec_<N>& other) {}
    };
    
    template<int N, int NN>
    struct minus
    {
        inline static void f(_Vec_<N>& dst, const _Vec_<N>& src, const _Vec_<N>& other)
        {
            dst._v[NN-1] = src._v[NN - 1] - other._v[NN - 1];
            minus<N, NN - 1>::f(dst, src, other);
        }
    };
    template<int N>
    struct minus<N, 0>
    {
        inline static void f(_Vec_<N>& dst, const _Vec_<N>& src, const _Vec_<N>& other){}
    };
    
    template<int N, int NN>
    struct dot
    {
        inline static float f(const _Vec_<N>& src, const _Vec_<N>& other)
        {
            return src._v[NN - 1] * other._v[NN - 1] + dot<N, NN-1>::f(src, other);
        }
    };
    template<int N>
    struct dot<N, 0>
    {
        inline static float f(const _Vec_<N>& src, const _Vec_<N>& other)
        {
            return 0.0f;
        }
    };
}

template<int N>
template<typename DerivedClass>
inline DerivedClass _Vec_<N>::operator+(const DerivedClass& other) const
{
    _Vec_<N> vec;
    plus<N, N>::f(vec, *this, other);

    return vec;
}

template<int N>
template <typename DerivedClass>
inline DerivedClass _Vec_<N>::operator-(const DerivedClass &other) const
{
    _Vec_<N> vec;
    minus<N, N>::f(vec, *this, other);
    return vec;
}

template<int N>
inline float _Vec_<N>::operator*(const _Vec_<N> &other) const
{
    return dot<N, N>::f(*this, other);
}


inline Vec3 Vec3::cross(const live::Vec3 &other) const
{
    Vec3 vec;

    vec.setX(y() * other.z() - z() * other.y());
    vec.setY(z() * other.x() - x() * other.z());
    vec.setZ(x() * other.y() - y() * other.x());

    return vec;
}
