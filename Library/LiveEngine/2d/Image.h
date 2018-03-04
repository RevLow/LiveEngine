//
//  Image.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/03.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Image__
#define __LiveEngine__Image__

namespace live {
    class Image
    {
    public:
        Image(const std::string& filePath);
        virtual ~Image();
        bool hasAlpha() const { return alpha; };
        float getWidth() const { return width; };
        float getHeight() const { return height; };
        GLubyte* getImageBuffer() { return imageBuffer; }
    private:
        float width;
        float height;
        bool alpha;
        GLubyte* imageBuffer;
    };
}


#endif /* defined(__LiveEngine__Image__) */
