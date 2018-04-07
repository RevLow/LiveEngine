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
    namespace VBO_CONST
    {
        constexpr int VBO_SIZE = 65536;
        constexpr int INDEX_VBO_SIZE = VBO_SIZE * 6 / 4;
    }

    class VBO
    {
    public:
        VBO();
        ~VBO();
        void bind(int filledVertexSize, int filledIndexSize);
        static void unbind();
        Vertex* getVertsPtr() { return verts; }
        GLushort* getIndicesPtr() { return indices; }
    private:
        Vertex verts[VBO_CONST::VBO_SIZE];
        GLushort indices[VBO_CONST::INDEX_VBO_SIZE];

        GLuint bufferHandler;
        GLuint indicesHandler;
    };
    
    class VAO
    {
    public:
        VAO();
        ~VAO();
        std::unique_ptr<VBO>& getVbo() { return vbo; };
        void bind(int filledVertexSize, int filledIndexSize);
        void draw(ssize_t indexCount, ssize_t startIndex);
        static void unbind();
    private:
        GLuint vaoHandler;
        uint32_t vertSize;
        std::unique_ptr<VBO> vbo;
    };
    
}



#endif /* defined(__LiveEngine__VertexBuffer__) */
