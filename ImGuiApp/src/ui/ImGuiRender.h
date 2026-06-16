#pragma once

namespace UI {

class ImGuiRender
{
public:
    // Call once per frame — starts ImGui frame
    static void BeginFrame();

    // Render all screens and overlays
    static void Render();

    // Submit ImGui draw data (call before GPU present)
    static void EndFrame();
};

}  // namespace UI
