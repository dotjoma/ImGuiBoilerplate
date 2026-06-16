#include "MessageModal.h"
#include "imgui.h"

namespace UI::Components {

MessageModal::MessageModal()
    : isOpen(false), shouldOpen(false), type(MessageModalType::Info), callback(nullptr)
{
}

MessageModal::~MessageModal() = default;

void MessageModal::ShowInfo(const std::string& title, const std::string& message)
{
    Show(title, message, MessageModalType::Info);
}

void MessageModal::ShowWarning(const std::string& title, const std::string& message)
{
    Show(title, message, MessageModalType::Warning);
}

void MessageModal::ShowError(const std::string& title, const std::string& message)
{
    Show(title, message, MessageModalType::Error);
}

void MessageModal::ShowConfirmation(const std::string& title, const std::string& message,
                                    std::function<void(MessageModalResult)> callback)
{
    Show(title, message, MessageModalType::Confirmation, callback);
}

void MessageModal::Show(const std::string& title, const std::string& message,
                        MessageModalType type, std::function<void(MessageModalResult)> callback)
{
    this->title = title;
    this->message = message;
    this->type = type;
    this->callback = callback;
    this->shouldOpen = true;
    this->isOpen = true;
}

void MessageModal::Close(MessageModalResult result)
{
    isOpen = false;
    if (callback)
    {
        callback(result);
        callback = nullptr;
    }
    ImGui::CloseCurrentPopup();
}

void MessageModal::Render()
{
    if (!isOpen)
        return;

    if (shouldOpen)
    {
        ImGui::OpenPopup(title.c_str());
        shouldOpen = false;
    }

    float width = 250.0f;
    float height = 0.0f;

    ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Appearing);
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->GetCenter(), ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    if (ImGui::BeginPopupModal(title.c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
    {
        switch (type)
        {
        case MessageModalType::Info:
            ImGui::TextColored(ImVec4(0.0f, 0.5f, 1.0f, 1.0f), "[i]");
            break;
        case MessageModalType::Warning:
            ImGui::TextColored(ImVec4(1.0f, 0.8f, 0.0f, 1.0f), "[!]");
            break;
        case MessageModalType::Error:
            ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "[X]");
            break;
        case MessageModalType::Confirmation:
            ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "[?]");
            break;
        }

        ImGui::SameLine();
        ImGui::TextWrapped("%s", message.c_str());

        ImGui::Separator();

        if (type == MessageModalType::Confirmation)
        {
            if (ImGui::Button("Yes", ImVec2(120, 0)))
                Close(MessageModalResult::Yes);
            ImGui::SameLine();
            if (ImGui::Button("No", ImVec2(120, 0)))
                Close(MessageModalResult::No);
        }
        else
        {
            float buttonWidth = 120.0f;
            float availWidth = ImGui::GetContentRegionAvail().x;
            ImGui::SetCursorPosX((availWidth - buttonWidth) * 0.5f);

            if (ImGui::Button("OK", ImVec2(buttonWidth, 0)))
                Close(MessageModalResult::OK);
        }

        ImGui::EndPopup();
    }
    else
    {
        isOpen = false;
    }
}

}  // namespace UI::Components
