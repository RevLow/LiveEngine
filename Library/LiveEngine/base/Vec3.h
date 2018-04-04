//
//  Vec3.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/04.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Vec3__
#define __LiveEngine__Vec3__

namespace live
{
    struct Vec3
    {
        Vec3 operator+(const Vec3& other) const;
        Vec3 operator-(const Vec3& other) const;
        float operator*(const Vec3& other) const;
        Vec3 operator+=(const Vec3& other);
        Vec3 operator-=(const Vec3& other);
        bool isZero() const;
        Vec3 cross(const Vec3& other) const;

        float x;
        float y;
        float z;
    };
    
    
}


#endif /* defined(__LiveEngine__Vec3__) */
