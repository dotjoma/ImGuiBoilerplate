#include "DashboardScreen.h"
#include "../ScreenManager.h"
#include "../components/Button.h"
#include "../style/Colors.h"
#include "../style/Icons.h"
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

    // Top row: Status + Quick Actions
    float availWidth = ImGui::GetContentRegionAvail().x;

    ImGui::BeginChild("StatusPanel", ImVec2(availWidth * 0.6f, 150), true);
    RenderStatusPanel();
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("QuickActions", ImVec2(0, 150), true);
    RenderQuickActions();
    ImGui::EndChild();

    ImGui::Spacing();

    // Bottom: Icon showcase
    ImGui::BeginChild("IconShowcase", ImVec2(0, 0), true);
    RenderIconShowcase();
    ImGui::EndChild();
}

void DashboardScreen::OnExit()
{
    // Cleanup when leaving dashboard
}

void DashboardScreen::RenderHeader()
{
    ImGui::Spacing();
    // Icons work inline — no PushFont/PopFont needed!
    ImGui::TextColored(Style::Colors::Primary, ICON_MS_DASHBOARD " DASHBOARD");
    ImGui::SameLine();
    ImGui::TextColored(Style::Colors::TextSecondary, "- Overview");
    ImGui::Spacing();
}

void DashboardScreen::RenderStatusPanel()
{
    ImGui::Text(ICON_MS_CHECK_CIRCLE " STATUS OVERVIEW");
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::TextColored(Style::Colors::Success, ICON_MS_CHECK_CIRCLE " Everything is running normally.");
    ImGui::Spacing();
    ImGui::TextColored(Style::Colors::TextMuted, "Configure your settings to get started.");
}

void DashboardScreen::RenderQuickActions()
{
    ImGui::Text(ICON_MS_BUILD " QUICK ACTIONS");
    ImGui::Separator();
    ImGui::Spacing();

    ImVec2 buttonSize(180, 35);

    if (Components::Button(ICON_MS_SETTINGS " Settings", buttonSize))
    {
        ScreenManager::GetInstance()->SetActive(ScreenType::Settings);
    }

    ImGui::Spacing();
    ImGui::TextColored(Style::Colors::TextMuted, "More features coming soon...");
}

void DashboardScreen::RenderIconShowcase()
{
    ImGui::Text(ICON_MS_STAR " ICON SHOWCASE");
    ImGui::SameLine();
    ImGui::TextColored(Style::Colors::TextMuted, "- Material Symbols Rounded (merged into default font)");

    ImGui::Separator();
    ImGui::Spacing();

    // Icon data: { icon + label string for display, name for reference }
    struct IconEntry { const char* display; const char* name; };
    IconEntry icons[] = {
        // Navigation
        { ICON_MS_HOME " home",              "home" },
        { ICON_MS_MENU " menu",              "menu" },
        { ICON_MS_CLOSE " close",            "close" },
        { ICON_MS_ARROW_BACK " arrow_back",  "arrow_back" },
        { ICON_MS_ARROW_FORWARD " arrow_fwd","arrow_fwd" },
        { ICON_MS_EXPAND_MORE " expand_more","expand_more" },
        // Actions
        { ICON_MS_SEARCH " search",          "search" },
        { ICON_MS_SETTINGS " settings",      "settings" },
        { ICON_MS_DELETE " delete",           "delete" },
        { ICON_MS_EDIT " edit",              "edit" },
        { ICON_MS_ADD " add",                "add" },
        { ICON_MS_REFRESH " refresh",        "refresh" },
        { ICON_MS_SAVE " save",              "save" },
        { ICON_MS_COPY " copy",              "copy" },
        { ICON_MS_DOWNLOAD " download",      "download" },
        { ICON_MS_UPLOAD " upload",          "upload" },
        // Status
        { ICON_MS_CHECK_CIRCLE " check",     "check_circle" },
        { ICON_MS_ERROR " error",            "error" },
        { ICON_MS_WARNING " warning",        "warning" },
        { ICON_MS_INFO " info",              "info" },
        { ICON_MS_HELP " help",              "help" },
        // Content
        { ICON_MS_FAVORITE " favorite",      "favorite" },
        { ICON_MS_STAR " star",              "star" },
        { ICON_MS_VISIBILITY " visibility",  "visibility" },
        { ICON_MS_NOTIFICATIONS " notifs",   "notifications" },
        { ICON_MS_PERSON " person",          "person" },
        { ICON_MS_GROUP " group",            "group" },
        { ICON_MS_LOCK " lock",              "lock" },
        // Dashboard
        { ICON_MS_DASHBOARD " dashboard",    "dashboard" },
        { ICON_MS_TRENDING_UP " trend_up",   "trending_up" },
        { ICON_MS_TRENDING_DOWN " trend_dn", "trending_down" },
        { ICON_MS_BAR_CHART " bar_chart",    "bar_chart" },
        { ICON_MS_SCHEDULE " schedule",      "schedule" },
        // Files
        { ICON_MS_FOLDER " folder",          "folder" },
        { ICON_MS_DESCRIPTION " desc",       "description" },
        { ICON_MS_ATTACH_FILE " attach",     "attach_file" },
        // Media
        { ICON_MS_PLAY_ARROW " play",        "play_arrow" },
        { ICON_MS_PAUSE " pause",            "pause" },
        { ICON_MS_STOP " stop",              "stop" },
        { ICON_MS_VOLUME_UP " vol_up",       "volume_up" },
        // Misc
        { ICON_MS_LIGHT_MODE " light",       "light_mode" },
        { ICON_MS_DARK_MODE " dark",         "dark_mode" },
        { ICON_MS_CODE " code",              "code" },
        { ICON_MS_BUG_REPORT " bug",         "bug_report" },
        { ICON_MS_BUILD " build",            "build" },
        { ICON_MS_POWER_SETTINGS_NEW " power","power" },
    };

    int count = sizeof(icons) / sizeof(icons[0]);
    float cellWidth = 130.0f;
    float availWidth = ImGui::GetContentRegionAvail().x;
    int columns = (int)(availWidth / cellWidth);
    if (columns < 1) columns = 1;

    int col = 0;
    for (int i = 0; i < count; i++)
    {
        ImGui::TextColored(Style::Colors::TextSecondary, "%s", icons[i].display);

        col++;
        if (col < columns && i < count - 1)
            ImGui::SameLine(col * cellWidth);
        else
            col = 0;
    }
}

}  // namespace UI
