//
//  Shader.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/01.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Shader__
#define __LiveEngine__Shader__

namespace live {
    class ShaderProgram
    {
    public:
        ShaderProgram();
        ShaderProgram(const GLchar* vertexShader, const GLchar* fragmentShader);
        virtual ~ShaderProgram();
        void use();
        void link();
    private:
        GLuint shaderProgram;
    };
}

#endif /* defined(__LiveEngine__Shader__) */
