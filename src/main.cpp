#include <iostream>

#include "../include/InitWindow.h"
#include "../include/ShaderLoader.h"
#include "../include/Renderer.h"
int main()
{
    Initial init(800, 600, "OpenGL");
    GLFWwindow* window = init.getWindow();

    const Shader shader("../res/shaders/Basic_1.shader");
    shader.bind();

    constexpr std::array<float,6> vertices
        {
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.0f, 0.5f,
        };

    constexpr std::array<uint32_t,3> indices
    {
        0,1,2,
    };

    VertexBuffer vb;
    vb.pushData(vertices.data(), vertices.size() * sizeof(float));

    IndexBuffer ib;
    ib.pushData(indices.data(), indices.size());

    VertexArray va;
    va.pushData(2, 2);

    va.bind();
    vb.bind();
    ib.bind();
    Renderer renderer(vb, ib, va);

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.clear();

        renderer.render();

        /* Swap front and back buffers */
        renderer.swapBuffers(window);

        /* Poll for and process events */
        renderer.pollEvents();
    }
}