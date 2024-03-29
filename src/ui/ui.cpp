#include <random>
#include <climits>
#include <ctime>
#include <vector>
#include <imgui.h>
#include <implot.h>

#include "ui.h"

namespace myProject
{
    static bool show_demo_window = true;
    static bool show_another_window = false;

    static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    static void drawFirstWindow();
    static void drawSecondWindow();
    static void drawThirdWindow();
    static void drawFourthWindow();
    static void drawFifthWindow();

    void renderUI()
    {
        drawFirstWindow();
        drawSecondWindow();
        drawThirdWindow();
        drawFourthWindow();
        drawFifthWindow();
    }   

    static void drawFirstWindow()
    {
        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
        {
            ImGui::ShowDemoWindow(&show_demo_window);
        }
    }

    static void drawSecondWindow()
    {
        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))
        {                                                       // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        }

        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }

    static void drawThirdWindow()
    {
        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
            {
                show_another_window = false;
            }
            ImGui::End();
        }
    }

    static void drawFourthWindow()
    {
        static std::default_random_engine randomEngine(time(nullptr));
        static std::uniform_real_distribution<double> distribution(std::numeric_limits<double>::min(),
                                                                   std::numeric_limits<double>::max());

        static std::vector<double> data;
        
        for (int i = 0; i < 10; i++)
        {
            data.emplace_back(distribution(randomEngine));
        }

        ImGui::Begin("My Window");
        if (ImPlot::BeginPlot("My Plot"))
        {
            ImPlot::PlotBars("My Bar Plot", &data[0], data.size());
            ImPlot::EndPlot();
        }
        ImGui::End();
    }

    static void drawFifthWindow()
    {
        ImPlot::ShowDemoWindow();
    }
}