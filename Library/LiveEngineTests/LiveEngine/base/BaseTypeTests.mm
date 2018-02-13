//
//  BaseTypeTests.m
//  LiveEngine
//
//  Created by Tetsushi on 2018/02/12.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "../../../LiveEngine/base/BaseType.h"

@interface BaseTypeTests : XCTestCase

@end

@implementation BaseTypeTests

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

-(void) testVecPlus
{
    live::Vec3 v1 = {0.0f, 1.0f, 2.0f};
    live::Vec3 v2 = {1.0f, 2.0f, 3.0f};
    live::Vec3 result = v1 + v2;
    
    XCTAssertEqual(result.x(), 1.0f, "x value is failed");
    XCTAssertEqual(result.y(), 3.0f, "y value is failed");
    XCTAssertEqual(result.z(), 5.0f, "z value is failed");
}

-(void) testVecMinus
{
    live::Vec3 v1 = {0.0f, 1.0f, 2.0f};
    live::Vec3 v2 = {1.0f, 2.0f, 3.0f};
    live::Vec3 result = v1 - v2;
    
    XCTAssertEqual(result.x(), -1.0f, "x value is failed");
    XCTAssertEqual(result.y(), -1.0f, "y value is failed");
    XCTAssertEqual(result.z(), -1.0f, "z value is failed");
}

-(void) testVecDot
{
    live::Vec3 v1 = {0.0f, 1.0f, 2.0f};
    live::Vec3 v2 = {1.0f, 2.0f, 3.0f};
    float dot = v1 * v2;
    
    XCTAssertEqual(roundf(dot), 8.0f, "dot value is failed");
}

-(void) testVecCross
{
    live::Vec3 v1 = {0.0f, 1.0f, 2.0f};
    live::Vec3 v2 = {1.0f, 2.0f, 3.0f};
    live::Vec3 result = v1.cross(v2);
    
    XCTAssertEqual(roundf(result.x()), -1.0f, "x value is failed");
    XCTAssertEqual(roundf(result.y()), 2.0f, "y value is failed");
    XCTAssertEqual(roundf(result.z()), -1.0f, "z value is failed");
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


-(void)testMatrix4DTranspose
{
    live::Matrix4D mat = {
        3.0f, 1.0f, 1.0f, 2.0f,
        5.0f, 1.0f, 3.0f, 4.0f,
        2.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 3.0f, 2.0f, 1.0f
    };
    
    live::Matrix4D tMat = mat.transpose();
    
    XCTAssertEqual(roundf(tMat.m11), roundf(mat.m11), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m12), roundf(mat.m21), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m13), roundf(mat.m31), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m14), roundf(mat.m41), "Fail transpose");
    
    XCTAssertEqual(roundf(tMat.m21), roundf(mat.m12), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m22), roundf(mat.m22), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m23), roundf(mat.m32), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m24), roundf(mat.m42), "Fail transpose");
    
    XCTAssertEqual(roundf(tMat.m31), roundf(mat.m13), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m32), roundf(mat.m23), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m33), roundf(mat.m33), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m34), roundf(mat.m43), "Fail transpose");
    
    XCTAssertEqual(roundf(tMat.m41), roundf(mat.m14), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m42), roundf(mat.m24), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m43), roundf(mat.m34), "Fail transpose");
    XCTAssertEqual(roundf(tMat.m44), roundf(mat.m44), "Fail transpose");
}

-(void) testMatrix4DDotVec3
{
    live::Matrix4D mat = {
        3.0f, 1.0f, 1.0f, 2.0f,
        5.0f, 1.0f, 3.0f, 4.0f,
        2.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 3.0f, 2.0f, 1.0f
    };

    live::Vec3 v = { 1.0f, 0.0f, 2.0f };
    live::Vec4 result = mat * v;
    
    XCTAssertEqual(roundf(result.x()), 7.0f,  "Fail x");
    XCTAssertEqual(roundf(result.y()), 15.0f, "Fail y");
    XCTAssertEqual(roundf(result.z()), 4.0f,  "Fail z");
    XCTAssertEqual(roundf(result.w()), 6.0f,  "Fail w");
}

-(void) testMatrix4DDotVec4
{
    live::Matrix4D mat = {
        3.0f, 1.0f, 1.0f, 2.0f,
        5.0f, 1.0f, 3.0f, 4.0f,
        2.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 3.0f, 2.0f, 1.0f
    };
    
    live::Vec4 v = { 1.0f, 0.0f, 2.0f, 2.0f };
    live::Vec4 result = mat * v;
    
    XCTAssertEqual(roundf(result.x()), 9.0f,  "Fail x");
    XCTAssertEqual(roundf(result.y()), 19.0f, "Fail y");
    XCTAssertEqual(roundf(result.z()), 4.0f,  "Fail z");
    XCTAssertEqual(roundf(result.w()), 7.0f,  "Fail w");
}

@end
