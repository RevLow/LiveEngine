//
//  TriangleRenderCommand.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/07.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "TriangleRenderCommand.h"

using namespace live;

TriangleRenderCommand::TriangleRenderCommand(const Rect& boundingRect, std::shared_ptr<Texture2D> _texture, const Matrix4D& _modelMatrix)
: modelMatrix(_modelMatrix)
, indices { 0, 1, 2,  3, 2, 1 }
{
    memcpy(vertices, boundingRect.vertices, sizeof(Vertex) * VERTICES_COUNT);
}