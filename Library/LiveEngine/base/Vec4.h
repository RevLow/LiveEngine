//
//  Vec4.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/04.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Vec4__
#define __LiveEngine__Vec4__

namespace live
{
    struct Vec4
    {
        Vec4 operator+(const Vec4& other) const;
        Vec4 operator-(const Vec4& other) const;
        float operator*(const Vec4& other) const;
        Vec4 operator+=(const Vec4& other);
        Vec4 operator-=(const Vec4& other);
        bool isZero() const;

        float x;
        float y;
        float z;
        float w;
    };
}

#endif /* defined(__LiveEngine__Vec4__) */
