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
#include "../node/Node.h"

namespace live {
    class NodeController : public Uncopyable<NodeController>, public observer::Observer<Node>
    {
    public:
        /**
         *  監視オブジェクトからの通知メソッド
         *
         *  @param action     実行されたアクション
         */
        virtual void notify(const Node& sender, const observer::Action& action) override;

        // 各イベントハンドラ
        virtual void onNodeTranslate(const Vec3& value) {};
        virtual void onNodeRation(const Vec3& value) {};
        virtual void onNodeScale(const Vec3& value) {};
    };
}

#endif /* defined(__LiveEngine__Component__) */
