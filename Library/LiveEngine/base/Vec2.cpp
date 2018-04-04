//
//  Vec2.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/04.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Vec2.h"

using namespace live;

float Vec2::operator*(const live::Vec2 &other) const
{
    return this->u * other.u + this->v * other.v;
}

Vec2 Vec2::operator+(const live::Vec2 &other) const
{
    return { this->u + other.u,
             this->v + other.v };
}


Vec2 Vec2::operator-(const live::Vec2 &other) const
{
    return { this->u - other.u,
             this->v - other.v };
    
}

Vec2 Vec2::operator+=(const live::Vec2 &other)
{
    this->u += other.u;
    this->v += other.v;

    return *this;
}

Vec2 Vec2::operator-=(const live::Vec2 &other)
{
    this->u -= other.u;
    this->v -= other.v;
    
    return *this;
}

bool Vec2::isZero() const
{
    return this->u != 0 && this->v != 0;
}