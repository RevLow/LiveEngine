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
    class GLView : public Uncopyable
    {
      public:
        GLView(){};
        virtual ~GLView(){};

        DEFINE_DEFAULT_MOVE_CONSTRUCTOR(GLView)
    };
}

#endif /* defined(__LiveEngine__GLView__) */
