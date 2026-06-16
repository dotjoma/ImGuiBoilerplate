#pragma once

#include "screens/IScreen.h"
#include <memory>
#include <map>

namespace UI {

class ScreenManager
{
public:
    static ScreenManager* GetInstance();

    void RegisterScreen(ScreenType type, std::unique_ptr<IScreen> screen);
    void SetActive(ScreenType type);
    void RenderCurrentScreen();

    IScreen* GetCurrentScreen() { return m_currentScreen; }
    ScreenType GetCurrentScreenType() const { return m_currentType; }

private:
    ScreenManager() = default;

    std::map<ScreenType, std::unique_ptr<IScreen>> m_screens;
    IScreen* m_currentScreen = nullptr;
    ScreenType m_currentType = ScreenType::Dashboard;
};

}  // namespace UI
