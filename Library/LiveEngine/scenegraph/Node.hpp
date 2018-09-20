//
//  Node.hpp
//  LiveEngine
//
//  Created by Tetsushi Haresaku on 2018/09/20.
//  Copyright © 2018年 RevLow. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

namespace live {
    class Node;
    using NodePtr = std::shared_ptr<Node>;

    class Node {
    public:
        static inline NodePtr create()
        {
            return std::make_shared<Node>();
        }

        virtual void addChild(NodePtr node);
        virtual void updateMatrix();
        virtual void setPosition(const Vec3& position);
        virtual void setRotation(const Vec3& rotation);
        virtual void setScale(const Vec3& scale);
    protected:
        std::weak_ptr<Node> m_parent;
    private:
        std::vector<NodePtr> m_children;
        Vec3 m_position;
        Vec3 m_rotation;
        Vec3 m_scale;
        Vec2 m_uv;
        Matrix4D m_model_matrix;
        bool m_dirty;
    };
}


#endif /* Node_hpp */
