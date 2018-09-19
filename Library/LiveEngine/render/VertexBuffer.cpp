//
//  VertexBuffer.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/26.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "VertexBuffer.h"

using namespace live;

enum VERTEX_ATTRIB
{
    POSITION = 0,
    COLOR = 1,
    UV = 2
};

VAO::VAO()
: vaoHandler(0)
, vbo(nullptr)
{
    glGenVertexArrays(1, &vaoHandler);
    glBindVertexArray(vaoHandler);

    vbo = std::unique_ptr<VBO>(new VBO());

    VAO::unbind();
};

VAO::~VAO()
{
    glDeleteVertexArrays(1, &vaoHandler);
}

void VAO::draw(ssize_t indexCount, ssize_t offset)
{
    glDrawElements(GL_TRIANGLES, (GLsizei)indexCount, GL_UNSIGNED_SHORT, (GLvoid*)(offset * sizeof(GLushort)));
}

void VAO::bind(int filledVertexSize, int filledIndexSize)
{
    glBindVertexArray(vaoHandler);
    vbo->bind(filledVertexSize, filledIndexSize);
}

void VAO::unbind()
{
    glBindVertexArray(0);
    VBO::unbind();
}

/*
@note
buffer:
    - position: (x, y, z)
      color: (r, g, b, a)
      uv: (u, v)
    - position:
      color:
      uv:
 */
VBO::VBO()
{
    GLuint buffers[2];
    glGenBuffers(2, buffers);

    bufferHandler = buffers[0];
    indicesHandler = buffers[1];
    
    glBindBuffer(GL_ARRAY_BUFFER, bufferHandler);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts[0]) * VBO_CONST::VBO_SIZE, verts, GL_DYNAMIC_DRAW);

    // position
    glEnableVertexAttribArray(VERTEX_ATTRIB::POSITION);
    glVertexAttribPointer(VERTEX_ATTRIB::POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    
    // uv
    glEnableVertexAttribArray(VERTEX_ATTRIB::UV);
    glVertexAttribPointer(VERTEX_ATTRIB::UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, uv));

    // color
    glEnableVertexAttribArray(VERTEX_ATTRIB::COLOR);
    glVertexAttribPointer(VERTEX_ATTRIB::COLOR, 4, GL_FLOAT,  GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
    
    // index
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesHandler);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * VBO_CONST::INDEX_VBO_SIZE, indices, GL_STATIC_DRAW);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &bufferHandler);
    glDeleteBuffers(1, &indicesHandler);
}

void VBO::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::bind(int filledVertexSize, int filledIndexSize)
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferHandler);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts[0]) * filledVertexSize, nullptr, GL_DYNAMIC_COPY);
    void* buf = glMapBufferRange(GL_ARRAY_BUFFER, 0, sizeof(verts[0]) * filledVertexSize, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
    memcpy(buf, verts, sizeof(verts[0]) * filledVertexSize);
    glUnmapBuffer(GL_ARRAY_BUFFER);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesHandler);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * filledIndexSize, indices, GL_STATIC_DRAW);
}