//
//  Vec3.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/04.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Vec3.h"

using namespace live;

Vec3 Vec3::cross(const live::Vec3 &other) const
{
    Vec3 vec;
    
    vec.x = y * other.z - z * other.y;
    vec.y = z * other.x - x * other.z;
    vec.z = x * other.y - y * other.x;

    return vec;
}

float Vec3::operator*(const live::Vec3 &other) const
{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

Vec3 Vec3::operator+(const live::Vec3 &other) const
{
    return { this->x + other.x,
             this->y + other.y,
             this->z + other.z };
}


Vec3 Vec3::operator-(const live::Vec3 &other) const
{
    return { this->x - other.x,
             this->y - other.y,
             this->z - other.z };
}

Vec3 Vec3::operator+=(const live::Vec3 &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;

    return *this;
}

Vec3 Vec3::operator-=(const live::Vec3 &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    
    return *this;
}

bool Vec3::isZero() const
{
    return this->x != 0 && this->y != 0 && this->z != 0;
}