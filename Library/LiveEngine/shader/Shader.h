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
        friend class ShaderFactory;
    public:
        virtual ~ShaderProgram();
        void use();
        GLint getAttribute(const std::string& attr) const;
        GLint getUniform(const std::string& str) const;
    private:
        ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
        GLuint shaderProgram;

    };

    class ShaderProgramState
    {
        
    };
}

#endif /* defined(__LiveEngine__Shader__) */
