#pragma once

#include "imgui.h"

namespace UI::Style {

struct Colors
{
    // Brand
    static constexpr ImVec4 Primary       = ImVec4(0.26f, 0.59f, 0.98f, 1.0f);  // Standard blue
    static constexpr ImVec4 PrimaryHover  = ImVec4(0.36f, 0.69f, 1.00f, 1.0f);
    static constexpr ImVec4 PrimaryActive = ImVec4(0.20f, 0.50f, 0.88f, 1.0f);

    // Status
    static constexpr ImVec4 Success       = ImVec4(0.34f, 0.80f, 0.44f, 1.0f);
    static constexpr ImVec4 Error         = ImVec4(0.93f, 0.33f, 0.33f, 1.0f);
    static constexpr ImVec4 Warning       = ImVec4(0.98f, 0.66f, 0.20f, 1.0f);
    static constexpr ImVec4 Info          = ImVec4(0.40f, 0.80f, 1.00f, 1.0f);

    // Surfaces (dark theme)
    static constexpr ImVec4 Background    = ImVec4(0.12f, 0.13f, 0.15f, 1.0f);
    static constexpr ImVec4 Surface       = ImVec4(0.17f, 0.18f, 0.20f, 1.0f);
    static constexpr ImVec4 SurfaceLight  = ImVec4(0.22f, 0.23f, 0.25f, 1.0f);

    // Text
    static constexpr ImVec4 Text          = ImVec4(1.00f, 1.00f, 1.00f, 1.0f);
    static constexpr ImVec4 TextSecondary = ImVec4(0.72f, 0.73f, 0.78f, 1.0f);
    static constexpr ImVec4 TextMuted     = ImVec4(0.45f, 0.46f, 0.50f, 1.0f);

    // Borders
    static constexpr ImVec4 Border        = ImVec4(0.28f, 0.29f, 0.33f, 1.0f);
    static constexpr ImVec4 Disabled      = ImVec4(0.40f, 0.40f, 0.40f, 0.50f);
};

}  // namespace UI::Style
