//
//  Scene.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/21.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Scene__
#define __LiveEngine__Scene__

#include "Node.h"

namespace live {
    class Scene
    {
    public:
        Scene() : rootNode(new Node()) {};
        void startTraversal(Visitor& visitor)
        {
            Matrix4D m = Matrix4D::Identity();
            rootNode->traversal(m, visitor);
        }
    protected:
        void addChild(std::shared_ptr<Node> node)
        {
            rootNode->addChild(node);
        }
        std::unique_ptr<Node> rootNode;
    };
}

#endif /* defined(__LiveEngine__Scene__) */
