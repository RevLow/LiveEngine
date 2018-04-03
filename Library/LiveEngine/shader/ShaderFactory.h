//
//  ShaderFactory.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/02.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__ShaderFactory__
#define __LiveEngine__ShaderFactory__

#include "Shader.h"

namespace live
{
    class ShaderFactory
    {
        DEFINE_SINGLETON(ShaderFactory);
    public:
        std::weak_ptr<ShaderProgram> makeShader(const std::string& vertexPath, const std::string& fragmentPath);
    private:
        ShaderFactory() = default;
        std::unordered_map<uint32_t, std::shared_ptr<ShaderProgram>> programCache;
    };
}

#endif /* defined(__LiveEngine__ShaderFactory__) */
