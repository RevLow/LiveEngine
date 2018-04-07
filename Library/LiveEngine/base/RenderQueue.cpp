//
//  RenderQueue.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/07.
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
