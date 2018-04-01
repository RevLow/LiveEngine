//
//  Application.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Application__
#define __LiveEngine__Application__

#include "../task/ITask.h"
#include "../node/Scene.h"
#include "../base/Uncopyable.h"
#include "GLView.h"

namespace live
{
    class Application : Uncopyable<Application>
    {
        DEFINE_SINGLETON(Application)
      public:
        virtual ~Application() = default;
        void initGLView(GLView* glview);
        void update(float delta);
        void resetRenderGroup();
        void pushRenderQueue(RenderQueue&& queue);
        std::stack<std::unique_ptr<Scene>>& getSceneStack() { return _sceneStack; };
        const RenderGroup& getRenderGroup() const { return _renderGroup; }
      private:
        Application();

        std::unique_ptr<GLView> _glview;
        std::vector<std::unique_ptr<ITask>> _tasks;
        std::stack<std::unique_ptr<Scene>> _sceneStack;
        RenderGroup _renderGroup;
    };
}

#endif /* defined(__LiveEngine__Application__) */
