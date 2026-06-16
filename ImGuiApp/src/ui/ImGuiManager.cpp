#include "ImGuiManager.h"
#include "style/Theme.h"
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
