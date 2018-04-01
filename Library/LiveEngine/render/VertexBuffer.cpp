//
//  VertexBuffer.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/03/26.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "VertexBuffer.h"

using namespace live;

enum VBOAttribute
{
    POSITION = 0,
    COLOR = 1,
    UV = 2
};

VAO::VAO(const VBO& vbo)
: vaoHandler(0),
vertSize(vbo.vertSize)
{
    glGenVertexArrays(1, &vaoHandler);
    glBindVertexArray(vaoHandler);

    vbo.bind();

    glBindVertexArray(0);
};

VAO::~VAO()
{
    glDeleteVertexArrays(1, &vaoHandler);
}

void VAO::draw()
{
    glBindVertexArray(vaoHandler);
    glDrawArrays(GL_TRIANGLES, 0, vertSize);
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
VBO::VBO(GLfloat buffer[], size_t vertSize)
{
    glGenBuffers(1, &bufferHandler);
    assert(glGetError() == GL_NO_ERROR);
    assert(bufferHandler != 0);

    glBindBuffer(GL_ARRAY_BUFFER, bufferHandler);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(float) * 9) * vertSize, buffer, GL_STATIC_DRAW);
    this->vertSize = vertSize;
}

VBO::~VBO()
{
    glDeleteBuffers(1, &bufferHandler);
}

void VBO::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferHandler);
    glEnableVertexAttribArray(VBOAttribute::POSITION);
    glVertexAttribPointer(VBOAttribute::POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 9, (GLubyte*)(sizeof(GLfloat) * 0));
    
    glBindBuffer(GL_ARRAY_BUFFER, bufferHandler);
    glEnableVertexAttribArray(VBOAttribute::COLOR);
    glVertexAttribPointer(VBOAttribute::COLOR, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 9, (GLubyte*)(sizeof(GLfloat) * 3));

    glBindBuffer(GL_ARRAY_BUFFER, bufferHandler);
    glEnableVertexAttribArray(VBOAttribute::UV);
    glVertexAttribPointer(VBOAttribute::UV, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 9, (GLubyte*)(sizeof(GLfloat) * 7));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}