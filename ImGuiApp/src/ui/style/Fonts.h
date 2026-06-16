#pragma once

#include "imgui.h"
#include <map>
#include <string>

namespace UI::Style {

/*
    FontManager — Centralized font loading for Dear ImGui

    Usage:
        auto* fm = FontManager::GetInstance();

        // Before ImGui backends init (in ImGuiManager::Initialize):
        fm->LoadDefaultFont("path/to/font.ttf", 16.0f);
        fm->MergeIconFont("path/to/icons.ttf", 16.0f, iconRange);
        fm->LoadFont("heading", "path/to/font.ttf", 24.0f);

        // At render time:
        ImGui::Text(ICON_MS_HOME " Home");           // icons are in default font
        ImGui::PushFont(fm->GetFont("heading"));      // switch to heading font
        ImGui::Text("Large Title");
        ImGui::PopFont();
*/
class FontManager
{
public:
    static FontManager* GetInstance();

    // Load the primary text font (becomes ImGui's default font).
    // Pass nullptr for filename to use ImGui's built-in font.
    ImFont* LoadDefaultFont(const char* filename = nullptr, float size = 13.0f,
                            const ImWchar* glyphRanges = nullptr);

    // Merge an icon font into the LAST loaded font (typically the default).
    // This is the standard Dear ImGui pattern — after merging, icon glyphs
    // can be used inline with text, no PushFont/PopFont needed.
    ImFont* MergeIconFont(const char* filename, float size,
                          const ImWchar* glyphRanges);

    // Load an additional named font (e.g. "heading", "mono").
    // Retrieve later with GetFont("heading").
    ImFont* LoadFont(const char* name, const char* filename, float size,
                     const ImWchar* glyphRanges = nullptr);

    // Retrieve a font by name. Returns default font if not found.
    ImFont* GetFont(const char* name);

    ImFont* GetDefaultFont() { return m_defaultFont; }

private:
    FontManager() = default;

    std::map<std::string, ImFont*> m_fonts;
    ImFont* m_defaultFont = nullptr;
};

}  // namespace UI::Style
