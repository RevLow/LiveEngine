//
//  TriangleRenderCommand.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/27.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "TriangleRenderCommand.h"

using namespace live;

TriangleRenderCommand::TriangleRenderCommand(const std::array<Triangle, 2>& _triangles, std::shared_ptr<Texture2D> _texture)
: triangles(_triangles)
, texture(_texture)
, materialId(0)
{
    // todo: generate material id from shaderprogram and texture information
}

void TriangleRenderCommand::execute()
{
    
}