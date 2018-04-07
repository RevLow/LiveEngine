//
//  UpdateTask.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/10.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__UpdateTask__
#define __LiveEngine__UpdateTask__

#include "ITask.h"

namespace live
{
    class UpdateTask final : public ITask
    {
      public:
        UpdateTask() = default;
        virtual void run() override;

        UpdateTask(UpdateTask&&) = default;
        UpdateTask& operator=(UpdateTask&&) = default;
    };
}

#endif /* defined(__LiveEngine__UpdateTask__) */
