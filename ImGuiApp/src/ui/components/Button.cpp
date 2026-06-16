#include "Button.h"
#include "../style/Colors.h"

namespace UI::Components {

bool Button(const char* label, const ImVec2& size)
{
    ImGui::PushStyleColor(ImGuiCol_Button, Style::Colors::Primary);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, Style::Colors::PrimaryHover);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, Style::Colors::PrimaryActive);

    bool clicked = ImGui::Button(label, size);

    ImGui::PopStyleColor(3);
    return clicked;
}

bool SmallButton(const char* label)
{
    return ImGui::SmallButton(label);
}

bool DangerButton(const char* label, const ImVec2& size)
{
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.80f, 0.20f, 0.20f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.93f, 0.33f, 0.33f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.70f, 0.15f, 0.15f, 1.0f));

    bool clicked = ImGui::Button(label, size);

    ImGui::PopStyleColor(3);
    return clicked;
}

}  // namespace UI::Components
