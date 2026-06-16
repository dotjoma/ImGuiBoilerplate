#include "SettingsScreen.h"
#include "../ScreenManager.h"
#include "../components/Button.h"
#include "../components/TextField.h"
#include "../style/Colors.h"
#include "../style/Icons.h"
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

    // Back button with icon
    if (Components::Button(ICON_MS_ARROW_BACK " Back to Dashboard", ImVec2(200, 30)))
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
    ImGui::TextColored(Style::Colors::Primary, ICON_MS_SETTINGS " SETTINGS");
    ImGui::TextColored(Style::Colors::TextSecondary, "Configure your application settings");
    ImGui::Spacing();
}

void SettingsScreen::RenderAppSettings()
{
    ImGui::Text(ICON_MS_LOCK " APPLICATION");
    ImGui::Spacing();

    ImGui::Text("API Key");
    ImGui::SetNextItemWidth(400.0f);
    Components::TextField("##apikey", apiKey, 256, ImGuiInputTextFlags_Password);

    ImGui::Spacing();
    ImGui::TextColored(Style::Colors::TextMuted, ICON_MS_INFO " Your API key is used to authenticate requests.");
}

void SettingsScreen::RenderGeneralSettings()
{
    ImGui::Text(ICON_MS_BUILD " GENERAL");
    ImGui::Spacing();

    ImGui::TextColored(Style::Colors::TextMuted, "More settings will appear here as features are added.");
}

}  // namespace UI
