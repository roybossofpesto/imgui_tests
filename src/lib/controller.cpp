#include "mcommon.h" 
#include "controller.h"
#include "display.h"
#include "imgui.h"

namespace StarterKit
{

void Controller::Render(const Rect4f& rc)
{
    // TODO: App display
    GetDisplay()->DrawRectFilled(rc.TopLeft(), rc.BottomRight(), 0xFF333333);
    GetDisplay()->DrawRectFilled(rc.TopLeft(), rc.TopLeft() + glm::vec2(100, 100), 0xFFFFFFFF);
    GetDisplay()->DrawLine(rc.TopLeft() + glm::vec2(100, 100), rc.TopLeft() + glm::vec2(110, 110), 0xFFFFFF00, 2);
    GetDisplay()->DrawChars(rc.TopLeft() + glm::vec2(120, 120), 0xFFFF8866, "Prout");

    // Create a window called "My First Tool", with a menu bar.
    bool my_tool_active = false;

    ImGui::Begin("My First Tool", &my_tool_active, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
            if (ImGui::MenuItem("Save", "Ctrl+S"))   { /* Do stuff */ }
            if (ImGui::MenuItem("Close", "Ctrl+W"))  { my_tool_active = false; }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::End();
}

}
