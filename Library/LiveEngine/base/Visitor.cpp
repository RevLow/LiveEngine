//
//  Visitor.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/21.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Visitor.h"

using namespace live;

void Visitor::pushRenderCommand(std::unique_ptr<TriangleRenderCommand> cmd)
{
    std::unique_ptr<RenderQueue>& lastQueue = group.back();
    if (lastQueue->isSameMaterialId(cmd->getMaterialId()))
    {
        lastQueue->pushQueue(std::move(cmd));
    }
    else
    {
        std::unique_ptr<RenderQueue> queue(new RenderQueue(cmd));
        queue->pushQueue(std::move(cmd));
        group.emplace_back(std::move(queue));
    }
}