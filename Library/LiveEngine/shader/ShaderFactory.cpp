//
//  ShaderFactory.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/02.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "ShaderFactory.h"
#include "../external/xxhash/xxhash.h"

using namespace live;

std::weak_ptr<ShaderProgram> ShaderFactory::makeShader(const std::string &vertexPath, const std::string &fragmentPath)
{
    std::string buffer[2] = { vertexPath, fragmentPath };
    uint32_t hash = XXH32((const void*)buffer, sizeof(buffer), 0);
    
    if (programCache.count(hash) != 0)
    {
        return programCache[hash];
    }
    
    std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>(vertexPath, fragmentPath);
    programCache[hash] = shaderProgram;

    return programCache[hash];
}