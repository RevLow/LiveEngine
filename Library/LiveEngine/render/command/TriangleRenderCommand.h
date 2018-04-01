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
        TriangleRenderCommand(const std::array<Triangle, 2>& _triangles, std::shared_ptr<Texture2D> _texture, const Matrix4D& modelMatrix);
        virtual ~TriangleRenderCommand() = default;
        TriangleRenderCommand(TriangleRenderCommand&&) = default;
        TriangleRenderCommand& operator=(TriangleRenderCommand&&) = default;
        virtual void execute() override;
        uint32_t getMaterialId() const { return materialId; }
    private:
        std::array<Triangle, 2> triangles;
        std::weak_ptr<Texture2D> texture;
        uint32_t materialId;
        Matrix4D modelMatrix;
    };
}

#endif /* defined(__LiveEngine__TriangleRenderCommand__) */
