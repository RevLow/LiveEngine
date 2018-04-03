//
//  FileManager.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/02.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "FileManager.h"
#include "FileManagerImpl.h"
#include <fstream>

using namespace live;

std::string FileManager::readFile(const std::string &filePath)
{
    std::ifstream ifs(filePath);
    if (ifs.fail())
    {
        return "";
    }

    std::istreambuf_iterator<char> it(ifs);
    std::istreambuf_iterator<char> last;
    return std::string(it, last);
}

std::string FileManager::getUserPath()
{
    return FileManagerImpl::getUserPath();
}

std::string FileManager::getCachePath()
{
    return FileManagerImpl::getCachePath();
}

std::string FileManager::getTmporaryPath()
{
    return FileManagerImpl::getTemporaryPath();
}

bool FileManager::isFileExist(const std::string& filePath)
{
    return FileManagerImpl::isFileExist(filePath);
}