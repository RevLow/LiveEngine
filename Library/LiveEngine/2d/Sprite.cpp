//
//  Sprite.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/18.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Sprite.h"
#include "../render/command/TriangleRenderCommand.h"

using namespace live;

Sprite::Sprite(const std::string& filePath)
{
    texture = TextureFactory::getInstance()->produceTexture(filePath);
    float width = texture.lock()->getImageWidth();
    float height = texture.lock()->getImageHeight();
    bounds = {
        {{0.0f, height, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{width, height, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{width, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}}
    };
}

Sprite::Sprite()
{
    bounds = {
        {{0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}}
    };
}

Sprite::Sprite(const std::string& filePath,  const std::array<Vec2, 4>&  uv)
{
    texture = TextureFactory::getInstance()->produceTexture(filePath);
    float width = texture.lock()->getImageWidth();
    float height = texture.lock()->getImageHeight();
    bounds = {
        {{width * uv[0].u, height * uv[0].v, 0.0f}, {uv[0].u, uv[0].v}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{width * uv[1].u, height * uv[1].v, 0.0f}, {uv[1].u, uv[1].v}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{width * uv[2].u, height * uv[2].v, 0.0f}, {uv[2].u, uv[2].v}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{width * uv[3].u, height * uv[3].v, 0.0f}, {uv[3].u, uv[3].v}, {1.0f, 1.0f, 1.0f, 1.0f}}
    };
}

void Sprite::traversal(const live::Matrix4D &parentMatrix, live::Visitor& visitior)
{
    Node::traversal(parentMatrix, visitior);
}

void Sprite::drawCall(const Matrix4D& modelMatrix, Visitor& visitor)
{
    std::unique_ptr<TriangleRenderCommand> cmd(new TriangleRenderCommand(bounds, texture.lock(), modelMatrix));
    visitor.pushRenderCommand(std::move(cmd));
}