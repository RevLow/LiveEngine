//
//  Component.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/31.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Component__
#define __LiveEngine__Component__

#include "../base/Uncopyable.h"
#include "../base/observer/Observer.h"

namespace live {
    class NodeController : public Uncopyable<NodeController>, public observer::Observer
    {
    public:
        virtual void notify() override
        {
            std::cout << "Notifyed" << std::endl;
        }
    };
}

#endif /* defined(__LiveEngine__Component__) */
