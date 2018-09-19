//
//  Application.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Application__
#define __LiveEngine__Application__

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
      private:
        Application();

        std::unique_ptr<GLView> _glview;
    };
}

#endif /* defined(__LiveEngine__Application__) */
