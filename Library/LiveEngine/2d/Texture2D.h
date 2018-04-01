//
//  Texture2D.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/28.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Texture2D__
#define __LiveEngine__Texture2D__

#include "Image.h"

namespace live{
    class Texture2D
    {
    public:
        static std::shared_ptr<Texture2D> create(const std::string& filePath);
        Texture2D(const std::string& filePath);
        virtual ~Texture2D();
        float getImageWidth() const { return width; }
        float getImageHeight() const { return height; }
        GLuint getTextureId() const { return textureID; }
    private:
        GLuint textureID;
        float width;
        float height;
    };

    class TextureFactory
    {
        DEFINE_SINGLETON(TextureFactory);
    public:
        std::weak_ptr<Texture2D> produceTexture(const std::string& filePath);
        void releaseTextureCache(const std::string& filePath);
        void releaseAllTextureCache();
    private:
        std::unordered_map<std::string, std::shared_ptr<Texture2D>> textureCache;
    };
}

#endif /* defined(__LiveEngine__Texture2D__) */
