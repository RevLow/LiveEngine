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
    class Uncopyable
    {
      public:
        Uncopyable() = default;
        ~Uncopyable() = default;

      protected:
        Uncopyable(const Uncopyable&) = delete;
        Uncopyable(Uncopyable&&) = delete;
        Uncopyable& operator=(const Uncopyable&) = delete;
        Uncopyable& operator=(Uncopyable&&) = delete;
    };
}

#endif
