//
//  ITask.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__ITask__
#define __LiveEngine__ITask__

#include "../base/Uncopyable.h"

namespace live
{
    class ITask : Uncopyable
    {
      public:
        ITask() = default;
        virtual ~ITask(){};
        virtual void run() const = 0;

        DEFINE_DEFAULT_MOVE_CONSTRUCTOR(ITask)
    };
}

#endif /* defined(__LiveEngine__ITask__) */
