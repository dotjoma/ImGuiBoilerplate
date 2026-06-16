#include "SettingsScreen.h"
#include "../ScreenManager.h"
#include "../components/Button.h"
#include "../components/TextField.h"
#include "../style/Colors.h"
#include "imgui.h"

namespace UI {

void SettingsScreen::OnEnter()
{
    // Load saved settings here in the future
}

void SettingsScreen::OnRender()
{
    RenderHeader();

    ImGui::Separator();
    ImGui::Spacing();

    RenderAppSettings();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    RenderGeneralSettings();

    ImGui::Spacing();
    ImGui::Spacing();

    // Back button
    if (Components::Button("< Back to Dashboard", ImVec2(180, 30)))
    {
        ScreenManager::GetInstance()->SetActive(ScreenType::Dashboard);
    }
}

void SettingsScreen::OnExit()
{
    // Save settings here in the future
}

void SettingsScreen::RenderHeader()
{
    ImGui::Spacing();
    ImGui::TextColored(Style::Colors::Primary, "SETTINGS");
    ImGui::TextColored(Style::Colors::TextSecondary, "Configure your application settings");
    ImGui::Spacing();
}

void SettingsScreen::RenderAppSettings()
{
    ImGui::Text("APPLICATION");
    ImGui::Spacing();

    ImGui::Text("API Key");
    ImGui::SetNextItemWidth(400.0f);
    Components::TextField("##apikey", apiKey, 256, ImGuiInputTextFlags_Password);

    ImGui::Spacing();
    ImGui::TextColored(Style::Colors::TextMuted, "Your API key is used to authenticate requests.");
}

void SettingsScreen::RenderGeneralSettings()
{
    ImGui::Text("GENERAL");
    ImGui::Spacing();

    ImGui::TextColored(Style::Colors::TextMuted, "More settings will appear here as features are added.");
}

}  // namespace UI
