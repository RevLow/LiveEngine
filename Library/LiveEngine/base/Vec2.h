//
//  Vec2.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/04.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Vec2__
#define __LiveEngine__Vec2__

namespace live
{
    struct Vec2
    {
        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        float operator*(const Vec2& other) const;
        Vec2 operator+=(const Vec2& other);
        Vec2 operator-=(const Vec2& other);
        bool isZero() const;
        float u;
        float v;
    };
    

}


#endif /* defined(__LiveEngine__Vec2__) */
