//
//  RenderQueue.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/26.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef LiveEngine_RenderQueue_h
#define LiveEngine_RenderQueue_h

#include "../render/command/TriangleRenderCommand.h"
#include "../render/Material.h"

namespace live
{
    class RenderQueue
    {
    public:
        RenderQueue(std::unique_ptr<TriangleRenderCommand>& cmd) {};
        ~RenderQueue();
        RenderQueue(RenderQueue&& other)
        {
            *this = std::move(other);
        }
        RenderQueue& operator=(RenderQueue&& other) noexcept
        {
            if(&other != this)
            {
                this->material = std::move(other.material);
                for(std::unique_ptr<TriangleRenderCommand>& cmd : other.queue)
                {
                    this->queue.emplace_back(std::move(cmd));
                }
            }
            return *this;
        }
        void pushQueue(std::unique_ptr<TriangleRenderCommand> cmd);
        bool isSameMaterialId(uint32_t materialId);

        std::vector<std::unique_ptr<TriangleRenderCommand>> queue;
        std::unique_ptr<Material> material;
    };
    
    using RenderGroup = std::vector<std::unique_ptr<RenderQueue>>;
}

#endif
