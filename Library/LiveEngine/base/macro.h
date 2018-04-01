//
//  macro.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/24.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef LiveEngine_macro_h
#define LiveEngine_macro_h

#define DEFINE_SINGLETON(TYPE_)\
private:\
using self_type = TYPE_;\
using unique_ptr = std::unique_ptr<self_type>;\
public:\
using singleton = const unique_ptr &;\
static singleton getInstance() {\
return ref();\
}\
static void create() {\
if (!ref()) ref() = make_unique();\
}\
static void destroy() {\
ref().reset();\
}\
private:\
template <typename... Args>\
static unique_ptr make_unique(Args&&... args) {\
struct temp : self_type { temp() : self_type() {} };\
return std::move(unique_ptr(new temp(std::forward<Args>(args)...)));\
}\
static unique_ptr &ref() {\
static unique_ptr p = make_unique();\
return p;\
}


#endif
