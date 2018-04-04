//
//  Vec4.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/04.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Vec4.h"

using namespace live;

float Vec4::operator*(const live::Vec4 &other) const
{
    return this->x * other.x +
           this->y * other.y +
           this->z * other.z +
           this->w * other.w;
}

Vec4 Vec4::operator+(const live::Vec4 &other) const
{
    return { this->x + other.x,
             this->y + other.y,
             this->z + other.z,
             this->w + other.w };
}


Vec4 Vec4::operator-(const live::Vec4 &other) const
{
    return { this->x - other.x,
             this->y - other.y,
             this->z - other.z,
             this->w - other.w };
}

Vec4 Vec4::operator+=(const live::Vec4 &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    this->w += other.w;

    return *this;
}

Vec4 Vec4::operator-=(const live::Vec4 &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    this->w -= other.w;

    return *this;
}

bool Vec4::isZero() const
{
    return this->x != 0 &&
           this->y != 0 &&
           this->z != 0 &&
           this->w != 0;
}