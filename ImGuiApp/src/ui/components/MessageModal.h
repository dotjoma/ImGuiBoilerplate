#pragma once

#include <string>
#include <functional>

namespace UI::Components {

enum class MessageModalType
{
    Info,
    Warning,
    Error,
    Confirmation
};

enum class MessageModalResult
{
    None,
    OK,
    Cancel,
    Yes,
    No
};

class MessageModal
{
public:
    MessageModal();
    ~MessageModal();

    void ShowInfo(const std::string& title, const std::string& message);
    void ShowWarning(const std::string& title, const std::string& message);
    void ShowError(const std::string& title, const std::string& message);
    void ShowConfirmation(const std::string& title, const std::string& message,
                          std::function<void(MessageModalResult)> callback = nullptr);
    void Render();
    bool IsShown() const { return isOpen; }

private:
    void Show(const std::string& title, const std::string& message,
              MessageModalType type, std::function<void(MessageModalResult)> callback = nullptr);
    void Close(MessageModalResult result);

    std::string title;
    std::string message;
    MessageModalType type;
    bool isOpen;
    bool shouldOpen;
    std::function<void(MessageModalResult)> callback;
};

}  // namespace UI::Components
