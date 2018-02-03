namespace {
    template<int NN, typename TT>
    struct plus
    {
        inline static void f(TT& dst, const TT& src, const TT& other)
        {
            dst.v[NN-1] = src.v[NN - 1] + other.v[NN - 1];
            plus<NN - 1, TT>::f(dst, other);
        }
    };
    template<typename TT>
    struct plus<0, TT>
    {
        inline static void f(TT& dst, const TT& src, const TT& other) {}
    };
    
    template<int NN, typename TT>
    struct minus
    {
        inline static void f(TT& dst, const TT& src, const TT& other)
        {
            dst.v[NN-1] = src.v[NN - 1] - other.v[NN - 1];
            minus<NN - 1, TT>::f(dst, other);
        }
    };
    template<typename TT>
    struct minus<0, TT>
    {
        inline static void f(TT& dst, const TT& src, const TT& other) {}
    };
    
    template<int NN, typename TT>
    struct dot
    {
        inline static float f(const TT& src, const TT& other)
        {
            return src.v[NN - 1] * other.v[NN - 1] + dot<NN-1, TT>(src, other);
        }
    };
    template<typename TT>
    struct dot<0, TT>
    {
        inline static float f(const TT& src, const TT& other)
        {
            return 0.0f;
        }
    };
}

template<int N, typename T>
inline T _Vec_<N, T>::operator+(const T& other) const
{
    T vec;
    plus<N, T>::f(vec, *this, other);
    return vec;
}

template<int N, typename T>
inline T _Vec_<N, T>::operator-(const T &other) const
{
    T vec;
    minus<N, T>::f(vec, *this, other);
    return vec;
}

template<int N, typename T>
inline float _Vec_<N, T>::operator*(const T &other) const
{
    return dot<N, T>::f(*this, other);
}


inline Vec3 Vec3::cross(const live::Vec3 &other) const
{
    Vec3 vec;
    
    vec.x = y * other.z - z * other.y;
    vec.y = z * other.x - x * other.z;
    vec.z = x * other.y - y * other.x;

    return vec;
}
