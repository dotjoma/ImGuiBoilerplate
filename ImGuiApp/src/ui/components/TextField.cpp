#include "TextField.h"

namespace UI::Components {

bool TextField(const char* label, std::string& value,
               size_t maxLength, ImGuiInputTextFlags flags)
{
    // Use a temporary buffer for ImGui
    char buffer[512] = {};

    if (value.length() < maxLength)
        strcpy_s(buffer, value.c_str());
    else
        strncpy_s(buffer, value.c_str(), maxLength - 1);

    bool changed = ImGui::InputText(label, buffer, maxLength, flags);

    if (changed)
        value = buffer;

    return changed;
}

bool IntField(const char* label, int& value)
{
    return ImGui::InputInt(label, &value);
}

bool FloatField(const char* label, float& value)
{
    return ImGui::InputFloat(label, &value);
}

}  // namespace UI::Components
