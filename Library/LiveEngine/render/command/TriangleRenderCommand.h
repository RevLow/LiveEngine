//
//  TriangleRenderCommand.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/07.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__TriangleRenderCommand__
#define __LiveEngine__TriangleRenderCommand__

#include "RenderCommand.h"
#include "../../base/BaseType.h"
#include "Texture2D.h"

namespace live {
    class TriangleRenderCommand
    {
    public:
        static constexpr ssize_t VERTICES_COUNT = 4;
        static constexpr ssize_t INDEX_COUNT = 6;
    public:
        TriangleRenderCommand(const Rect& boundingRect, std::shared_ptr<Texture2D> _texture, const Matrix4D& _modelMatrix);

        virtual ~TriangleRenderCommand() = default;
        TriangleRenderCommand(TriangleRenderCommand&&) = default;
        TriangleRenderCommand& operator=(TriangleRenderCommand&&) = default;
        
        Vertex* getVertices() { return vertices; }
        unsigned short* getIndices() { return indices; }
        Matrix4D& getModelMatrix() { return modelMatrix; }
    private:
        Matrix4D modelMatrix;
        Vertex vertices[VERTICES_COUNT];
        unsigned short indices[INDEX_COUNT];
    };
}

#endif /* defined(__LiveEngine__TriangleRenderCommand__) */
