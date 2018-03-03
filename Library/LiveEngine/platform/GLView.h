//
//  GLView.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__GLView__
#define __LiveEngine__GLView__

#include "../base/Uncopyable.h"

namespace live
{
    class GLView
    {
      public:
        GLView(){};
        virtual ~GLView(){};

        GLView(GLView&&) = default;
        GLView& operator=(GLView&&) = default;
    };
}

#endif /* defined(__LiveEngine__GLView__) */
