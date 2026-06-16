#pragma once

#include "imgui.h"
#include <map>
#include <string>

namespace UI::Style {

class FontManager
{
public:
    static FontManager* GetInstance();

    ImFont* LoadFont(const char* filename, float size, const ImWchar* glyphRanges = nullptr);
    ImFont* GetFont(const char* name);
    ImFont* GetDefaultFont() { return m_defaultFont; }

private:
    FontManager() = default;

    std::map<std::string, ImFont*> m_fonts;
    ImFont* m_defaultFont = nullptr;
};

}  // namespace UI::Style
