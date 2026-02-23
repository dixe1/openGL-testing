//
// Created by bartek on 2/23/26.
//

#pragma once
#include "Renderer.h"

class VertexArray
{
    uint32_t RendererID;
public:
    ~VertexArray()
    {
        glDeleteVertexArrays(1, &RendererID);
    }

    void pushData(uint32_t type, uint32_t strike)
    {
        glGenVertexArrays(1, &RendererID);
        glBindVertexArray(RendererID);
        glVertexAttribPointer(0, type, GL_FLOAT, GL_FALSE, strike * sizeof(float), 0);
        glEnableVertexAttribArray(0);
    }

    void bind() const
    {
        glBindVertexArray(RendererID);
    }
    void unbind() const
    {
        glBindVertexArray(0);
    }
};