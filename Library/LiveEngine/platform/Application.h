//
//  Application.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Application__
#define __LiveEngine__Application__

#include "../render/command/RenderCommand.h"
#include "../task/ITask.h"
#include "GLView.h"

namespace live
{
    class Application : public Uncopyable
    {
        DEFINE_SINGLETON(Application)
      public:
        using RenderQueue = std::vector<std::unique_ptr<RenderCommand>>;
        using RenderGroup = std::vector<RenderQueue>;

      public:
        void initGLView(GLView* glview);
        void update(float delta);
        void resetRenderGroup();
        // RenderQueueはコピーコストがかかるのでmoveで明示的に渡せるように右辺値参照のみとるようにする
        void pushRenderQueue(RenderQueue&& queue);
        
        virtual ~Application() = default;

      private:
        Application();

        std::unique_ptr<GLView> _glview;
        std::vector<std::unique_ptr<ITask>> _tasks;
        RenderGroup _renderGroup;
    };
}

#endif /* defined(__LiveEngine__Application__) */
