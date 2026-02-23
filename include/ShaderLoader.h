//
// Created by bartek on 2/20/26.
//

#pragma once
#include "Renderer.h"

#include <string>
#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>

class Shader
{
public:
    std::string VertexShaderSource, FragmentShaderSource;
    uint32_t program;

    Shader(const std::string& filePath)
    {
        enum class ShaderType
        {
            NONE = -1,
            VERTEX = 0,
            FRAGMENT = 1
        };

        std::ifstream stream(filePath);
        if (!stream.is_open())
            std::cerr << "failed to open " << filePath << std::endl;

        std::string line;
        std::stringstream ss[2];

        ShaderType type = ShaderType::NONE;
        while (getline(stream, line))
        {
            if (line.find("#shader") != std::string::npos)
            {
                if (line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;

                else if (line.find("fragment") != std::string::npos)
                    type = ShaderType::FRAGMENT;
            }
            else
            {
                ss[static_cast<int>(type)] << line << '\n';
            }
        }
            VertexShaderSource = ss[0].str();
            FragmentShaderSource = ss[1].str();

            createShader();
    }

    void bind() const
    {
        glUseProgram(program);
    }
    void unbind() const
    {
        glUseProgram(0);
    }
private:
    void createShader()
    {
        program = glCreateProgram();
        uint32_t vs = compileShader(VertexShaderSource, GL_VERTEX_SHADER);
        uint32_t fs = compileShader(FragmentShaderSource, GL_FRAGMENT_SHADER);

        glAttachShader(program, vs);
        glAttachShader(program, fs);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(fs);
    }
    uint32_t compileShader(const std::string &source, uint32_t type)
    {
        uint32_t id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        // error handling
        int result{};
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);

        if (!result)
        {
            int length{};
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            auto message = std::make_unique<char[]>(length);
            glGetShaderInfoLog(id, length, &length, message.get());
            std::cerr << "failed to compile shader" << std::endl;
            std::cerr << message << std::endl;
            glDeleteShader(id);
            return 0;
        }
        return id;
    }
};