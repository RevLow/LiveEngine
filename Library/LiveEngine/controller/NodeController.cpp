//
//  Component.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/31.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "NodeController.h"

using namespace live;

void NodeController::on(const observer::Action& action)
{
    std::cout << "actiond by " << action.actionId << std::endl;
    if(action.actionId == 1)
    {
        const TransformAction& transaction = static_cast<const TransformAction&>(action);
        std::cout << "key: " << transaction.key << ", value: x=" << transaction.value.x() << ", y=" << transaction.value.y() << std::endl;
    }
}