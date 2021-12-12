#ifndef IBUTTON
#define IBUTTON

#include "IBtnController.h"

#include <memory>


/**
 * @brief Кнопка предполагаемой панели интрументов
 */
class IButton
{
public:
    IButton() = default;
    virtual ~IButton() = default;
    virtual void click() = 0;
};

/**
 * @brief Нажимательнальная кнопка
 */
class PushButton : public IButton
{
protected:
    std::unique_ptr<IBtnController> _ctrl;
public:
    PushButton(std::unique_ptr<IBtnController> ctrl) : _ctrl{std::move(ctrl)} 
    {
    }
    void click() override
    {
        _ctrl->exec();
    }
};

enum class CheckState
{
    Checked,
    Unchecked
};

/**
 * @brief Залипающая кнопка
 */
class ToggleButton : public PushButton
{
    CheckState state {CheckState::Unchecked};
public:
    ToggleButton(std::unique_ptr<IBtnController> ctrl) : PushButton(std::move(ctrl)) 
    {
    }
    void click() override
    {
        if (state == CheckState::Unchecked)
        {
            state = CheckState::Checked;
            _ctrl->exec();
        }
        else
        {
            state = CheckState::Unchecked;
            _ctrl->cancel();
        }
    }
};

#endif //IBUTTON