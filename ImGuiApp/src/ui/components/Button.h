#pragma once

#include "imgui.h"

namespace UI::Components {

// Styled button with theme colors
bool Button(const char* label, const ImVec2& size = ImVec2(0, 0));

// Small button variant
bool SmallButton(const char* label);

// Danger button (red) for destructive actions
bool DangerButton(const char* label, const ImVec2& size = ImVec2(0, 0));

}  // namespace UI::Components
