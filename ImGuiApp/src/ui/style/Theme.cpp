#include "Theme.h"

namespace UI::Style {

void DarkTheme::Apply()
{
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();

    // Sizes
    style.WindowPadding    = ImVec2(10.0f, 10.0f);
    style.FramePadding     = ImVec2(8.0f, 6.0f);
    style.ItemSpacing      = ImVec2(8.0f, 8.0f);
    style.ItemInnerSpacing = ImVec2(6.0f, 6.0f);
    style.IndentSpacing    = 25.0f;
    style.ScrollbarSize    = 15.0f;
    style.GrabMinSize      = 10.0f;
    style.WindowBorderSize = 1.0f;
    style.ChildBorderSize  = 1.0f;
    style.PopupBorderSize  = 1.0f;
    style.FrameBorderSize  = 0.0f;

    // Rounding
    style.WindowRounding    = 7.0f;
    style.ChildRounding     = 4.0f;
    style.FrameRounding     = 3.0f;
    style.PopupRounding     = 4.0f;
    style.ScrollbarRounding = 9.0f;
    style.GrabRounding      = 3.0f;
    style.TabRounding       = 4.0f;

    // Colors — dark theme
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_WindowBg]         = Colors::Background;
    colors[ImGuiCol_ChildBg]          = Colors::Surface;
    colors[ImGuiCol_PopupBg]          = ImVec4(0.14f, 0.15f, 0.17f, 1.0f);
    colors[ImGuiCol_Border]           = Colors::Border;
    colors[ImGuiCol_FrameBg]          = Colors::SurfaceLight;
    colors[ImGuiCol_FrameBgHovered]   = ImVec4(0.27f, 0.28f, 0.32f, 1.0f);
    colors[ImGuiCol_FrameBgActive]    = ImVec4(0.30f, 0.31f, 0.35f, 1.0f);
    colors[ImGuiCol_TitleBg]          = Colors::Background;
    colors[ImGuiCol_TitleBgActive]    = Colors::Surface;
    colors[ImGuiCol_MenuBarBg]        = Colors::Surface;
    colors[ImGuiCol_ScrollbarBg]      = Colors::Background;
    colors[ImGuiCol_ScrollbarGrab]    = Colors::SurfaceLight;
    colors[ImGuiCol_CheckMark]        = Colors::Primary;
    colors[ImGuiCol_SliderGrab]       = Colors::Primary;
    colors[ImGuiCol_Button]           = Colors::Primary;
    colors[ImGuiCol_ButtonHovered]    = Colors::PrimaryHover;
    colors[ImGuiCol_ButtonActive]     = Colors::PrimaryActive;
    colors[ImGuiCol_Header]           = Colors::SurfaceLight;
    colors[ImGuiCol_HeaderHovered]    = ImVec4(0.27f, 0.28f, 0.32f, 1.0f);
    colors[ImGuiCol_HeaderActive]     = ImVec4(0.30f, 0.31f, 0.35f, 1.0f);
    colors[ImGuiCol_Separator]        = Colors::Border;
    colors[ImGuiCol_Tab]              = Colors::Surface;
    colors[ImGuiCol_TabHovered]       = Colors::Primary;
    colors[ImGuiCol_TabSelected]      = Colors::Primary;
    colors[ImGuiCol_Text]             = Colors::Text;
    colors[ImGuiCol_TextDisabled]     = Colors::TextMuted;
}

}  // namespace UI::Style
