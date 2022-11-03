/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2022 Filipe Coelho <falktx@falktx.com>
 * SPDX-License-Identifier: ISC
 */

#include "Application.hpp"
#include "DearImGui.hpp"

class DemoWindow : public ImGuiStandaloneWindow
{
public:
    explicit DemoWindow(Application& app)
        : ImGuiStandaloneWindow(app)
    {
        setGeometryConstraints(300, 200);
        setResizable(true);
        setTitle("DPF + ImGui Demo");
    }

protected:
    void onImGuiDisplay() override
    {
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(getWidth(), getHeight()));
        ImGui::ShowDemoWindow();
    }
};

int main(int, char**)
{
    Application app;
    DemoWindow win(app);
    win.show();
    app.exec();
    return 0;
}
