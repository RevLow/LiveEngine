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

class MockController : public live::NodeController
{
public:
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

    bool isTranslateCall = false;
    bool isRotateCall = false;
    bool isScaleCall = false;
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
    live::Node n;
    std::shared_ptr<MockController> controller = std::make_shared<MockController>();
    
    n.attach(controller);
    n.translateX(1.0f);
    XCTAssertEqual(n.position().x(), 1.0f, "X value is fail");
    XCTAssertEqual(n.position().y(), 0.0f, "X value is fail");
    XCTAssertEqual(n.position().z(), 0.0f, "X value is fail");
    XCTAssertEqual(controller->isTranslateCall, true, "Controller does not call");
}

-(void) testNodeRotate
{
    live::Node n;
    std::shared_ptr<MockController> controller = std::make_shared<MockController>();
    
    n.attach(controller);
    n.rotateX(0.1f);
    XCTAssertEqual(n.rotation().x(), 0.1f, "X value is fail");
    XCTAssertEqual(n.rotation().y(), 0.0f, "X value is fail");
    XCTAssertEqual(n.rotation().z(), 0.0f, "X value is fail");
    XCTAssertEqual(controller->isRotateCall, true, "Controller does not call");
}

-(void) testNodeScale
{
    live::Node n;
    std::shared_ptr<MockController> controller = std::make_shared<MockController>();
    
    n.attach(controller);
    n.scaleX(2.0f);
    XCTAssertEqual(n.scale().x(), 2.0f, "X value is fail");
    XCTAssertEqual(n.scale().y(), 1.0f, "X value is fail");
    XCTAssertEqual(n.scale().z(), 1.0f, "X value is fail");
    XCTAssertEqual(controller->isScaleCall, true, "Controller does not call");
}


@end
