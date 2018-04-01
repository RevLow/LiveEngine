//
//  Visitor.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/21.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Visitor__
#define __LiveEngine__Visitor__

#include "../base/RenderQueue.h"

namespace live {
    class Visitor
    {
    public:
        void pushRenderCommand(std::unique_ptr<TriangleRenderCommand> cmd);
    private:
        RenderGroup group;
    };
}


#endif /* defined(__LiveEngine__Visitor__) */
