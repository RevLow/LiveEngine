//
//  LiveEngine.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__LiveEngine__
#define __LiveEngine__LiveEngine__

#include <memory>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <math.h>
#include <cassert>
#include <OpenGLES/ES3/gl.h>
#include <OpenGLES/ES3/glext.h>

#include "../platform/Application.h"
#include "../base/BaseType.h"

#ifdef __OBJC__
    #define __log(message) NSLog(@message)
    #define __logf(fmt, ...) NSLog(@message, __VA_ARGS__)
#else
    #define __log(message) printf("%s\n", message)
    #define __logf(fmt, ...) printf(fmt "\n",  __VA_ARGS__)
#endif


#endif