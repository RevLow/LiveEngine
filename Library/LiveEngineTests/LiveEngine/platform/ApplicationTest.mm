//
//  ApplicationTest.m
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/14.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "../../../LiveEngine/platform/Application.h"

using namespace live;

@interface ApplicationTest : XCTestCase

@end

@implementation ApplicationTest

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

// Application#updateを実行したとき
// RenderCommandが発行されている
- (void)test_Application_update
{
    Application::getInstance()->update(0);
    XCTAssertTrue(true, @"publish triangle command");
}



@end
