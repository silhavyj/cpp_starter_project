//========================================================================
// Simple multi-window example
// Copyright (c) Camilla Löwy <elmindreda@glfw.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>
#include <cxxopts.hpp>
#include <magic_enum/magic_enum.hpp>
#include <nlohmann/json.hpp>

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    fmt::print("{1} {0}\n", "World!", "Hello");

    cxxopts::Options options("MyProgram", "One line description of MyProgram");

    options.add_options()
        ("d,debug", "Enable debugging") // a bool parameter
        ("i,integer", "Int param", cxxopts::value<int>())
        ("f,file", "File name", cxxopts::value<std::string>())
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
    ;

    fmt::print("{}", options.help());

    enum Color { RED, BLUE, WHITE, GREEN };
    constexpr auto color_count = magic_enum::enum_count<Color>();
    fmt::print("count = {}\n", color_count);

    nlohmann::json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {
            {"everything", 42}
        }},
        {"list", {1, 0, 2}},
        {"object", {
            {"currency", "USD"},
            {"value", 42.99}
        }}
    };

    fmt::print("{}", j2.dump());

    int xpos, ypos, height;
    const char* description;
    GLFWwindow* windows[4];

    if (!glfwInit())
    {
        glfwGetError(&description);
        printf("Error: %s\n", description);
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

    glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &xpos, &ypos, NULL, &height);

    for (int i = 0;  i < 4;  i++)
    {
        const int size = height / 5;
        const struct
        {
            float r, g, b;
        } colors[] =
        {
            { 0.95f, 0.32f, 0.11f },
            { 0.50f, 0.80f, 0.16f },
            {   0.f, 0.68f, 0.94f },
            { 0.98f, 0.74f, 0.04f }
        };

        if (i > 0)
            glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_FALSE);

        windows[i] = glfwCreateWindow(size, size, "Multi-Window Example", NULL, NULL);
        if (!windows[i])
        {
            glfwGetError(&description);
            printf("Error: %s\n", description);
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetWindowPos(windows[i],
                         xpos + size * (1 + (i & 1)),
                         ypos + size * (1 + (i >> 1)));
        glfwSetInputMode(windows[i], GLFW_STICKY_KEYS, GLFW_TRUE);

        glfwMakeContextCurrent(windows[i]);
        gladLoadGL(glfwGetProcAddress);
        glClearColor(colors[i].r, colors[i].g, colors[i].b, 1.f);
    }

    for (int i = 0;  i < 4;  i++)
        glfwShowWindow(windows[i]);

    for (;;)
    {
        for (int i = 0;  i < 4;  i++)
        {
            glfwMakeContextCurrent(windows[i]);
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(windows[i]);

            if (glfwWindowShouldClose(windows[i]) ||
                glfwGetKey(windows[i], GLFW_KEY_ESCAPE))
            {
                glfwTerminate();
                exit(EXIT_SUCCESS);
            }
        }

        glfwWaitEvents();
    }
}
