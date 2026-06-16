#include "ImGuiManager.h"
#include "style/Theme.h"
#include "style/Fonts.h"
#include "style/Icons.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx9.h"
#include <d3d9.h>

namespace UI {

ImGuiManager* ImGuiManager::GetInstance()
{
    static ImGuiManager instance;
    return &instance;
}

bool ImGuiManager::Initialize(HWND hwnd, IDirect3DDevice9* device)
{
    if (m_initialized)
        return true;

    // Create ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Configure ImGui
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    // Apply theme
    Style::DarkTheme theme;
    theme.Apply();

    // ─── Load Fonts ──────────────────────────────────────
    // Font loading must happen BEFORE backend init so the atlas is built correctly.
    //
    // The standard Dear ImGui icon font pattern:
    //   1. Load your text font (becomes the default)
    //   2. Merge icon font into it (MergeMode = true)
    //   3. Now icon glyphs are part of the default font — no PushFont/PopFont needed
    //
    // After this, you can write:
    //   ImGui::Text(ICON_MS_HOME " Dashboard");
    //   ImGui::Button(ICON_MS_SAVE " Save");

    auto* fontMgr = Style::FontManager::GetInstance();

    // 1. Load default text font (pass nullptr to use ImGui's built-in font)
    ImFontConfig config;
    config.SizePixels = 13.0f;  // Explicit size
    io.Fonts->AddFontDefault(&config);

    // 2. Merge Material Symbols Rounded icons into the default font
    fontMgr->MergeIconFont(
        "vendor/fonts/Material_Symbols_Rounded/static/MaterialSymbolsRounded_Filled-Bold.ttf",
        18.0f,
        ICON_MS_RANGE
    );

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(device);

    m_initialized = true;
    return true;
}

void ImGuiManager::Shutdown()
{
    if (!m_initialized)
        return;

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    m_initialized = false;
}

}  // namespace UI
