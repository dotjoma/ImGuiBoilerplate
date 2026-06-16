#include "DashboardScreen.h"
#include "../ScreenManager.h"
#include "../components/Button.h"
#include "../style/Colors.h"
#include "imgui.h"

namespace UI {

void DashboardScreen::OnEnter()
{
    // Initialize dashboard data when entering
}

void DashboardScreen::OnRender()
{
    RenderHeader();

    ImGui::Separator();
    ImGui::Spacing();

    // Two-column layout
    float availWidth = ImGui::GetContentRegionAvail().x;

    ImGui::BeginChild("StatusPanel", ImVec2(availWidth * 0.6f, 0), true);
    RenderStatusPanel();
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("QuickActions", ImVec2(0, 0), true);
    RenderQuickActions();
    ImGui::EndChild();
}

void DashboardScreen::OnExit()
{
    // Cleanup when leaving dashboard
}

void DashboardScreen::RenderHeader()
{
    ImGui::Spacing();
    ImGui::TextColored(Style::Colors::Primary, "DASHBOARD");
    ImGui::SameLine();
    ImGui::TextColored(Style::Colors::TextSecondary, "- Overview");
    ImGui::Spacing();
}

void DashboardScreen::RenderStatusPanel()
{
    ImGui::Text("STATUS OVERVIEW");
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::TextColored(Style::Colors::TextSecondary, "Everything is running normally.");
    ImGui::Spacing();
    ImGui::TextColored(Style::Colors::TextMuted, "Configure your settings to get started.");
}

void DashboardScreen::RenderQuickActions()
{
    ImGui::Text("QUICK ACTIONS");
    ImGui::Separator();
    ImGui::Spacing();

    ImVec2 buttonSize(180, 35);

    if (Components::Button("Settings", buttonSize))
    {
        ScreenManager::GetInstance()->SetActive(ScreenType::Settings);
    }

    ImGui::Spacing();

    ImGui::TextColored(Style::Colors::TextMuted, "More features coming soon...");
}

}  // namespace UI
