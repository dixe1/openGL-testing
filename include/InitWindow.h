//
// Created by bartek on 2/21/26.
//

#pragma once
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

#include <array>
#include <iostream>
#include <string>
#include <memory>

class Initial
{
    GLFWwindow* window = nullptr;
    const int windowWidth, windowHeight;
    const std::string windowTitle;

public:
    Initial(int width, int height,std::string title = "default") : windowWidth(width), windowHeight(height), windowTitle(std::move(title))
    {
        /* Initialize the library */
        if (!glfwInit())
            throw std::runtime_error("GLFW initialization failed");

        // OpenGL version
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
        glfwSwapInterval(1); // Turn on V-Sync

        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error("Window initialization failed");
        }

        glfwMakeContextCurrent(window);

        // Initial glew
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            glfwDestroyWindow(window);
            glfwTerminate();
            throw std::runtime_error("glewInit() failed");
        }

        // Set background color
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        // Log info
        std::clog << "OpenGL version " << glGetString(GL_VERSION) << "\n";
    }
    ~Initial()
    {
        if (window)
            glfwDestroyWindow(window);
        glfwTerminate();
    }

    [[nodiscard]] GLFWwindow* getWindow() const { return window; };
};