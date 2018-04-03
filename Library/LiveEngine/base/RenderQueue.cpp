//
//  RenderQueue.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/26.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "RenderQueue.h"

using namespace live;

RenderQueue::~RenderQueue()
{
    if(!queue.empty())
    {
        std::vector<std::unique_ptr<TriangleRenderCommand>>().swap(queue);
    }
}

void RenderQueue::pushQueue(std::unique_ptr<TriangleRenderCommand> cmd)
{
    queue.emplace_back(std::move(cmd));
}

bool RenderQueue::isSameMaterialId(uint32_t materialId)
{
    return materialId == this->material->getMaterialId();
}