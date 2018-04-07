//
//  TriangleRenderCommand.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/27.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__TriangleRenderCommand__
#define __LiveEngine__TriangleRenderCommand__

#include "RenderCommand.h"
#include "../../base/BaseType.h"
#include "../../2d/Texture2D.h"

namespace live {
    class TriangleRenderCommand : public RenderCommand
    {
    public:
        static constexpr ssize_t VerticesCount() { return 4; }
        static constexpr ssize_t IndexCount() { return 6; }
    public:
        TriangleRenderCommand(const Rect& boundingRect, std::shared_ptr<Texture2D> _texture, const Matrix4D& modelMatrix);
        virtual ~TriangleRenderCommand() = default;
        TriangleRenderCommand(TriangleRenderCommand&&) = default;
        TriangleRenderCommand& operator=(TriangleRenderCommand&&) = default;
        uint32_t getMaterialId() const { return materialId; }
        void useMaterial();

        Vertex* getVertices() { return vertices; }
        unsigned short* getIndices() { return indices; }
    private:
        uint32_t createMatrialId();
        std::weak_ptr<Texture2D> texture;
        uint32_t materialId;
        Matrix4D modelMatrix;
        Vertex vertices[TriangleRenderCommand::VerticesCount()];
        unsigned short indices[] = { 0, 1, 2,  3, 2, 1 };
    };
}

#endif /* defined(__LiveEngine__TriangleRenderCommand__) */
