//
//  RenderTask.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/14.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__RenderTask__
#define __LiveEngine__RenderTask__

#include "ITask.h"
#include "VertexBuffer.h"
#include "RenderQueue.h"

namespace live
{
    class RenderTask : public ITask
    {
        struct MaterialMap
        {
            int indicesCount;
            std::unique_ptr<Material>& material;
        };
    public:
        RenderTask();
        virtual void run();
    private:
        void fillVerticesAndIndices(const std::unique_ptr<TriangleRenderCommand>& cmd);
        void rendering(std::vector<MaterialMap>& batchedCommand);
        void clean();
        std::unique_ptr<VAO> vao;
        int filledVertex;
        int filledIndex;
    };
}

#endif /* defined(__LiveEngine__RenderTask__) */
