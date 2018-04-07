//
//  RenderTask.cpp
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/14.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#include "RenderTask.h"
#include "../render/VertexBuffer.h"

using namespace live;

void RenderTask::run() const
void RenderTask::run()
{
    const RenderGroup& renderGroup = Application::getInstance()->getRenderGroup();
    
    for (const std::unique_ptr<RenderQueue>& renderQueue : renderGroup )
    {
        const int vertSize = 3 * 2 * renderQueue->queue.size();
        const int bufferSize = vertSize * 9;
        
        // render頂点バッファを作成
        GLfloat* buffer = (GLfloat*)malloc(sizeof(GLfloat) * bufferSize);
        int bufferCount = 0;
        for (const std::unique_ptr<TriangleRenderCommand>& cmd : renderQueue->queue)
        {
            for(const Triangle& triangle : cmd->getTriangles())
            {
                for(const Vertex& vertex : triangle.vertices)
                {
                    buffer[bufferCount + 0] = vertex.position.x;
                    buffer[bufferCount + 1] = vertex.position.y;
                    buffer[bufferCount + 2] = vertex.position.z;
                    
                    buffer[bufferCount + 3] = vertex.color.x;
                    buffer[bufferCount + 4] = vertex.color.y;
                    buffer[bufferCount + 5] = vertex.color.z;
                    buffer[bufferCount + 6] = vertex.color.w;

                    buffer[bufferCount + 7] = vertex.uv.u;
                    buffer[bufferCount + 8] = vertex.uv.v;

                    bufferCount += 9;
                }
            }
        }

        // renderQueue.materialIdからシェーダを使用する
        renderQueue->material->use();

        /*
         Shader shader("vertexshaderのファイル名", "fragmentshaderのファイル名");
         shader.compile();
         shader.useProgram();
        */
        

        /*
         VBO vbo(buffer, vertSize);
         free(buffer);

         VAO vao(vbo);
         vao.draw();
        */
        
        

        // vbo, vao delete
        // release vertex buffer and vertex array
    }

}