//
//  RenderCommand.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/11.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__RenderCommand__
#define __LiveEngine__RenderCommand__

#include "../../base/Uncopyable.h"

namespace live
{
    class RenderCommand
    {
      public:
        RenderCommand() = default;
        virtual ~RenderCommand() = default;

        DEFINE_DEFAULT_MOVE_CONSTRUCTOR(RenderCommand);
    };
}

#endif /* defined(__LiveEngine__RenderCommand__) */
