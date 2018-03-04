//
//  Texture2D.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/28.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Texture2D.h"

namespace {
    // todo: 文字列の格納をハッシュ化するなら使う
    std::string serializeFilePath(const std::string& filePath)
    {
        return filePath;
    }
}

using namespace live;

Texture2D::Texture2D(const std::string& filePath) : width(0.0f), height(0.0f), textureID(0)
{
    glGenTextures(1, &textureID);
    assert(textureID != 0);
    assert(glGetError() == GL_NO_ERROR);
    
    glBindTexture(GL_TEXTURE_2D, textureID);
    assert(glGetError() == GL_NO_ERROR);
    
    // Imageの読み出し
    auto img = new Image(filePath);
    width = img->getWidth();
    height = img->getHeight();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    assert(glGetError() == GL_NO_ERROR);
    
    // VRAMにピクセル情報をコピーする
    glTexImage2D(GL_TEXTURE_2D, 0, img->hasAlpha() ? GL_RGBA : GL_RGB,
                 img->getWidth(), img->getHeight(),
                 0, img->hasAlpha() ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, img->getImageBuffer());
    assert(glGetError() == GL_NO_ERROR);
    
    // テクスチャ領域外の補間方法
    // GL_CLAMP_TO_EDGEは端の色をそのままコピーする
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // 拡大時の補間方法
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 縮小時の補間方法
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    assert(glGetError() == GL_NO_ERROR);
    
    delete img;
}

Texture2D::~Texture2D()
{
    glBindTexture(textureID, 0);
    glDeleteTextures(1, &textureID);
    assert(glGetError() == GL_NO_ERROR);
}

std::weak_ptr<Texture2D> TextureFactory::produceTexture(const std::string &filePath)
{
    std::string serializeKey = serializeFilePath(filePath);
    
    if(textureCache.find(serializeKey) != textureCache.end())
    {
        return textureCache[serializeKey];
    }

    textureCache[serializeKey] = Texture2D::create(filePath);
    return textureCache[serializeKey];
}

void TextureFactory::releaseTextureCache(const std::string& filePath)
{
    std::string serializeKey = serializeFilePath(filePath);
    auto itr = textureCache.find(serializeKey);
    if(itr != textureCache.end())
    {
        textureCache.erase(itr);
    }
}

void TextureFactory::releaseAllTextureCache()
{
    textureCache.erase(textureCache.begin(), textureCache.end());
}
