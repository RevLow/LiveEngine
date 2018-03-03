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
#include "Texture2D.h"

namespace live
{
    class Sprite : public Node
    {
    public:
        static std::shared_ptr<Sprite> create() noexcept { return std::make_shared<Sprite>(); };
        virtual void update(float deltaT) {};
        virtual void traversal(const Matrix4D& parentMatrix, const Visitor& visitor) override;
        virtual void drawCall(const Visitor& visitor) override;
    private:
        Rect bounds;
        std::weak_ptr<Texture2D> texture;
    };
}

#endif /* defined(__LiveEngine__Sprite__) */
