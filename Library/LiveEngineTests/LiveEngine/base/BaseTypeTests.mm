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
    
    XCTAssertEqualWithAccuracy(dot, 8.0f, 0.01f, "dot value is failed");
}

-(void) testVecCross
{
    live::Vec3 v1 = {0.0f, 1.0f, 2.0f};
    live::Vec3 v2 = {1.0f, 2.0f, 3.0f};
    live::Vec3 result = v1.cross(v2);
    
    XCTAssertEqualWithAccuracy(result.x(), -1.0f, 0.01f, "x value is failed");
    XCTAssertEqualWithAccuracy(result.y(),  2.0f, 0.01f, "y value is failed");
    XCTAssertEqualWithAccuracy(result.z(), -1.0f, 0.01f, "z value is failed");
}

- (void)testMatrix4DOperationDot
{
    live::Matrix4D mat = {
        3.0f, 5.0f, 2.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 3.0f,
        1.0f, 3.0f, 1.0f, 2.0f,
        2.0f, 4.0f, 0.0f, 1.0f
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
    XCTAssertEqual(expect.m21, 0.0f, "m12 fail");
    XCTAssertEqual(expect.m31, 0.0f, "m13 fail");
    XCTAssertEqual(expect.m41, 0.0f, "m14 fail");
    
    XCTAssertEqual(expect.m12, 0.0f, "m21 fail");
    XCTAssertEqual(expect.m22, 1.0f, "m22 fail");
    XCTAssertEqual(expect.m32, 0.0f, "m23 fail");
    XCTAssertEqual(expect.m42, 0.0f, "m24 fail");
    
    XCTAssertEqual(expect.m13, 0.0f, "m31 fail");
    XCTAssertEqual(expect.m23, 0.0f, "m32 fail");
    XCTAssertEqual(expect.m33, 1.0f, "m33 fail");
    XCTAssertEqual(expect.m43, 0.0f, "m34 fail");
    
    XCTAssertEqual(expect.m14, 0.0f, "m14 fail");
    XCTAssertEqual(expect.m24, 0.0f, "m24 fail");
    XCTAssertEqual(expect.m34, 0.0f, "m34 fail");
    XCTAssertEqual(expect.m44, 1.0f, "m44 fail");
}

-(void) testMatrix4DInverse
{
    live::Matrix4D mat = {
        3.0f, 5.0f, 2.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 3.0f,
        1.0f, 3.0f, 1.0f, 2.0f,
        2.0f, 4.0f, 0.0f, 1.0f
    };
    
    live::Matrix4D expect = mat.inverse() * mat;
    
    XCTAssertEqualWithAccuracy(expect.m11, 1.0f, 0.01f, "m11 fail");
    XCTAssertEqualWithAccuracy(expect.m21, 0.0f, 0.01f, "m21 fail");
    XCTAssertEqualWithAccuracy(expect.m31, 0.0f, 0.01f, "m31 fail");
    XCTAssertEqualWithAccuracy(expect.m41, 0.0f, 0.01f, "m41 fail");
    
    XCTAssertEqualWithAccuracy(expect.m12, 0.0f, 0.01f, "m12 fail");
    XCTAssertEqualWithAccuracy(expect.m22, 1.0f, 0.01f, "m22 fail");
    XCTAssertEqualWithAccuracy(expect.m32, 0.0f, 0.01f, "m32 fail");
    XCTAssertEqualWithAccuracy(expect.m42, 0.0f, 0.01f, "m42 fail");
    
    XCTAssertEqualWithAccuracy(expect.m13, 0.0f, 0.01f, "m13 fail");
    XCTAssertEqualWithAccuracy(expect.m23, 0.0f, 0.01f, "m23 fail");
    XCTAssertEqualWithAccuracy(expect.m33, 1.0f, 0.01f, "m33 fail");
    XCTAssertEqualWithAccuracy(expect.m43, 0.0f, 0.01f, "m43 fail");
    
    XCTAssertEqualWithAccuracy(expect.m14, 0.0f, 0.01f, "m14 fail");
    XCTAssertEqualWithAccuracy(expect.m24, 0.0f, 0.01f, "m24 fail");
    XCTAssertEqualWithAccuracy(expect.m34, 0.0f, 0.01f, "m34 fail");
    XCTAssertEqualWithAccuracy(expect.m44, 1.0f, 0.01f, "m44 fail");
}

-(void)testMatrix4DDeterminant
{
    live::Matrix4D mat = {
        3.0f, 5.0f, 2.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 3.0f,
        1.0f, 3.0f, 1.0f, 2.0f,
        2.0f, 4.0f, 0.0f, 1.0f
    };
    
    float detMat = mat.determinant();
    float expectDeterminent = -22.0f;
    
    XCTAssertEqualWithAccuracy(detMat, expectDeterminent, 0.01f, "Fail determinent value");
}


-(void)testMatrix4DTranspose
{
    live::Matrix4D mat = {
        3.0f, 5.0f, 2.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 3.0f,
        1.0f, 3.0f, 1.0f, 2.0f,
        2.0f, 4.0f, 0.0f, 1.0f
    };
    
    live::Matrix4D tMat = mat.transpose();
    
    XCTAssertEqualWithAccuracy(tMat.m11, mat.m11, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m12, mat.m21, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m13, mat.m31, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m14, mat.m41, 0.01f, "Fail transpose");
    
    XCTAssertEqualWithAccuracy(tMat.m21, mat.m12, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m22, mat.m22, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m23, mat.m32, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m24, mat.m42, 0.01f, "Fail transpose");
    
    XCTAssertEqualWithAccuracy(tMat.m31, mat.m13, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m32, mat.m23, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m33, mat.m33, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m34, mat.m43, 0.01f, "Fail transpose");
    
    XCTAssertEqualWithAccuracy(tMat.m41, mat.m14, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m42, mat.m24, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m43, mat.m34, 0.01f, "Fail transpose");
    XCTAssertEqualWithAccuracy(tMat.m44, mat.m44, 0.01f, "Fail transpose");
}

-(void) testMatrix4DDotVec3
{
    live::Matrix4D mat = {
        3.0f, 5.0f, 2.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 3.0f,
        1.0f, 3.0f, 1.0f, 2.0f,
        2.0f, 4.0f, 0.0f, 1.0f
    };

    live::Vec3 v = { 1.0f, 0.0f, 2.0f };
    live::Vec4 result = mat * v;
    
    XCTAssertEqualWithAccuracy(result.x(), 7.0f, 0.01f, "Fail x");
    XCTAssertEqualWithAccuracy(result.y(), 15.0f,0.01f, "Fail y");
    XCTAssertEqualWithAccuracy(result.z(), 4.0f, 0.01f, "Fail z");
    XCTAssertEqualWithAccuracy(result.w(), 6.0f, 0.01f, "Fail w");
}

-(void) testMatrix4DDotVec4
{
    live::Matrix4D mat = {
        3.0f, 5.0f, 2.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 3.0f,
        1.0f, 3.0f, 1.0f, 2.0f,
        2.0f, 4.0f, 0.0f, 1.0f
    };
    
    live::Vec4 v = { 1.0f, 0.0f, 2.0f, 2.0f };
    live::Vec4 result = mat * v;
    
    XCTAssertEqualWithAccuracy(result.x(), 9.0f,  0.01f, "Fail x");
    XCTAssertEqualWithAccuracy(result.y(), 19.0f, 0.01f, "Fail y");
    XCTAssertEqualWithAccuracy(result.z(), 4.0f,  0.01f, "Fail z");
    XCTAssertEqualWithAccuracy(result.w(), 7.0f,  0.01f, "Fail w");
}

-(void) testTriangleContain
{
    live::Triangle t1 = {
        { {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} }
    };
    
    bool result = t1.isContain({0.5f, 0.5f, 0.0f});

    XCTAssert(result, "position is not contain");
}

-(void) testTriangleNotContain
{
    live::Triangle t1 = {
        { {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} }
    };
    
    bool result = t1.isContain({0.5f, 1.5f, 0.0f});
    
    XCTAssert(!result, "position is contain");
}

-(void) testRectContain
{
    live::Rect r1 = {
        { {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} }
    };
    
    bool result = r1.isContain({0.5f, 0.5f, 0.0f});
    
    XCTAssert(result, "position is not contain");
}

-(void) testRectNotContain
{
    live::Rect r1 = {
        { {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} }
    };
    
    bool result = r1.isContain({1.5f, 2.5f, 0.0f});
    
    XCTAssert(!result, "position is not contain");
}

-(void) testRectSplitTriangles
{
    live::Rect r1 = {
        { {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} },
        { {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f} }
    };
    
    std::array<live::Triangle, 2> triangles = r1.split();

    // 1つめの三角形
    XCTAssertEqual(triangles[0].vertices[0].position.x(), 0.0f, "vert1 position x fail");
    XCTAssertEqual(triangles[0].vertices[0].position.y(), 1.0f, "vert1 position y fail");
    XCTAssertEqual(triangles[0].vertices[0].position.z(), 0.0f, "vert1 position z fail");
    
    XCTAssertEqual(triangles[0].vertices[1].position.x(), 0.0f, "vert2 position x fail");
    XCTAssertEqual(triangles[0].vertices[1].position.y(), 0.0f, "vert2 position y fail");
    XCTAssertEqual(triangles[0].vertices[1].position.z(), 0.0f, "vert2 position z fail");
    
    XCTAssertEqual(triangles[0].vertices[2].position.x(), 1.0f, "vert3 position x fail");
    XCTAssertEqual(triangles[0].vertices[2].position.y(), 1.0f, "vert3 position y fail");
    XCTAssertEqual(triangles[0].vertices[2].position.z(), 0.0f, "vert3 position z fail");

    // 2つめの三角形
    XCTAssertEqual(triangles[1].vertices[0].position.x(), 1.0f, "vert1 position x fail");
    XCTAssertEqual(triangles[1].vertices[0].position.y(), 1.0f, "vert1 position y fail");
    XCTAssertEqual(triangles[1].vertices[0].position.z(), 0.0f, "vert1 position z fail");
    
    XCTAssertEqual(triangles[1].vertices[1].position.x(), 0.0f, "vert2 position x fail");
    XCTAssertEqual(triangles[1].vertices[1].position.y(), 0.0f, "vert2 position y fail");
    XCTAssertEqual(triangles[1].vertices[1].position.z(), 0.0f, "vert2 position z fail");
    
    XCTAssertEqual(triangles[1].vertices[2].position.x(), 1.0f, "vert3 position x fail");
    XCTAssertEqual(triangles[1].vertices[2].position.y(), 0.0f, "vert3 position y fail");
    XCTAssertEqual(triangles[1].vertices[2].position.z(), 0.0f, "vert3 position z fail");

}

@end
