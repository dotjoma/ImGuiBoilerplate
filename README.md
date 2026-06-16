# ImGui Boilerplate

A clean, ready-to-use **Dear ImGui** boilerplate built with **DirectX 9** and **Win32**. Designed as a starting point for desktop GUI applications on Windows.

<p align="center">
  <img src="image.png" alt="ImGui Boilerplate" width="700"/>
</p>

## Features

- **Dear ImGui** with D3D9 + Win32 backend
- **Screen management system** — easily add and switch between screens
- **Dark theme** with a full color system (`Colors.h`)
- **Reusable UI components** — Button, TextField, MessageModal
- **Font manager** — load and manage custom fonts
- **Device lost handling** — graceful D3D9 recovery and window resize support
- **C++20** — modern language standard

## Project Structure

```
ImGuiApp/
├── main.cpp                        # Entry point & app lifecycle
├── src/
│   ├── graphics/
│   │   ├── GuiWindow.h/cpp         # Win32 window wrapper
│   │   └── GuiRenderer.h/cpp       # D3D9 renderer
│   └── ui/
│       ├── ImGuiManager.h/cpp      # ImGui initialization & shutdown
│       ├── ImGuiRender.h/cpp       # Per-frame ImGui rendering
│       ├── ScreenManager.h/cpp     # Screen registration & switching
│       ├── screens/
│       │   ├── IScreen.h           # Screen interface + ScreenType enum
│       │   ├── DashboardScreen     # Example: dashboard screen
│       │   └── SettingsScreen      # Example: settings screen
│       ├── components/
│       │   ├── Button              # Styled button variants
│       │   ├── TextField           # Text/int/float input fields
│       │   └── MessageModal        # Info/warning/error/confirm modal
│       └── style/
│           ├── Colors.h            # Color palette constants
│           ├── Theme.h/cpp         # Theme base class + DarkTheme
│           └── Fonts.h/cpp         # Font loading & management
└── vendor/
    └── ImGui/                      # Dear ImGui source (vendored)
```

## Requirements

- **Visual Studio 2022** (v145 toolset)
- **Windows SDK 10.0**
- **DirectX 9 SDK** (ships with Windows SDK)

## Getting Started

1. Open `ImGuiApp.slnx` in Visual Studio
2. Set build configuration to **Debug | x64**
3. Build and run (F5)

## Adding a New Screen

1. Create `MyScreen.h` and `MyScreen.cpp` in `src/ui/screens/`
2. Add `MyScreen` to the `ScreenType` enum in `IScreen.h`
3. Register it in `main.cpp`:

```cpp
#include "src/ui/screens/MyScreen.h"

// In main(), after the other RegisterScreen calls:
screenMgr->RegisterScreen(UI::ScreenType::MyScreen, std::make_unique<UI::MyScreen>());
```

## Screen Interface

Every screen implements `IScreen`:

```cpp
class MyScreen : public IScreen
{
public:
    void OnEnter() override;   // Called when screen becomes active
    void OnRender() override;  // Called every frame — draw ImGui here
    void OnExit() override;    // Called when screen becomes inactive

    const char* GetTitle() const override { return "My Screen"; }
    ScreenType GetType() const override { return ScreenType::MyScreen; }
};
```

## Using Components

```cpp
#include "src/ui/components/Button.h"
#include "src/ui/components/TextField.h"

// Styled button
if (UI::Components::Button("Click Me", ImVec2(120, 30))) { /* ... */ }

// Danger button (red)
if (UI::Components::DangerButton("Delete", ImVec2(120, 30))) { /* ... */ }

// Text field bound to std::string
std::string name;
UI::Components::TextField("##name", name);
```

## License

This project is provided as a boilerplate — use it however you like.
