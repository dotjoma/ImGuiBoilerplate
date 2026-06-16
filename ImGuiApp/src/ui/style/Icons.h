#pragma once

#include "imgui.h"

/*
    Material Symbols Rounded — Icon Codepoints for Dear ImGui

    These are pre-computed UTF-8 string literals for Material Symbols Rounded
    icon codepoints. They are designed to be merged into your default ImGui
    font so you can use them inline with regular text — no PushFont/PopFont needed.

    Setup (done automatically in ImGuiManager.cpp):
        ImGuiIO& io = ImGui::GetIO();
        io.Fonts->AddFontDefault();                               // or your text font
        ImFontConfig config;
        config.MergeMode = true;
        config.GlyphMinAdvanceX = 13.0f;
        io.Fonts->AddFontFromFileTTF("icons.ttf", 13.0f, &config, ICON_MS_RANGE);

    Usage — icons work inline with text, no font switching required:
        ImGui::Text(ICON_MS_HOME " Dashboard");
        ImGui::Button(ICON_MS_SETTINGS " Settings");
        if (ImGui::MenuItem(ICON_MS_SAVE " Save")) { ... }

    Browse all icons at: https://fonts.google.com/icons?icon.set=Material+Symbols
*/

// ─── Glyph Range ─────────────────────────────────────────
// Pass this to AddFontFromFileTTF() as the glyph_ranges parameter.
// Covers the Material Symbols Private Use Area (U+E000–U+F8FF).
static const ImWchar ICON_MS_RANGE[] = { 0xE000, 0xF8FF, 0 };

// Min/max codepoints (useful for custom range building)
#define ICON_MS_MIN 0xE000
#define ICON_MS_MAX 0xF8FF

// ─── Navigation ──────────────────────────────────────────
#define ICON_MS_HOME                "\xEE\xA2\x8A"  // U+E88A
#define ICON_MS_MENU                "\xEE\x97\x92"  // U+E5D2
#define ICON_MS_CLOSE               "\xEE\x97\x8D"  // U+E5CD
#define ICON_MS_ARROW_BACK          "\xEE\x97\x84"  // U+E5C4
#define ICON_MS_ARROW_FORWARD       "\xEE\x97\x88"  // U+E5C8
#define ICON_MS_EXPAND_MORE         "\xEE\x97\x8F"  // U+E5CF
#define ICON_MS_EXPAND_LESS         "\xEE\x97\x8E"  // U+E5CE

// ─── Actions ─────────────────────────────────────────────
#define ICON_MS_SEARCH              "\xEE\xA2\xB6"  // U+E8B6
#define ICON_MS_SETTINGS            "\xEE\xA2\xB8"  // U+E8B8
#define ICON_MS_DELETE              "\xEE\xA1\xB2"  // U+E872
#define ICON_MS_EDIT                "\xEE\x8F\x89"  // U+E3C9
#define ICON_MS_ADD                 "\xEE\x85\x85"  // U+E145
#define ICON_MS_REFRESH             "\xEE\x97\x95"  // U+E5D5
#define ICON_MS_SAVE                "\xEE\x85\xA1"  // U+E161
#define ICON_MS_COPY                "\xEE\x85\x8D"  // U+E14D
#define ICON_MS_DOWNLOAD            "\xEF\x82\x90"  // U+F090
#define ICON_MS_UPLOAD              "\xEF\x82\x9B"  // U+F09B

// ─── Status / Alerts ─────────────────────────────────────
#define ICON_MS_CHECK_CIRCLE        "\xEE\xA1\xAC"  // U+E86C
#define ICON_MS_ERROR               "\xEE\x80\x80"  // U+E000
#define ICON_MS_WARNING             "\xEE\x80\x82"  // U+E002
#define ICON_MS_INFO                "\xEE\xA2\x8E"  // U+E88E
#define ICON_MS_HELP                "\xEE\xA2\x87"  // U+E887

// ─── Content ─────────────────────────────────────────────
#define ICON_MS_FAVORITE            "\xEE\xA1\xBD"  // U+E87D
#define ICON_MS_STAR                "\xEE\xA0\xB8"  // U+E838
#define ICON_MS_VISIBILITY          "\xEE\xA3\xB4"  // U+E8F4
#define ICON_MS_VISIBILITY_OFF      "\xEE\xA3\xB5"  // U+E8F5
#define ICON_MS_NOTIFICATIONS       "\xEE\x9F\xB4"  // U+E7F4
#define ICON_MS_PERSON              "\xEE\x9F\xBD"  // U+E7FD
#define ICON_MS_GROUP               "\xEE\x9F\xAF"  // U+E7EF
#define ICON_MS_LOCK                "\xEE\xA2\x97"  // U+E897
#define ICON_MS_LOCK_OPEN           "\xEE\xA2\x98"  // U+E898

// ─── Dashboard / Data ────────────────────────────────────
#define ICON_MS_DASHBOARD           "\xEE\xA1\xB1"  // U+E871
#define ICON_MS_ANALYTICS           "\xEE\xBC\xBE"  // U+EF3E
#define ICON_MS_TRENDING_UP         "\xEE\xA3\xA5"  // U+E8E5
#define ICON_MS_TRENDING_DOWN       "\xEE\xA3\xA3"  // U+E8E3
#define ICON_MS_BAR_CHART           "\xEE\x89\xAB"  // U+E26B
#define ICON_MS_SCHEDULE            "\xEE\xA2\xB5"  // U+E8B5

// ─── Files / Folders ─────────────────────────────────────
#define ICON_MS_FOLDER              "\xEE\x8B\x87"  // U+E2C7
#define ICON_MS_FOLDER_OPEN         "\xEE\x8B\x88"  // U+E2C8
#define ICON_MS_DESCRIPTION         "\xEE\xA1\xB3"  // U+E873
#define ICON_MS_ATTACH_FILE         "\xEE\x88\xA6"  // U+E226

// ─── Media ───────────────────────────────────────────────
#define ICON_MS_PLAY_ARROW          "\xEE\x80\xB7"  // U+E037
#define ICON_MS_PAUSE               "\xEE\x80\xB4"  // U+E034
#define ICON_MS_STOP                "\xEE\x81\x87"  // U+E047
#define ICON_MS_VOLUME_UP           "\xEE\x81\x90"  // U+E050
#define ICON_MS_VOLUME_OFF          "\xEE\x81\x8F"  // U+E04F

// ─── Misc ────────────────────────────────────────────────
#define ICON_MS_LIGHT_MODE          "\xEE\x94\x98"  // U+E518
#define ICON_MS_DARK_MODE           "\xEE\x94\x9C"  // U+E51C
#define ICON_MS_LANGUAGE            "\xEE\xA2\x94"  // U+E894
#define ICON_MS_CODE                "\xEE\xA1\xAF"  // U+E86F
#define ICON_MS_BUG_REPORT          "\xEE\xA1\xA8"  // U+E868
#define ICON_MS_BUILD               "\xEE\xA1\xA9"  // U+E869
#define ICON_MS_POWER_SETTINGS_NEW  "\xEE\xA2\xAC"  // U+E8AC
