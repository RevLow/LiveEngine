//
//  EAGLView.m
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import "EAGLView.h"
#include "Application.h"

using namespace live;

@implementation EAGLView

+(Class)layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        [self setUp];
        [self setUpDisplayLink];
    }
    return self;
}

-(void)dealloc
{
    [_displayLink invalidate];
}

-(void) setUp
{
    CAEAGLLayer* layer = (CAEAGLLayer*)self.layer;
    layer.opaque = YES;
    _context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
    [EAGLContext setCurrentContext:_context];
    

    glGenRenderbuffers(1, &_renderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, _renderBuffer);
    [_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:layer];
    

    glGenFramebuffers(1, &_frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, _frameBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _renderBuffer);
}

-(void) setUpDisplayLink
{
    _displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(update:)];
    [_displayLink addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
}


-(void) layoutSubviews
{
    [super layoutSubviews];
    glViewport(0, 0, self.frame.size.width, self.frame.size.height);
}


-(void) update:(CADisplayLink *)link
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    Application::instance().update(link.duration);
    
    glBindRenderbuffer(GL_RENDERBUFFER, _renderBuffer);
    [_context presentRenderbuffer:GL_RENDERBUFFER];
}

-(EAGLContext*)getGLContext
{
    return _context;
};

-(GLuint)getFrameBuffer
{
    return _frameBuffer;
}

-(GLuint)getRenderBuffer
{
    return _renderBuffer;
}

-(float)getFrameWidth
{
    return [self getFrameWidth];
}

-(float)getFrameHeight
{
    return [self getFrameHeight];
}



@end
