//
//  EAGLView.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface EAGLView : UIView
{
    EAGLContext* _context;
    GLuint _frameBuffer;
    GLuint _renderBuffer;
    CADisplayLink* _displayLink;
}

@end
