//
//  Node.cpp
//  LiveEngine
//
//  Created by Tetsushi Haresaku on 2018/09/20.
//  Copyright © 2018年 RevLow. All rights reserved.
//

#include "Node.hpp"

using namespace live;

void Node::addChild(live::NodePtr node)
{
    node->m_parent = std::make_shared<Node>(this);
    m_children.emplace_back(node);
}

void Node::updateMatrix()
{
    if(m_dirty == false) return;
    

    m_dirty = false;
}

void Node::setPosition(const Vec3& position)
{
    m_dirty = true;
}

void Node::setRotation(const Vec3& rotation)
{
    m_dirty = true;
}

void Node::setScale(const Vec3& scale)
{
    m_dirty = true;
}
