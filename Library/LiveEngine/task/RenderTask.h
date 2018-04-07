//
//  RenderTask.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/14.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__RenderTask__
#define __LiveEngine__RenderTask__

#include "ITask.h"

namespace live
{
    class RenderTask : public ITask
    {
      public:
        virtual void run() const;
        virtual void run();
    };
}

#endif /* defined(__LiveEngine__RenderTask__) */
