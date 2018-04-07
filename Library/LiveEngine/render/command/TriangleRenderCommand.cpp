//
//  TriangleRenderCommand.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/27.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "TriangleRenderCommand.h"
#include "xxhash.h"

using namespace live;

TriangleRenderCommand::TriangleRenderCommand(const Rect& boundingRect, std::shared_ptr<Texture2D> _texture, const Matrix4D& _modelMatrix)
: texture(_texture)
, materialId(0)
, modelMatrix(_modelMatrix)
{
    memcpy(vertices, boundingRect.vertices, sizeof(Vertex) * VerticesCount());
    // todo: generate material id from shaderprogram and texture information
    materialId = createMatrialId();
}

uint32_t TriangleRenderCommand::createMatrialId()
{
    return 0;
    /*
     int glProgram = (int)_glProgramState-> getGLProgram()->getProgram();
     int intArray[4] = {
        glProgram,
        (int)texture.lock()->getTextureId(),
        (int)_blendType.src,
        (int)_blendType.dst
     }
     
     return XXH32((const void*)intArray, sizeof(intArray), 0);
     */
}