//
//  GLSLPrograms.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/22.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef LiveEngine_GLSLPrograms_h
#define LiveEngine_GLSLPrograms_h

namespace live
{
    namespace shaderprograms
    {
        struct VertexShader
        {
            static const GLchar* SPRITE_SHADER_VERT;
        };
        struct FragmentShader
        {
            static const GLchar* SPRITE_SHADER_FRAG;
        };
        
        #define STRINGIFY(CODE) #CODE
                
        #include "glsl/sprite_shader.vert"
        #include "glsl/sprite_shader.frag"
                
        #undef STRINGIFY
    }
}

#endif
