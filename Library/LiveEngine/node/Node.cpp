//
//  Node.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/20.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Node.h"
#include "../controller/NodeController.h"

using namespace live;

namespace {
    enum ACTION_KEY
    {
        TRANSLATION = 1,
        ROTATION = 2,
        SCALE = 3
    };
}


Node::Node()
    : _viewMatrix(Matrix4D::Identity()), _dirty(false),
      _position(0.0f, 0.0f, 0.0f), _rotation(0.0f, 0.0f, 0.0f),
      _scale(1.0f, 1.0f, 1.0f)
{
}

void Node::addChild(std::unique_ptr<Node> node)
{
    if (node != nullptr)
    {
        _child.emplace_back(std::move(node));
    }
}

void Node::traversal(const live::Visitor& visitor)
{
    std::sort(
        _child.begin(), _child.end(),
        [](const std::unique_ptr<Node>& lhs, const std::unique_ptr<Node>& rhs) {
            return lhs->_layerOrder < rhs->_layerOrder;
        });

    auto it = _child.begin();
    for (; it != _child.end(); it++)
    {
        if ((*it)->_layerOrder >= _layerOrder)
            break;
        (*it)->traversal(visitor);
    }

    drawCall(visitor);

    for (; it != _child.end(); it++)
    {
        (*it)->traversal(visitor);
    }
}

void Node::drawCall(const live::Visitor& visitor) {}

#pragma mark TRANSFORMATION

void Node::transform(Matrix4D&& mat)
{
    _viewMatrix = std::move(mat);
}

void Node::translate(const Vec3& pos)
{
    _position = pos;
    TransformAction action(ACTION_KEY::TRANSLATION, _position);
    notifyAll(action);
    _dirty = true;
}

void Node::translate(Vec3&& pos)
{
    _position = std::move(pos);
    TransformAction action(ACTION_KEY::TRANSLATION, _position);
    notifyAll(action);
    _dirty = true;
}

void Node::translateX(float value)
{
    translate({value, _position.y(), _position.z()});
}
void Node::translateY(float value)
{
    translate({_position.x(), value, _position.z()});
}
void Node::translateZ(float value)
{
    translate({_position.x(), _position.y(), value});
}

void Node::rotate(const Vec3& r)
{
    _rotation = r;
    TransformAction action(ACTION_KEY::ROTATION, _rotation);
    notifyAll(action);
    _dirty = true;
}

void Node::rotate(Vec3&& r)
{
    _rotation = std::move(r);
    TransformAction action(ACTION_KEY::ROTATION, _rotation);
    notifyAll(action);
    _dirty = true;
}


void Node::rotateX(float value)
{
    rotate({value, _rotation.y(), _rotation.z()});
}
void Node::rotateY(float value)
{
    rotate({_rotation.x(), value, _rotation.z()});
}
void Node::rotateZ(float value)
{
    rotate({_rotation.x(), _rotation.y(), value});
}

void Node::scale(const Vec3& s)
{
    _scale = s;
    TransformAction action(ACTION_KEY::SCALE, _scale);
    notifyAll(action);
    _dirty = true;
}

void Node::scale(Vec3&& s)
{
    _scale = std::move(s);
    TransformAction action(ACTION_KEY::SCALE, _scale);
    notifyAll(action);
    _dirty = true;
}

void Node::scaleX(float value) { scale({value, _scale.y(), _scale.z()}); }
void Node::scaleY(float value) { scale({_scale.x(), value, _scale.z()}); }
void Node::scaleZ(float value) { scale({_scale.x(), _scale.y(), value}); }
