//
//  Application.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Application.h"
#include "../shader/Shader.h"
#include "../shader/GLSLPrograms.h"

using namespace live;
Application Application::m_application;

Application::Application() : m_glview(nullptr)
{
}

void Application::initGLView(GLView* glview)
{
    ShaderProgram* shader = new ShaderProgram::ShaderProgram(shaderprograms::VertexShader::SPRITE_SHADER_VERT, shaderprograms::FragmentShader::SPRITE_SHADER_FRAG);
    m_glview = std::unique_ptr<GLView>(glview);
}

void Application::update(float delta)
{
    
    /*
     // レンダー用とストア用のコマンドバッファをスワップ

     std::thread update_thread([](){
        // シーングラフのUPDATE
        // 次フレームに描画するため、コマンドバッファを送信
     });
     // メインスレッドで前フレームの描画処理
     
     update_thread.join();
     */
}
