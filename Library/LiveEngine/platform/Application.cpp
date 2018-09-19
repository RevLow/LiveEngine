//
//  Application.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Application.h"

using namespace live;

Application::Application() : _glview(nullptr)
{
}

void Application::initGLView(GLView* glview)
{
    _glview = std::unique_ptr<GLView>(glview);
}

void Application::update(float delta)
{
    /*
     // レンダー用とストア用のコマンドバッファをスワップ
     std::thread th1([](){
        // シーングラフのUPDATE
        // 次フレームに描画するため、コマンドバッファを送信
     });
     
     std::thread th2([]() {
        // 前フレームのレンダーコマンドをGPUに送信しレンダリング
     });
     
     
     th1.join();
     th2.join();
     */
}