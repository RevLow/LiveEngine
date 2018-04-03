//
//  RenderCommand.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/11.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__RenderCommand__
#define __LiveEngine__RenderCommand__

namespace live
{
    class RenderCommand
    {
    public:
        RenderCommand() = default;
        virtual ~RenderCommand() = default;
        RenderCommand(RenderCommand&&) = default;
        RenderCommand& operator=(RenderCommand&&) = default;
    };
}

#endif /* defined(__LiveEngine__RenderCommand__) */
