//
//  UpdateTask.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/10.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "UpdateTask.h"
#include "Application.h"

using namespace live;

void UpdateTask::run() const
{
    // レンダーツリーを深さ優先探索で見ていき、renderコマンドを発行
    Application::getInstance()->resetRenderGroup();
    /*
     const Level& level = Application::getInstance()->popLevelStack()
     level->traverse();
     */
}
