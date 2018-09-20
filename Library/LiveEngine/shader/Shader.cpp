//
//  Shader.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/01.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//
         
#include "Shader.h"
#include "../external/xxhash/xxhash.h"

namespace {
    const char* GLES_VERSION = "#version 300";

    template<GLenum T>
    GLuint compileShader(const GLchar* source)
    {
        // シェーダ作成
        GLuint shaderHandle = glCreateShader(T);
        glShaderSource(shaderHandle, 1, &source, nullptr);
        //glShaderSource(shaderHandle, sizeof(source), &source, nullptr);
        glCompileShader(shaderHandle);
        
        // コンパイルエラーチェック
        {
            GLint compileSuccess = 0;
            glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
            if(compileSuccess == GL_FALSE)
            {
                GLint infoLen = 0;
                glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLen);
                if(infoLen > 1)
                {
                    GLchar* message = new GLchar[infoLen];
                    glGetShaderInfoLog(shaderHandle, infoLen, NULL, message);
                    fprintf(stderr, "%s", message);
                    delete [] message;
                }
                else {
                    fprintf(stderr, "complete error not info...");
                }
            }
            assert(compileSuccess == GL_TRUE);
        }
        
        return shaderHandle;
    }
}

#pragma mark SHADER PROGRAM MEMBERS

using namespace live;

ShaderProgram::ShaderProgram(const GLchar* vertexShader, const GLchar* fragmentShader) :
shaderProgram(0)
{
    GLuint vsHandler = compileShader<GL_VERTEX_SHADER>(vertexShader);
    assert(vsHandler != 0);
    GLuint fsHandler = compileShader<GL_FRAGMENT_SHADER>(fragmentShader);
    assert(fsHandler != 0);
    
    shaderProgram = glCreateProgram();
    assert(shaderProgram != 0);
    
    glAttachShader(shaderProgram, vsHandler);
    assert(glGetError() == GL_NO_ERROR);
    
    glAttachShader(shaderProgram, fsHandler);
    assert(glGetError() == GL_NO_ERROR);
    
    link();

    // vertexシェーダ、fragmentシェーダはもう使わないので破棄
    glDeleteShader(vsHandler);
    assert(glGetError() == GL_NO_ERROR);
    glDeleteShader(fsHandler);
    assert(glGetError() == GL_NO_ERROR);
}

ShaderProgram::~ShaderProgram()
{
    // シェーダの利用を終了
    glUseProgram(0);
    assert(glGetError() == GL_NO_ERROR);
    
    // シェーダプログラムの破棄
    glDeleteProgram(shaderProgram);
    assert(glGetError() == GL_NO_ERROR);
    assert(glIsProgram(shaderProgram) == GL_FALSE);
}

void ShaderProgram::use()
{
    glUseProgram(shaderProgram);
    assert(glGetError() == GL_NO_ERROR);
}

void ShaderProgram::link()
{
    glLinkProgram(shaderProgram);

    // リンクエラーチェック
    {
        GLint linkSuccess = 0;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);
        if(linkSuccess == GL_FALSE)
        {
            GLint infoLen = 0;
            glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLen);
            
            if(infoLen > 1)
            {
                GLchar* message = new GLchar[infoLen];
                glGetProgramInfoLog(shaderProgram, infoLen, NULL, message);
                fprintf(stderr, "%s", message);
                delete [] message;
            }
        }
        
        assert(linkSuccess == GL_TRUE);
    }
}