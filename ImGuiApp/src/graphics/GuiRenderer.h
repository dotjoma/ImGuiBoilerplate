#pragma once

#include <d3d9.h>
#include <Windows.h>

class GuiRenderer
{
public:
    GuiRenderer();
    ~GuiRenderer();

    bool Initialize(HWND hwnd);
    void Shutdown();

    bool HandleDeviceLost();
    void HandleResize(UINT width, UINT height);

    void BeginFrame();
    void EndFrame();
    void Clear(float r, float g, float b, float a);

    LPDIRECT3DDEVICE9 GetDevice() const { return pd3dDevice; }
    bool IsDeviceLost() const { return deviceLost; }

private:
    bool ResetDevice();

    LPDIRECT3D9 pD3D;
    LPDIRECT3DDEVICE9 pd3dDevice;
    D3DPRESENT_PARAMETERS d3dpp;
    bool deviceLost;
};
