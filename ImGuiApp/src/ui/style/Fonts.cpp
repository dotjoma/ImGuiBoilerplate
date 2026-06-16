#include "Fonts.h"

namespace UI::Style {

FontManager* FontManager::GetInstance()
{
    static FontManager instance;
    return &instance;
}

ImFont* FontManager::LoadFont(const char* filename, float size, const ImWchar* glyphRanges)
{
    ImGuiIO& io = ImGui::GetIO();
    ImFont* font = io.Fonts->AddFontFromFileTTF(filename, size, nullptr, glyphRanges);

    if (font)
    {
        m_fonts[filename] = font;
        if (!m_defaultFont)
            m_defaultFont = font;
    }

    return font;
}

ImFont* FontManager::GetFont(const char* name)
{
    auto it = m_fonts.find(name);
    if (it != m_fonts.end())
        return it->second;
    return m_defaultFont;
}

}  // namespace UI::Style
