//
//  NodeTests.mm
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/12.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "../../../LiveEngine/node/Node.h"
#include "../../../LiveEngine/controller/NodeController.h"

namespace {
    inline float RADIAN_TO_PI(float radian)
    {
        return radian * (M_PI / 180.0f);
    }
}


class MockController : public live::NodeController
{
public:
    MockController(std::shared_ptr<live::Node> n) : live::NodeController(n) {}
    virtual void onNodeTranslate(const live::Vec3& value) override
    {
        isTranslateCall = true;
    }

    virtual void onNodeRation(const live::Vec3& value) override
    {
        isRotateCall = true;
    }

    virtual void onNodeScale(const live::Vec3& value) override
    {
        isScaleCall = true;
    }

    void nodeTranslateX(float translate)
    {
        getTargetNode()->translateX(translate);
    }

    void nodeRotateX(float rotate)
    {
        getTargetNode()->rotateX(rotate);
    }

    void nodeScaleX(float scale)
    {
        getTargetNode()->scaleX(scale);
    }

    bool isTranslateCall = false;
    bool isRotateCall = false;
    bool isScaleCall = false;
};

class MockNode : public live::Node
{
public:
    live::Matrix4D& calculateModelMatrix()
    {
        computeModelMatrix();
        return _modelMatrix;
    }
};

@interface NodeTests : XCTestCase

@end

@implementation NodeTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

-(void) testNodeTransform
{
    std::shared_ptr<live::Node> n = std::make_shared<live::Node>();
    std::shared_ptr<MockController> controller = std::make_shared<MockController>(n);
    
    n->attach(controller);
    controller->nodeTranslateX(1.0f);
    XCTAssertEqual(n->position().x(), 1.0f, "X value is fail");
    XCTAssertEqual(n->position().y(), 0.0f, "Y value is fail");
    XCTAssertEqual(n->position().z(), 0.0f, "Z value is fail");
    XCTAssertEqual(controller->isTranslateCall, true, "Controller does not call");
}

-(void) testNodeRotate
{
    std::shared_ptr<live::Node> n = std::make_shared<live::Node>();
    std::shared_ptr<MockController> controller = std::make_shared<MockController>(n);
    
    n->attach(controller);
    controller->nodeRotateX(0.1f);
    XCTAssertEqual(n->rotation().x(), 0.1f, "X value is fail");
    XCTAssertEqual(n->rotation().y(), 0.0f, "Y value is fail");
    XCTAssertEqual(n->rotation().z(), 0.0f, "Z value is fail");
    XCTAssertEqual(controller->isRotateCall, true, "Controller does not call");
}

-(void) testNodeScale
{
    std::shared_ptr<live::Node> n = std::make_shared<live::Node>();
    std::shared_ptr<MockController> controller = std::make_shared<MockController>(n);
    
    n->attach(controller);
    controller->nodeScaleX(2.0f);
    XCTAssertEqual(n->scale().x(), 2.0f, "X value is fail");
    XCTAssertEqual(n->scale().y(), 1.0f, "X value is fail");
    XCTAssertEqual(n->scale().z(), 1.0f, "X value is fail");
    XCTAssertEqual(controller->isScaleCall, true, "Controller does not call");
}

-(void) testAddChild
{
    std::shared_ptr<live::Node> n = std::make_shared<live::Node>();
    std::shared_ptr<live::Node> child = std::make_shared<live::Node>();

    XCTAssertEqual(n.use_count(), 1, "Reference count is not 1");
    XCTAssertEqual(child.use_count(), 1, "Reference count is not 1");
    n->addChild(child);
    XCTAssertEqual(child.use_count(), 2, "Reference count is not 2");
}

-(void) testMatrixTranslate
{
    std::shared_ptr<MockNode> n = std::make_shared<MockNode>();
    n->translateX(2.0f);

    live::Matrix4D& matrix = n->calculateModelMatrix();
    live::Vec3 srcXYZ = {2.0f, 4.0f, 5.0f};
    live::Vec4 dstXYZ = matrix * srcXYZ;

    XCTAssertEqual(roundf(dstXYZ.x()), 4.0f, "translate failed");
    XCTAssertEqual(roundf(dstXYZ.y()), 4.0f, "translate failed");
    XCTAssertEqual(roundf(dstXYZ.z()), 5.0f, "translate failed");
}

-(void) testMatrixRotation
{
    std::shared_ptr<MockNode> n = std::make_shared<MockNode>();
    n->anchorPoint({0.5f, 0.5f, 0.0f});
    n->rotateZ(RADIAN_TO_PI(90.0f));
    live::Matrix4D& matrix = n->calculateModelMatrix();
    
    live::Vec3 srcXYZ = {1.0f, 1.0f, 1.0f};
    live::Vec4 dstXYZ = matrix * srcXYZ;
    
    
    XCTAssertEqualWithAccuracy(dstXYZ.x(), -1.5f, 0.01f, "translate failed");
    XCTAssertEqualWithAccuracy(dstXYZ.y(),  0.5f, 0.01f, "translate failed");
    XCTAssertEqualWithAccuracy(dstXYZ.z(),  1.0f, 0.01f, "translate failed");
}

-(void) testMatrixScale
{
    std::shared_ptr<MockNode> n = std::make_shared<MockNode>();
    n->anchorPoint({0.5f, 0.5f, 0.0f});
    n->scale({2.0f, 2.0f, 1.0f});
    live::Matrix4D& matrix = n->calculateModelMatrix();
    
    live::Vec3 srcXYZ = {1.0f, 1.0f, 1.0f};
    live::Vec4 dstXYZ = matrix * srcXYZ;
    
    XCTAssertEqual(dstXYZ.x(), 1.0f, "translate failed");
    XCTAssertEqual(dstXYZ.y(), 1.0f, "translate failed");
    XCTAssertEqual(dstXYZ.z(), 1.0f, "translate failed");
}

-(void) testMatrixCalculation
{
    std::shared_ptr<MockNode> n = std::make_shared<MockNode>();
    n->anchorPoint({0.5f, 0.5f, 0.0f});
    n->translateX(2.0f);
    n->rotateZ(RADIAN_TO_PI(45.0f));
    n->scale({2.0f, 2.0f, 1.0f});

    live::Matrix4D&  matrix = n->calculateModelMatrix();
    live::Vec3 srcXYZ = {1.0f, 1.0f, 1.0f};
    live::Vec4 dstXYZ = matrix * srcXYZ;
    
    XCTAssertEqualWithAccuracy(dstXYZ.x(), 1.0f,                  0.01f, "translate failed");
    XCTAssertEqualWithAccuracy(dstXYZ.y(), 2.0f * sqrt(2) - 1.0f, 0.01f, "translate failed");
    XCTAssertEqual(dstXYZ.z(), 1.0f, "translate failed");
}

@end
