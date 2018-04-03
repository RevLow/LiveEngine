//
//  Material.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/02.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Material__
#define __LiveEngine__Material__

#include "../shader/Shader.h"

namespace live
{
    class Material
    {
    public:
        void use();
        uint32_t getMaterialId() const { return materialId; }
        const Material& operator=(Material&& other) noexcept
        {
            if(&other != this)
            {
                this->materialId = other.materialId;
                this->state = std::move(other.state);
                this->texture = other.texture;
                this->program = other.program;
            }
            
            return this;
        }
        Material(Material&& other) noexcept { *this = std::move(other); }
    private:
        uint32_t materialId;
        std::weak_ptr<ShaderProgram> program;
        std::weak_ptr<Texture2D> texture;
        std::unique_ptr<ShaderProgramState> state;
    };
    
}


#endif /* defined(__LiveEngine__Material__) */
