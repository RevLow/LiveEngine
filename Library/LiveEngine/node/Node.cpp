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

Node::Node()
    : _modelMatrix(Matrix4D::Identity()), _dirty(false),
      _position(0.0f, 0.0f, 0.0f), _rotation(0.0f, 0.0f, 0.0f),
      _scale(1.0f, 1.0f, 1.0f), _anchorPoint(0.0f, 0.0f, 0.0f)
{
}

Node::~Node()
{
    std::vector<std::shared_ptr<Node>>().swap(_child);
}

void Node::addChild(std::shared_ptr<Node> node)
{
    if (node != nullptr)
    {
        _child.emplace_back(node);
    }
}

void Node::traversal(const Matrix4D& parentMatrix, const Visitor& visitor)
{
    if(_dirty)
    {
        computeModelMatrix();
    }
    
    Matrix4D m = parentMatrix * _modelMatrix;
    
    std::sort(
        _child.begin(), _child.end(),
        [](const std::shared_ptr<Node>& lhs, const std::shared_ptr<Node>& rhs) {
            return lhs->_layerOrder < rhs->_layerOrder;
        });

    auto it = _child.begin();
    for (; it != _child.end(); it++)
    {
        if ((*it)->_layerOrder >= _layerOrder)
            break;
        (*it)->traversal(m, visitor);
    }

    drawCall(visitor);

    for (; it != _child.end(); it++)
    {
        (*it)->traversal(m, visitor);
    }
}

void Node::drawCall(const live::Visitor& visitor) {
    if (_dirty)
    {
        
    }
}

#pragma mark TRANSFORMATION

void Node::transform(Matrix4D&& mat)
{
    _modelMatrix = std::move(mat);
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

void Node::anchorPoint(const Vec3& anchorPoint)
{
    _anchorPoint = anchorPoint;
    TransformAction action(ACTION_KEY::ANCHOR, _anchorPoint);
    notifyAll(action);
    _dirty = true;
}

void Node::anchorPoint(Vec3&& anchorPoint)
{
    _anchorPoint = std::move(anchorPoint);
    TransformAction action(ACTION_KEY::ANCHOR, _anchorPoint);
    notifyAll(action);
    _dirty = true;
}

void Node::anchorPointX(float value) { anchorPoint({value, _anchorPoint.y(), _anchorPoint.z()}); }
void Node::anchorPointY(float value) { anchorPoint({_anchorPoint.x(), value, _anchorPoint.z()}); }
void Node::anchorPointZ(float value) { anchorPoint({_anchorPoint.x(), _anchorPoint.y(), value}); }

/**
 *  モデル行列の計算
 *  アンカーポイントを起点にした座標 -> ノードの起点座標系(0, 0)に変換
 */
void Node::computeModelMatrix()
{
    float m14 = _position.x();
    float m24 = _position.y();
    float m34 = _position.z();

    if (!_anchorPoint.isZero())
    {
        m14 -= _scale.x() * _anchorPoint.x();
        m24 -= _scale.y() * _anchorPoint.y();
        m34 -= _scale.z() * _anchorPoint.z();
    }

    
    float cosX = cosf(_rotation.x());
    float sinX = sinf(_rotation.x());
    
    float cosY = cosf(_rotation.y());
    float sinY = sinf(_rotation.y());
    
    float cosZ = cosf(_rotation.z());
    float sinZ = sinf(_rotation.z());
    
    float m11 = cosX * cosY * cosZ - sinX * sinZ,
          m12 = -cosX * cosY * sinZ - sinX * cosZ,
          m13 = cosX * sinY,
          m21 = sinX * cosY * cosZ + cosX * sinZ,
          m22 = -sinX * cosY * sinZ + cosX * cosZ,
          m23 = sinX * sinY,
          m31 = -sinY * cosZ,
          m32 = sinY * sinZ,
          m33 = cosY;

    m11 *= _scale.x(), m21 *= _scale.x(), m31 *= _scale.x();
    m12 *= _scale.y(), m22 *= _scale.y(), m32 *= _scale.y();
    m13 *= _scale.z(), m23 *= _scale.z(), m33 *= _scale.z();
    
    _modelMatrix = {
        m11, m21, m31, 0.0f,
        m12, m22, m32, 0.0f,
        m13, m23, m33, 0.0f,
        m14, m24, m34, 1.0f
    };
}
