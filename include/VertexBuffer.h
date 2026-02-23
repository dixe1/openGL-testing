//
// Created by bartek on 2/23/26.
//

#pragma once
#include <cstdint>
#include "Renderer.h"


class VertexBuffer
{
    uint32_t RendererID;

public:
    ~VertexBuffer()
    {
        glDeleteBuffers(1, &RendererID);
    }

    void pushData(const void* data, uint32_t size)
    {
        glGenBuffers(1, &RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, RendererID);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, RendererID);
    }
    void unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};
