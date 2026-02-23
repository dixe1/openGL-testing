cmake_minimum_required(VERSION 4.1)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig REQUIRED)
find_package(GLEW REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
find_package(OpenGL REQUIRED)

add_executable(untitled2
        src/main.cpp
        include/InitWindow.h
        include/ShaderLoader.h
        include/Renderer.h
        include/VertexBuffer.h
        include/IndexBuffer.h
        include/VertexArray.h
)

target_include_directories(untitled2 PRIVATE
        ${GLFW_INCLUDE_DIRS}
)

target_link_libraries(untitled2 PRIVATE
        GLEW::GLEW
        OpenGL::GL
        ${GLFW_LIBRARIES}
)