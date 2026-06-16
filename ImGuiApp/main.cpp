/*
    Entry Point

    Architecture:
    - src/graphics/  → D3D9 renderer + Win32 window
    - src/ui/        → ImGui UI layer (screens, components, style)
    - main.cpp       → This file (app lifecycle)

    Adding a new screen:
    1. Create MyScreen.h/cpp in src/ui/screens/
    2. Add ScreenType::MyScreen to IScreen.h enum
    3. Register it below with screenMgr->RegisterScreen(...)
*/

#include "src/graphics/GuiWindow.h"
#include "src/graphics/GuiRenderer.h"
#include "src/ui/ImGuiManager.h"
#include "src/ui/ImGuiRender.h"
#include "src/ui/ScreenManager.h"
#include "src/ui/screens/DashboardScreen.h"
#include "src/ui/screens/SettingsScreen.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <memory>

int main()
{
    // ─── Create Window ───────────────────────────────────
    ImGui_ImplWin32_EnableDpiAwareness();

    auto window = std::make_unique<GuiWindow>(L"ImGui Application", 800, 600);
    if (!window->Create())
        return 1;

    // ─── Initialize D3D9 Renderer ────────────────────────
    auto renderer = std::make_unique<GuiRenderer>();
    if (!renderer->Initialize(window->GetHandle()))
    {
        window->Destroy();
        return 1;
    }

    window->Show();

    // ─── Initialize ImGui ────────────────────────────────
    UI::ImGuiManager::GetInstance()->Initialize(window->GetHandle(), renderer->GetDevice());

    // ─── Register Screens ────────────────────────────────
    // Add new screens here:
    //   screenMgr->RegisterScreen(UI::ScreenType::MyScreen, std::make_unique<UI::MyScreen>());
    UI::ScreenManager* screenMgr = UI::ScreenManager::GetInstance();
    screenMgr->RegisterScreen(UI::ScreenType::Dashboard, std::make_unique<UI::DashboardScreen>());
    screenMgr->RegisterScreen(UI::ScreenType::Settings, std::make_unique<UI::SettingsScreen>());
    screenMgr->SetActive(UI::ScreenType::Dashboard);

    // ─── Main Loop ───────────────────────────────────────
    bool running = true;
    while (running)
    {
        // Handle Windows messages
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                running = false;
        }

        if (!running)
            break;

        // Handle lost D3D9 device
        if (!renderer->HandleDeviceLost())
            continue;

        // Handle window resize
        if (window->HasResizePending())
        {
            UINT w, h;
            window->GetPendingResize(w, h);
            renderer->HandleResize(w, h);
            window->ClearPendingResize();
        }

        // Get window size for full-screen ImGui window
        int width, height;
        window->GetClientSize(width, height);

        // ─── ImGui Frame ─────────────────────────────────
        UI::ImGuiRender::BeginFrame();

        // Create a full-window ImGui container
        ImGuiWindowFlags flags =
            ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove |
            ImGuiWindowFlags_NoCollapse |
            ImGuiWindowFlags_NoBringToFrontOnFocus
        ;

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2((float)width, (float)height));

        ImGui::Begin("ImGui Application##MainWindow", nullptr, flags);
        UI::ImGuiRender::Render();
        ImGui::End();

        UI::ImGuiRender::EndFrame();

        // ─── GPU Render ──────────────────────────────────
        renderer->BeginFrame();
        renderer->Clear(0.12f, 0.13f, 0.15f, 1.0f);

        if (renderer->GetDevice()->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            renderer->GetDevice()->EndScene();
        }

        renderer->EndFrame();
    }

    // ─── Cleanup ─────────────────────────────────────────
    UI::ImGuiManager::GetInstance()->Shutdown();

    renderer->Shutdown();
    window->Destroy();

    return 0;
}
