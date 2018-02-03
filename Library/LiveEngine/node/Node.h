//
//  Node.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/20.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Node__
#define __LiveEngine__Node__

#include "../base/Uncopyable.h"
#include "../components/Component.h"

namespace live
{
    class Visitor;
    class Node : public Uncopyable
    {
      public:
        virtual void addComponent(std::unique_ptr<Component>&& component) final;
        virtual void addChild(std::unique_ptr<Node>&& node) final;
        virtual void traversal(const Visitor& visitor);
        virtual void action(const Visitor& visitor);
      private:
        int _layerOrder;
        std::vector<std::unique_ptr<Node>> _nodes;
        std::vector<std::unique_ptr<Component>> _components;
    };
}

#endif /* defined(__LiveEngine__Node__) */
