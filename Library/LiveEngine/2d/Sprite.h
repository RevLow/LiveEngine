//
//  Sprite.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/18.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Sprite__
#define __LiveEngine__Sprite__

#include "../node/Node.h"

namespace live
{
    class Texture2D;
    class Sprite : public Node
    {
    public:
        virtual void drawCall(const Visitor& visitor) override;
    private:
        Rect bounds;
        std::weak_ptr<Texture2D> texture;
    };
}

#endif /* defined(__LiveEngine__Sprite__) */
