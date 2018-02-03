//
//  Node.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/20.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Node.h"

using namespace live;

void Node::addComponent(std::unique_ptr<Component>&& component)
{
    if (component != nullptr)
    {
        _components.emplace_back(std::move(component));
    }
}

void Node::addChild(std::unique_ptr<Node>&& node)
{
    if (node != nullptr)
    {
        _nodes.emplace_back(std::move(node));
    }
}

void Node::traversal(const live::Visitor& visitor)
{
    std::sort(_nodes.begin(), _nodes.end(),
    [](const std::unique_ptr<Node>& lhs, const std::unique_ptr<Node>& rhs)
    {
        return lhs->_layerOrder < rhs->_layerOrder;
    });
    
    auto it = _nodes.begin();
    for(;it != _nodes.end();it++)
    {
        if((*it)->_layerOrder >= _layerOrder) break;
        (*it)->traversal(visitor);
    }
    
    action(visitor);
    
    for (; it != _nodes.end(); it++)
    {
        (*it)->traversal(visitor);
    }
}

void Node::action(const live::Visitor& visitor)
{
    
}