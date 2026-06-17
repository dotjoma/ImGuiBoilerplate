#include "Fonts.h"
#include "../../../resource.h"
#include <Windows.h>

namespace UI::Style {

FontManager* FontManager::GetInstance()
{
    static FontManager instance;
    return &instance;
}

ImFont* FontManager::LoadDefaultFont(const char* filename, float size, const ImWchar* glyphRanges)
{
    ImGuiIO& io = ImGui::GetIO();

    ImFont* font = nullptr;

    if (filename)
        font = io.Fonts->AddFontFromFileTTF(filename, size, nullptr, glyphRanges);
    else
        font = io.Fonts->AddFontDefault();

    if (font)
    {
        m_defaultFont = font;
        m_fonts["default"] = font;
    }

    return font;
}

ImFont* FontManager::MergeIconFont(const char* filename, float size, const ImWchar* glyphRanges)
{
    ImGuiIO& io = ImGui::GetIO();

    ImFontConfig config;
    config.MergeMode = true;       // Merge into the previously loaded font
    config.PixelSnapH = true;      // Snap icon glyphs to pixel grid
    config.GlyphMinAdvanceX = size; // Monospace-width icons

    // Slight vertical offset to better align icons with text
    config.GlyphOffset = ImVec2(0.0f, 4.0f); // negative values move icon upward ImVec2(0.0f, -4.0f)

    ImFont* font = nullptr;

    // Try to load from embedded resource first
    HMODULE hModule = GetModuleHandle(NULL);
    HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(IDR_MATERIAL_SYMBOLS_FONT), RT_RCDATA);
    
    if (hResource) {
        HGLOBAL hMemory = LoadResource(hModule, hResource);
        DWORD dwSize = SizeofResource(hModule, hResource);
        LPVOID lpAddress = LockResource(hMemory);
        
        if (lpAddress && dwSize > 0) {
            // Load font from memory (embedded resource)
            font = io.Fonts->AddFontFromMemoryTTF(lpAddress, dwSize, size, &config, glyphRanges);
            
            if (font) {
                // Success - loaded from embedded resource
                return font;
            }
        }
    }
    
    // Fallback: Try to load from file if resource loading failed
    font = io.Fonts->AddFontFromFileTTF(filename, size, &config, glyphRanges);

    return font;
}

ImFont* FontManager::LoadFont(const char* name, const char* filename, float size,
                              const ImWchar* glyphRanges)
{
    ImGuiIO& io = ImGui::GetIO();
    ImFont* font = io.Fonts->AddFontFromFileTTF(filename, size, nullptr, glyphRanges);

    if (font)
        m_fonts[name] = font;

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
