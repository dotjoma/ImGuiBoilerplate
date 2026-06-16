#pragma once

#include "IScreen.h"

namespace UI {

class DashboardScreen : public IScreen
{
public:
    void OnEnter() override;
    void OnRender() override;
    void OnExit() override;

    const char* GetTitle() const override { return "Dashboard"; }
    ScreenType GetType() const override { return ScreenType::Dashboard; }

private:
    void RenderHeader();
    void RenderStatusPanel();
    void RenderQuickActions();
    void RenderIconShowcase();
};

}  // namespace UI
