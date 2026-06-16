#pragma once

#include <string>
#include "imgui.h"

namespace UI::Components {

// Text field with std::string conversion
bool TextField(const char* label, std::string& value,
               size_t maxLength = 256, ImGuiInputTextFlags flags = 0);

// Integer field
bool IntField(const char* label, int& value);

// Float field
bool FloatField(const char* label, float& value);

}  // namespace UI::Components
