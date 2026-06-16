#include "ImGuiRender.h"
#include "ScreenManager.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx9.h"

namespace UI {

void ImGuiRender::BeginFrame()
{
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void ImGuiRender::Render()
{
    // Render the active screen
    ScreenManager::GetInstance()->RenderCurrentScreen();

    // TODO: Add global overlays here (modals, toasts, etc.)
}

void ImGuiRender::EndFrame()
{
    ImGui::EndFrame();
    ImGui::Render();
}

}  // namespace UI
