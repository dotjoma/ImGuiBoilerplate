#pragma once

namespace UI {

enum class ScreenType
{
    Dashboard,
    Settings,
    // Add more screen types here as needed
};

class IScreen
{
public:
    virtual ~IScreen() = default;

    // Called when screen becomes active
    virtual void OnEnter() {}

    // Called every frame — draw your ImGui UI here
    virtual void OnRender() = 0;

    // Called when screen becomes inactive
    virtual void OnExit() {}

    // Getters
    virtual const char* GetTitle() const = 0;
    virtual ScreenType GetType() const = 0;
};

}  // namespace UI
