#pragma once

#include <Windows.h>

#ifndef IMGUI_IMPL_API
#define IMGUI_IMPL_API
#endif

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class GuiWindow
{
public:
    GuiWindow(const wchar_t* title, int width, int height);
    ~GuiWindow();

    bool Create();
    void Show();
    void Destroy();

    HWND GetHandle() const { return hwnd; }
    const wchar_t* GetClassName() const { return className; }

    void GetClientSize(int& outWidth, int& outHeight) const;
    bool HasResizePending() const { return resizeWidth != 0 && resizeHeight != 0; }
    void GetPendingResize(UINT& outWidth, UINT& outHeight);
    void ClearPendingResize();

    static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    HWND hwnd;
    WNDCLASSEXW wc;
    const wchar_t* className;
    const wchar_t* title;
    int width, height;

    static UINT resizeWidth;
    static UINT resizeHeight;
};
