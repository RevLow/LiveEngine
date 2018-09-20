//
//  FileManagerImpl-ios.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/02.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef LiveEngine_FileManagerImpl_ios_h
#define LiveEngine_FileManagerImpl_ios_h

namespace live {
    namespace FileManagerImpl
    {
        std::string getAppBasePath();
        std::string getUserPath();
        std::string getCachePath();
        std::string getTemporaryPath();
        bool isFileExist(const std::string& filePath);
    };
}


#endif
