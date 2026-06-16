#pragma once

#include "imgui.h"
#include "Colors.h"

namespace UI::Style {

class Theme
{
public:
    virtual ~Theme() = default;
    virtual void Apply() = 0;
    virtual const char* GetName() const = 0;
};

class DarkTheme : public Theme
{
public:
    void Apply() override;
    const char* GetName() const override { return "Dark"; }
};

}  // namespace UI::Style
