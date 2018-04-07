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

    std::vector<MaterialMap> materialQueue;
    for (const std::unique_ptr<RenderQueue>& renderQueue : renderGroup )
    {
        MaterialMap map = { 0, renderQueue->getMaterial() };
        for(const std::unique_ptr<TriangleRenderCommand>& cmd : renderQueue->getQueue())
        {
            fillVerticesAndIndices(cmd);
            map.indicesCount += TriangleRenderCommand::INDEX_COUNT;
        }
        materialQueue.emplace_back(map);
    }

    rendering(materialQueue);
    clean();
}

void RenderTask::fillVerticesAndIndices(const std::unique_ptr<TriangleRenderCommand>& cmd)
{
    Vertex* vptr = vao->getVbo()->getVertsPtr();
    memcpy(vptr + filledVertex,
           cmd->getVertices(),
           sizeof(Vertex) * TriangleRenderCommand::VERTICES_COUNT);

    for(ssize_t i = 0; i < TriangleRenderCommand::VERTICES_COUNT; i++)
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
    for (ssize_t i = 0; i < TriangleRenderCommand::INDEX_COUNT; i++)
    {
        indicesPtr[i + filledIndex] = filledVertex + indices[i];
    }

    filledVertex += TriangleRenderCommand::VERTICES_COUNT;
    filledIndex += TriangleRenderCommand::INDEX_COUNT;
}

void RenderTask::rendering(std::vector<MaterialMap>& batchedCommand)
{
    vao->bind(filledVertex, filledIndex);

    ssize_t offset = 0;
    for(MaterialMap& map : batchedCommand)
    {
        map.material->use();
        vao->draw(map.indicesCount, offset);
        offset += map.indicesCount;
    }

    vao->unbind();
}

void RenderTask::clean()
{
    filledVertex = 0;
    filledIndex = 0;
}