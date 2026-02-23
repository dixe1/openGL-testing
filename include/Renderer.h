//
// Created by bartek on 2/23/26.
//

#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

class Renderer
{
    VertexBuffer vb;
    IndexBuffer ib;
    VertexArray va;
public:
    Renderer(VertexBuffer& vb_, IndexBuffer& ib_, VertexArray& va_) : vb(vb_), ib(ib_), va(va_) {}

    void render() const
    {
        glDrawElements(GL_TRIANGLES, ib.count, GL_UNSIGNED_INT, nullptr);
    }

    static void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    static void swapBuffers(GLFWwindow* window)
    {
        glfwSwapBuffers(window);
    }
    static void pollEvents()
    {
        glfwPollEvents();
    }
};