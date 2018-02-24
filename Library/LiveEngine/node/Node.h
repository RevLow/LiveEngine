//
//  Node.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/20.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__Node__
#define __LiveEngine__Node__

#include "../base/Uncopyable.h"
#include "../base/observer/Observer.h"
#include "../base/BaseType.h"

namespace live
{
    class Visitor;
    typedef struct _transformAction : observer::Action
    {
        _transformAction(uint8_t _key, Vec3 _value) : key(_key), value(_value)
        {
            actionId = 1;
        }
        
        uint8_t key;
        Vec3 value;
    } TransformAction;
    
    enum ACTION_KEY
    {
        TRANSLATION = 1,
        ROTATION = 2,
        SCALE = 3,
        ANCHOR = 4
    };
    
    class Node : public observer::Subject<Node>
    {
      public:
        Node();
        virtual ~Node();
        Node(const Node& other) = default;
        Node& operator=(const Node& other) = default;
        
        virtual void addChild(std::shared_ptr<Node> childNode) final;
        virtual void traversal(const Matrix4D& parentMatrix, const Visitor& visitor);
        virtual void drawCall(const Visitor& visitor);

        virtual void transform(Matrix4D&& mat);
        
        virtual void translate(const Vec3& pos) final;
        virtual void translate(Vec3&& pos) final;
        virtual void translateX(float value) final;
        virtual void translateY(float value) final;
        virtual void translateZ(float value) final;

        virtual void rotate(const Vec3& r) final;
        virtual void rotate(Vec3&& r) final;
        virtual void rotateX(float value) final;
        virtual void rotateY(float value) final;
        virtual void rotateZ(float value) final;

        virtual void scale(const Vec3& s) final;
        virtual void scale(Vec3&& s) final;
        virtual void scaleX(float value) final;
        virtual void scaleY(float value) final;
        virtual void scaleZ(float value) final;

        virtual void anchorPoint(const Vec3&) final;
        virtual void anchorPoint(Vec3&& s) final;
        virtual void anchorPointX(float value) final;
        virtual void anchorPointY(float value) final;
        virtual void anchorPointZ(float value) final;

        const Vec3& position() const { return _position; }
        const Vec3& rotation() const { return _rotation; }
        const Vec3& scale() const { return _scale; }
        const Vec3& anchorPoint() const { return _anchorPoint; }
      protected:
        void computeModelMatrix();
        int8_t _layerOrder;
        uint8_t _opacity;
        bool _dirty;
        
        Vec3 _position;
        Vec3 _rotation;
        Vec3 _scale;
        Vec3 _anchorPoint;
        
        Matrix4D _modelMatrix;
        std::vector<std::shared_ptr<Node>> _child;
    };
}

#endif /* defined(__LiveEngine__Node__) */
