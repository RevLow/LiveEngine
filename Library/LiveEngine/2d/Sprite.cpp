//
//  Sprite.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/18.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Sprite.h"
#include "../render/command/TriangleRenderCommand.h"

using namespace live;

void Sprite::traversal(const live::Matrix4D &parentMatrix, const live::Visitor& visitior)
{
    Node::traversal(parentMatrix, visitior);
}

void Sprite::drawCall(const live::Visitor &visitor)
{
    TriangleRenderCommand cmd(bounds.split(), texture.lock());
}