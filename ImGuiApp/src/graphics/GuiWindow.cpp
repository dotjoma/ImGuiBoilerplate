#include "GuiWindow.h"

UINT GuiWindow::resizeWidth = 0;
UINT GuiWindow::resizeHeight = 0;

GuiWindow::GuiWindow(const wchar_t* title, int width, int height)
    : hwnd(nullptr), className(title), title(title), width(width), height(height)
{
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.style = CS_CLASSDC;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = className;
}

GuiWindow::~GuiWindow()
{
    Destroy();
}

bool GuiWindow::Create()
{
    if (!::RegisterClassExW(&wc))
        return false;

    hwnd = ::CreateWindowW(
        wc.lpszClassName,
        title,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        nullptr, nullptr, wc.hInstance, nullptr);

    return hwnd != nullptr;
}

void GuiWindow::Show()
{
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);
}

void GuiWindow::Destroy()
{
    if (hwnd)
    {
        ::DestroyWindow(hwnd);
        hwnd = nullptr;
    }
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
}

void GuiWindow::GetClientSize(int& outWidth, int& outHeight) const
{
    RECT rect;
    GetClientRect(hwnd, &rect);
    outWidth = rect.right - rect.left;
    outHeight = rect.bottom - rect.top;
}

void GuiWindow::GetPendingResize(UINT& outWidth, UINT& outHeight)
{
    outWidth = resizeWidth;
    outHeight = resizeHeight;
}

void GuiWindow::ClearPendingResize()
{
    resizeWidth = 0;
    resizeHeight = 0;
}

LRESULT WINAPI GuiWindow::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        resizeWidth = (UINT)LOWORD(lParam);
        resizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
