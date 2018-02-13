//
//  Component.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/31.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "NodeController.h"

using namespace live;

namespace  {
    void dispatch(NodeController* self, uint8_t actionKey, const Vec3& value)
    {
        switch (actionKey)
        {
            case live::ACTION_KEY::TRANSLATION:
                self->onNodeTranslate(value);
                break;
            case live::ACTION_KEY::ROTATION:
                self->onNodeRation(value);
                break;
            case live::ACTION_KEY::SCALE:
                self->onNodeScale(value);
                break;
            default:
                break;
        }
    }
}


void NodeController::notify(const Node& sender, const observer::Action& action)
{
    if(action.actionId == 1)
    {
        const TransformAction& transaction = static_cast<const TransformAction&>(action);
        dispatch(this, transaction.key, transaction.value);
    }
}