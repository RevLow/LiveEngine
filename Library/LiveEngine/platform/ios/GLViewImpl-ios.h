//
//  GLViewImpl-ios.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef LiveEngine_GLViewImpl_ios_h
#define LiveEngine_GLViewImpl_ios_h

#include "../GLView.h"

namespace live
{
    class GLViewImpl final : public GLView
    {
      public:
        GLViewImpl(void* eaglView);

      private:
        // iOSのEAGLViewへのポインタ
        // Objective-cのオブジェクトを持つとC++からこのクラスを使えないため、void*を持つようにする
        void* _eaglView;
    };
}

#endif
