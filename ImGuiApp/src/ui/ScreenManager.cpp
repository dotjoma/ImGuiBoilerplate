#include "ScreenManager.h"

namespace UI {

ScreenManager* ScreenManager::GetInstance()
{
    static ScreenManager instance;
    return &instance;
}

void ScreenManager::RegisterScreen(ScreenType type, std::unique_ptr<IScreen> screen)
{
    m_screens[type] = std::move(screen);
}

void ScreenManager::SetActive(ScreenType type)
{
    // Exit current screen
    if (m_currentScreen)
        m_currentScreen->OnExit();

    // Activate new screen
    auto it = m_screens.find(type);
    if (it != m_screens.end())
    {
        m_currentScreen = it->second.get();
        m_currentType = type;
        m_currentScreen->OnEnter();
    }
}

void ScreenManager::RenderCurrentScreen()
{
    if (m_currentScreen)
        m_currentScreen->OnRender();
}

}  // namespace UI
