//
//  LiveEngineTests.m
//  LiveEngineTests
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "../LiveEngine/base/BaseType.h"

@interface LiveEngineTests : XCTestCase

@end

@implementation LiveEngineTests

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

- (void)testMatrix4DOperationDot
{
    live::Matrix4D mat = {
        3.0f, 1.0f, 1.0f, 2.0f,
        5.0f, 1.0f, 3.0f, 4.0f,
        2.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 3.0f, 2.0f, 1.0f
    };
    
    live::Matrix4D i = live::Matrix4D::Identity();
    
    live::Matrix4D expect = i * mat;
    
    XCTAssertEqual(expect.m11, 3.0f, "m11 fail");
    XCTAssertEqual(expect.m12, 1.0f, "m12 fail");
    XCTAssertEqual(expect.m13, 1.0f, "m13 fail");
    XCTAssertEqual(expect.m14, 2.0f, "m14 fail");
    
    XCTAssertEqual(expect.m21, 5.0f, "m21 fail");
    XCTAssertEqual(expect.m22, 1.0f, "m22 fail");
    XCTAssertEqual(expect.m23, 3.0f, "m23 fail");
    XCTAssertEqual(expect.m24, 4.0f, "m24 fail");
    
    XCTAssertEqual(expect.m31, 2.0f, "m31 fail");
    XCTAssertEqual(expect.m32, 0.0f, "m32 fail");
    XCTAssertEqual(expect.m33, 1.0f, "m33 fail");
    XCTAssertEqual(expect.m34, 0.0f, "m34 fail");
    
    XCTAssertEqual(expect.m41, 1.0f, "m41 fail");
    XCTAssertEqual(expect.m42, 3.0f, "m42 fail");
    XCTAssertEqual(expect.m43, 2.0f, "m43 fail");
    XCTAssertEqual(expect.m44, 1.0f, "m44 fail");
}


- (void)testMatrix4IdentityInverse
{
    live::Matrix4D mat = live::Matrix4D::Identity();
    live::Matrix4D expect = mat.inverse() * mat;
    
    XCTAssertEqual(expect.m11, 1.0f, "m11 fail");
    XCTAssertEqual(expect.m12, 0.0f, "m12 fail");
    XCTAssertEqual(expect.m13, 0.0f, "m13 fail");
    XCTAssertEqual(expect.m14, 0.0f, "m14 fail");
    
    XCTAssertEqual(expect.m21, 0.0f, "m21 fail");
    XCTAssertEqual(expect.m22, 1.0f, "m22 fail");
    XCTAssertEqual(expect.m23, 0.0f, "m23 fail");
    XCTAssertEqual(expect.m24, 0.0f, "m24 fail");
    
    XCTAssertEqual(expect.m31, 0.0f, "m31 fail");
    XCTAssertEqual(expect.m32, 0.0f, "m32 fail");
    XCTAssertEqual(expect.m33, 1.0f, "m33 fail");
    XCTAssertEqual(expect.m34, 0.0f, "m34 fail");
    
    XCTAssertEqual(expect.m41, 0.0f, "m41 fail");
    XCTAssertEqual(expect.m42, 0.0f, "m42 fail");
    XCTAssertEqual(expect.m43, 0.0f, "m43 fail");
    XCTAssertEqual(expect.m44, 1.0f, "m44 fail");
}

-(void) testMatrix4DInverse
{
    live::Matrix4D mat = {
        3.0f, 1.0f, 1.0f, 2.0f,
        5.0f, 1.0f, 3.0f, 4.0f,
        2.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 3.0f, 2.0f, 1.0f
    };
    
    live::Matrix4D expect = mat.inverse() * mat;
    
    XCTAssertEqual(roundf(expect.m11), 1.0f, "m11 fail");
    XCTAssertEqual(roundf(expect.m12), 0.0f, "m12 fail");
    XCTAssertEqual(roundf(expect.m13), 0.0f, "m13 fail");
    XCTAssertEqual(roundf(expect.m14), 0.0f, "m14 fail");
    
    XCTAssertEqual(roundf(expect.m21), 0.0f, "m21 fail");
    XCTAssertEqual(roundf(expect.m22), 1.0f, "m22 fail");
    XCTAssertEqual(roundf(expect.m23), 0.0f, "m23 fail");
    XCTAssertEqual(roundf(expect.m24), 0.0f, "m24 fail");
    
    XCTAssertEqual(roundf(expect.m31), 0.0f, "m31 fail");
    XCTAssertEqual(roundf(expect.m32), 0.0f, "m32 fail");
    XCTAssertEqual(roundf(expect.m33), 1.0f, "m33 fail");
    XCTAssertEqual(roundf(expect.m34), 0.0f, "m34 fail");
    
    XCTAssertEqual(roundf(expect.m41), 0.0f, "m41 fail");
    XCTAssertEqual(roundf(expect.m42), 0.0f, "m42 fail");
    XCTAssertEqual(roundf(expect.m43), 0.0f, "m43 fail");
    XCTAssertEqual(roundf(expect.m44), 1.0f, "m44 fail");
}

-(void)testMatrix4DDeterminant
{
    live::Matrix4D mat = {
        3.0f, 1.0f, 1.0f, 2.0f,
        5.0f, 1.0f, 3.0f, 4.0f,
        2.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 3.0f, 2.0f, 1.0f
    };

    float detMat = mat.determinant();
    float expectDeterminent = -22.0f;

    XCTAssertEqual(roundf(detMat), expectDeterminent, "Fail determinent value");
}


@end
