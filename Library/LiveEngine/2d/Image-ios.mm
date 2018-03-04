//
//  Image.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/03.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "Image.h"

using namespace live;

Image::Image(const std::string& fileName) :
width(0),
height(0),
alpha(false),
imageBuffer(nullptr)
{
    NSString* nsfileName = [[NSString alloc] initWithUTF8String:fileName.c_str()];
    UIImage* image = [UIImage imageNamed:nsfileName];
    CGImageRef textureImage = image.CGImage;
    
    width = static_cast<int>(CGImageGetWidth(textureImage));
    height = static_cast<int>(CGImageGetHeight(textureImage));
    int bpp = static_cast<int>(CGImageGetBitsPerPixel(textureImage)) / 8;
    
    // alpha チェック
    CGImageAlphaInfo info = CGImageGetAlphaInfo(textureImage);
    if(info  == kCGImageAlphaNone) alpha = false;
    else alpha = true;
    
    // テクスチャデータのメモリを確保
    imageBuffer = (GLubyte *)malloc(width * height * 4);
    
    // テクスチャ画像のコンテキストを作成
    CGContextRef textureContext = CGBitmapContextCreate(
                                                        imageBuffer,
                                                        width,
                                                        height,
                                                        8, width * bpp,
                                                        CGImageGetColorSpace(textureImage),
                                                        kCGImageAlphaPremultipliedLast);
    CGContextDrawImage(textureContext, CGRectMake(0.0, 0.0, static_cast<float>(width), static_cast<float>(height)), textureImage);
    CGContextRelease(textureContext);
}

Image::~Image()
{
    free(imageBuffer);
}