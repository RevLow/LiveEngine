//
//  MainScene.cpp
//  LiveEngineApp
//
//  Created by Tetsushi on 2018/03/24.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "MainScene.h"

using namespace live;

class SpriteController : public NodeController
{
public:
    // 各イベントハンドラ
    virtual void onNodeTranslate(const Vec3& value) override
    {
        getTargetNode()->position();
    };
    virtual void onNodeRation(const Vec3& value) override {};
    virtual void onNodeScale(const Vec3& value) override {};
};

MainScene::MainScene() : Scene::Scene()
{
    std::shared_ptr<Sprite> sp = std::make_shared<Sprite>("filename");
    std::shared_ptr<SpriteController> controller = std::make_shared<SpriteController>(sp);
    sp->attach(controller);

    addChild(sp);
}