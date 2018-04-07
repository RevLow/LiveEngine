//
//  RenderTask.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/14.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "RenderTask.h"

using namespace live;

RenderTask::RenderTask()
: vao(std::unique_ptr<VAO>(new VAO()))
, filledVertex(0)
, filledIndex(0)
{}

void RenderTask::run()
{
    const RenderGroup& renderGroup = Application::getInstance()->getRenderGroup();
    std::vector<TriangleRenderCommandPtrReference> batchedCommand;
    for (const std::unique_ptr<RenderQueue>& renderQueue : renderGroup )
    {
        for(const std::unique_ptr<TriangleRenderCommand>& cmd : renderQueue->queue)
        {
            fillVerticesAndIndices(cmd);
            batchedCommand.emplace_back(cmd);
        }
    }

    rendering(batchedCommand);
    clean();
}

void RenderTask::fillVerticesAndIndices(const std::unique_ptr<TriangleRenderCommand>& cmd)
{
    Vertex* vptr = vao->getVbo()->getVertsPtr();
    memcpy(vptr + filledVertex,
           cmd->getVertices(),
           sizeof(Vertex) * TriangleRenderCommand::VerticesCount());

    for(ssize_t i = 0; i < TriangleRenderCommand::VerticesCount(); i++)
    {
        Vertex* vertex = &vptr[i + filledVertex];
        Vec3* position = &vertex->position;

        // new_positionは一時的な変数なので右辺値参照型で受け取り、
        // positionの各要素に代入していく
        Vec4&& new_position = cmd->getModelMatrix() * *position;
        position->x = new_position.x;
        position->y = new_position.y;
        position->z = new_position.z;
    }

    const unsigned short* indices = cmd->getIndices();
    GLushort* indicesPtr = vao->getVbo()->getIndicesPtr();
    for (ssize_t i = 0; i < TriangleRenderCommand::IndexCount(); i++)
    {
        indicesPtr[i + filledIndex] = filledVertex + indices[i];
    }

    filledVertex += TriangleRenderCommand::VerticesCount();
    filledIndex += TriangleRenderCommand::IndexCount();
}

void RenderTask::rendering(std::vector<TriangleRenderCommandPtrReference>& batchedCommand)
{
    uint32_t lastMaterialId = 0;
    ssize_t indexCount = 0, startIndex = 0;
    // 貯めていた頂点バッファをGPUに転送
    vao->bind(filledVertex, filledIndex);

    for(std::unique_ptr<TriangleRenderCommand>& cmd : batchedCommand)
    {
        indexCount += cmd->IndexCount();
        
        // 最後のマテリアルIDと違うなら、マテリアルを有効化
        // cmd->useMaterial();
        // vao->draw(indexCount, startIndex);
    }

    vao->unbind();
}


void RenderTask::clean()
{
    filledVertex = 0;
    filledIndex = 0;
}