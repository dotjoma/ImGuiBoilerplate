#pragma once

#include "IScreen.h"
#include <string>

namespace UI {

class SettingsScreen : public IScreen
{
public:
    void OnEnter() override;
    void OnRender() override;
    void OnExit() override;

    const char* GetTitle() const override { return "Settings"; }
    ScreenType GetType() const override { return ScreenType::Settings; }

private:
    void RenderHeader();
    void RenderAppSettings();
    void RenderGeneralSettings();

    // Settings data
    std::string apiKey;
};

}  // namespace UI
