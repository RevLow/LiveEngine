//
//  Application.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Application.h"
#include "../task/UpdateTask.h"

using namespace live;

Application::Application() : _glview(nullptr)
{
    _tasks.emplace_back(new UpdateTask);
}

void Application::initGLView(GLView* glview)
{
    _glview = std::unique_ptr<GLView>(glview);
}

void Application::update(float delta)
{
    if (!_tasks.empty())
    {
        for (const std::unique_ptr<ITask>& task : _tasks)
        {
            task->run();
        }
    }
}

void Application::resetRenderGroup()
{
    if (!_renderGroup.empty())
    {
        RenderGroup().swap(_renderGroup);
    }
}

void Application::pushRenderQueue(RenderQueue&& queue)
{
    _renderGroup.emplace_back(new RenderQueue(std::move(queue)));
}