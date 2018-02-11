//
//  Uncopyable.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/14.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef LiveEngine_Uncopyable_h
#define LiveEngine_Uncopyable_h

namespace live
{
    template<typename T>
    class Uncopyable
    {
      protected:
        Uncopyable() = default;
        ~Uncopyable() = default;

        Uncopyable(const Uncopyable&) = delete;
        T& operator=(const T&) = delete;
    };
}

#endif
