#pragma once

#include <Windows.h>

struct IDirect3DDevice9;

namespace UI {

class ImGuiManager
{
public:
    static ImGuiManager* GetInstance();

    bool Initialize(HWND hwnd, IDirect3DDevice9* device);
    void Shutdown();

    bool IsInitialized() const { return m_initialized; }

private:
    ImGuiManager() = default;
    bool m_initialized = false;
};

}  // namespace UI
