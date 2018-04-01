//
//  VertexBuffer.h
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/26.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#ifndef __LiveEngine__VertexBuffer__
#define __LiveEngine__VertexBuffer__


namespace live
{
    class VBO
    {
    friend class VAO;
    public:
        VBO(GLfloat buffer[], size_t vertSize);
        ~VBO();
        void bind() const;
    private:
        GLuint bufferHandler;
        uint32_t vertSize;
    };
    
    class VAO
    {
    public:
        VAO(const VBO& vbo);
        ~VAO();
        void draw();
    private:
        GLuint vaoHandler;
        uint32_t vertSize;
    };
    
}



#endif /* defined(__LiveEngine__VertexBuffer__) */
