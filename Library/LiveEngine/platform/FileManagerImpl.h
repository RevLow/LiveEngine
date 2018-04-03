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
        static std::string getAppBasePath();
        static std::string getUserPath();
        static std::string getCachePath();
        static std::string getTemporaryPath();
        static bool isFileExist(const std::string& filePath);
    };
}


#endif
