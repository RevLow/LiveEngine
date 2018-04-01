//
//  UpdateTask.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/10.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "UpdateTask.h"
#include "Application.h"
#include "../base/Visitor.h"

using namespace live;

void UpdateTask::run() const
{
    Application::getInstance()->resetRenderGroup();
    Visitor visitor;
    std::stack<std::unique_ptr<Scene>>& sceneStack = Application::getInstance()->getSceneStack();

    if (sceneStack.empty()) {
        return;
    }

    std::unique_ptr<Scene>& topScene = sceneStack.top();
    topScene->startTraversal(visitor);

    // visitorにはRenderCommandが入っている
}
