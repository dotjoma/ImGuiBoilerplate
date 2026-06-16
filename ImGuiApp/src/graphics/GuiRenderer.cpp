#include "GuiRenderer.h"
#include "imgui_impl_dx9.h"

GuiRenderer::GuiRenderer()
    : pD3D(nullptr), pd3dDevice(nullptr), deviceLost(false)
{
    ZeroMemory(&d3dpp, sizeof(d3dpp));
}

GuiRenderer::~GuiRenderer()
{
    Shutdown();
}

bool GuiRenderer::Initialize(HWND hwnd)
{
    if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == nullptr)
        return false;

    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

    if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
        D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &pd3dDevice) < 0)
        return false;

    return true;
}

void GuiRenderer::Shutdown()
{
    if (pd3dDevice)
    {
        pd3dDevice->Release();
        pd3dDevice = nullptr;
    }
    if (pD3D)
    {
        pD3D->Release();
        pD3D = nullptr;
    }
}

bool GuiRenderer::HandleDeviceLost()
{
    if (!deviceLost)
        return true;

    HRESULT hr = pd3dDevice->TestCooperativeLevel();
    if (hr == D3DERR_DEVICELOST)
    {
        ::Sleep(10);
        return false;
    }
    if (hr == D3DERR_DEVICENOTRESET)
    {
        if (!ResetDevice())
            return false;
    }
    deviceLost = false;
    return true;
}

void GuiRenderer::HandleResize(UINT width, UINT height)
{
    d3dpp.BackBufferWidth = width;
    d3dpp.BackBufferHeight = height;
    ResetDevice();
}

void GuiRenderer::BeginFrame()
{
    pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
    pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
}

void GuiRenderer::EndFrame()
{
    HRESULT result = pd3dDevice->Present(nullptr, nullptr, nullptr, nullptr);
    if (result == D3DERR_DEVICELOST)
        deviceLost = true;
}

void GuiRenderer::Clear(float r, float g, float b, float a)
{
    D3DCOLOR color = D3DCOLOR_RGBA(
        (int)(r * a * 255.0f),
        (int)(g * a * 255.0f),
        (int)(b * a * 255.0f),
        (int)(a * 255.0f)
    );
    pd3dDevice->Clear(0, nullptr, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 1.0f, 0);
}

bool GuiRenderer::ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = pd3dDevice->Reset(&d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        return false;
    ImGui_ImplDX9_CreateDeviceObjects();
    return true;
}
