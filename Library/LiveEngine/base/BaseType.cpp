//
//  BaseType.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/31.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "BaseType.h"

using namespace live;

/*
 以下のプログラムをテンプレートで実装
 
 for(int II=0, int SrcRow=0;II < 3;II++)
 {
    if(II == I) continue;
    for(int JJ=0, int SrcCol=0;JJ < 3;JJ++)
    {
        if(JJ == J) continue;
        dst.m[SrcRow * ROW + SrcCol] = src.m[II * ROW + JJ];
        SrcCol++;
    }
 
    SrcRow++;
 }
 */

namespace  {
    template<bool Cond, typename Then, typename Else>
    struct if_;
    
    template<typename Then, typename Else>
    struct if_<true, Then, Else>
    {
        typedef Then type;
    };
    
    template<typename Then, typename Else>
    struct if_<false, Then, Else>
    {
        typedef Else type;
    };
    
    template<int I, int J>
    struct is_same
    {
        static const bool value = I == J;
    };
    
    // I行J列を除外した小行列
    template<int I, int J>
    class SubMatrix
    {
        static constexpr uint8_t ROW = 3;
        static constexpr uint8_t COLUMN = 3;
        
        template<int II, int SrcRow>
        struct func1
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src)
            {
                if_<is_same<II, I>::value,
                    F1Success<II, SrcRow>, // continue
                    F1Fail<II, SrcRow>     // assign
                   >::type::f(dst, src);
            }
        };
        
        template <int SrcRow>
        struct func1<4, SrcRow>
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src) {}
        };
        
        template<int II, int SrcRow>
        struct F1Success
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src)
            {
                func1<II+1, SrcRow>::f(dst, src);
            }
        };
        
        template<int II, int SrcRow>
        struct F1Fail
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src)
            {
                func2<II, 0, SrcRow, 0>::f(dst, src);
                func1<II+1, SrcRow+1>::f(dst, src);
            }
        };
        
        template<int II, int JJ, int SrcRow, int SrcCol>
        struct func2
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src)
            {
                if_<is_same<JJ, J>::value,
                    F2Success<II, JJ, SrcRow, SrcCol>, // continue
                    F2Fail<II, JJ, SrcRow, SrcCol>     // assign
                    >::type::f(dst, src);
            }
        };
        
        template<int II, int SrcRow, int SrcCol>
        struct func2<II, 4, SrcRow, SrcCol>
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src){}
        };
        
        template<int II, int JJ, int SrcRow, int SrcCol>
        struct F2Success
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src)
            {
                func2<II, JJ+1, SrcRow, SrcCol>::f(dst, src);
            }
        };
        
        template<int II, int JJ, int SrcRow, int SrcCol>
        struct F2Fail
        {
            static void f(SubMatrix<I, J>& dst, const Matrix4D& src)
            {
                dst.m[SrcRow * ROW + SrcCol] = src.m[II * 4 + JJ];
                func2<II, JJ+1, SrcRow, SrcCol+1>::f(dst, src);
            }
        };
    public:
        static SubMatrix<I, J> create(const Matrix4D& src)
        {
            SubMatrix<I, J> dst;
            func1<0, 0>::f(dst, src);
            return dst;
        }
        
        constexpr float determinant() const
        {
            return    m[0] * (m[4] * m[8] - m[5] * m[7])
                    - m[1] * (m[3] * m[8] - m[5] * m[6])
                    + m[2] * (m[3] * m[7] - m[4] * m[6]);
        }

        float m[ROW * COLUMN];
    };
}

Matrix4D::Matrix4D() :
m { 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f }
{}
Matrix4D Matrix4D::inverse() const
{
    float A00 =  SubMatrix<0, 0>::create(*this).determinant() / determinant();
    float A01 = -SubMatrix<1, 0>::create(*this).determinant() / determinant();
    float A02 =  SubMatrix<2, 0>::create(*this).determinant() / determinant();
    float A03 = -SubMatrix<3, 0>::create(*this).determinant() / determinant();

    float A10 = -SubMatrix<0, 1>::create(*this).determinant() / determinant();
    float A11 =  SubMatrix<1, 1>::create(*this).determinant() / determinant();
    float A12 = -SubMatrix<2, 1>::create(*this).determinant() / determinant();
    float A13 =  SubMatrix<3, 1>::create(*this).determinant() / determinant();
    
    float A20 =  SubMatrix<0, 2>::create(*this).determinant() / determinant();
    float A21 = -SubMatrix<1, 2>::create(*this).determinant() / determinant();
    float A22 =  SubMatrix<2, 2>::create(*this).determinant() / determinant();
    float A23 = -SubMatrix<3, 2>::create(*this).determinant() / determinant();
    
    float A30 = -SubMatrix<0, 3>::create(*this).determinant() / determinant();
    float A31 =  SubMatrix<1, 3>::create(*this).determinant() / determinant();
    float A32 = -SubMatrix<2, 3>::create(*this).determinant() / determinant();
    float A33 =  SubMatrix<3, 3>::create(*this).determinant() / determinant();
    
    return { A00, A01, A02, A03,
             A10, A11, A12, A13,
             A20, A21, A22, A23,
             A30, A31, A32, A33 };
}


const float Matrix4D::determinant() const
{
    return   m11 * SubMatrix<0, 0>::create(*this).determinant()
           - m21 * SubMatrix<1, 0>::create(*this).determinant()
           + m31 * SubMatrix<2, 0>::create(*this).determinant()
           - m41 * SubMatrix<3, 0>::create(*this).determinant();
}