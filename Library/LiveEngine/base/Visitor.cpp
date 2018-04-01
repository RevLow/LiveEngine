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
        RenderQueue queue(cmd);
        queue.pushQueue(std::move(cmd));
        group.emplace_back(queue);
    }
}