//
//  FileManager.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/04/02.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__FileManager__
#define __LiveEngine__FileManager__

namespace live {
    class FileManager
    {
        DEFINE_SINGLETON(FileManager)
    public:
        std::string readFile(const std::string& filePath);
        // iOS: /Documents
        // Android:
        std::string getUserPath();
        // iOS: /Library/Caches
        // Android:
        std::string getCachePath();
        // iOS: /tmp
        // Android:
        std::string getTmporaryPath();
        // iOS: /
        // Android:
        std::string getAppBasePath();
        
        bool isFileExist(const std::string& filePath);
    };
}



#endif /* defined(__LiveEngine__FileManager__) */
