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
#include "FileManager.h"
#include "GLView.h"

namespace live
{
    class Application
    {
    public:
        static Application& instance()
        {
            return m_application;
        }

        void initGLView(GLView* glview);
        void update(float delta);
        FileManager& getFileManager() { return m_file_manager; }
    private:
        static Application m_application;
        FileManager m_file_manager;
        std::unique_ptr<GLView> m_glview;

        Application();
    };
}

#endif /* defined(__LiveEngine__Application__) */
