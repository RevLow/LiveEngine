//
//  FileManagerImpl.m
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/02.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import "../FileManagerImpl.h"

using namespace live;

namespace {
    inline std::string convertToStdString(NSString* nsString)
    {
        return [nsString UTF8String];
    }

    inline NSString* convertToNsString(const std::string& cppString)
    {
        return [NSString stringWithUTF8String:cppString.c_str()];
    }

    template<NSSearchPathDirectory D>
    std::string getPath()
    {
        NSArray* paths = NSSearchPathForDirectoriesInDomains(D, NSUserDomainMask, YES);
        return convertToStdString([paths objectAtIndex:0]);
    }
}

std::string FileManagerImpl::getAppBasePath()
{
    return convertToStdString(NSHomeDirectory());
}

std::string FileManagerImpl::getUserPath()
{
    return getPath<NSDocumentDirectory>();
}

std::string FileManagerImpl::getCachePath()
{
    return getPath<NSCachesDirectory>();
}

std::string FileManagerImpl::getTemporaryPath()
{
    return convertToStdString(NSTemporaryDirectory());
}

bool FileManagerImpl::isFileExist(const std::string &filePath)
{
    NSFileManager* fileManager = [NSFileManager defaultManager];
    return [fileManager fileExistsAtPath:convertToNsString(filePath)];
}

