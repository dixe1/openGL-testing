//
// Created by bartek on 2/23/26.
//

#pragma once
#include <cstdint>
#include <iterator>
#include <ranges>
#include "Renderer.h"


class IndexBuffer
{
    uint32_t RendererID;

public:
    int count;
    ~IndexBuffer()
    {
        glDeleteBuffers(1, &RendererID);
    }

    void pushData(const uint32_t* data, int count_)
    {
        count = count_;
        glGenBuffers(1, &RendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(int), data, GL_STATIC_DRAW);
    }

    void bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RendererID);
    }
    void unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    [[nodiscard]] inline uint32_t getCount() const { return count; }
};
