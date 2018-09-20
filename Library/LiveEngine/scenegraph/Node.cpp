//
//  Node.cpp
//  LiveEngine
//
//  Created by Tetsushi Haresaku on 2018/09/20.
//  Copyright © 2018年 RevLow. All rights reserved.
//

#include "Node.hpp"

using namespace live;

void Node::addChild(const live::NodePtr& node)
{
    //m_children.emplace_back(std::move(node));
}

void Node::update()
{
    if(m_dirty == false) return;
    

    m_dirty = false;
}

void Node::draw()
{
    
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
