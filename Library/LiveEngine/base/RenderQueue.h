//
//  RenderQueue.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/07.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__RenderQueue__
#define __LiveEngine__RenderQueue__

#include "Material.h"
#include "TriangleRenderCommand.h"

namespace live {
    class RenderQueue
    {
    public:
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
    private:
        std::unique_ptr<Material> material;
        std::vector<std::unique_ptr<TriangleRenderCommand>> queue;
    };

    using RenderGroup = std::vector<std::unique_ptr<RenderQueue>>;
}

#endif /* defined(__LiveEngine__RenderQueue__) */
