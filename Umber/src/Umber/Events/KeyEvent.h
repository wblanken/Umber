#pragma once

#include "umpch.h"
#include "Event.h"

namespace Umber
{    
    class UMBER_API KeyEvent : public Event
    {
    public:
        int GetKeyCode() const { return m_KeyCode; }
        int GetRepeatCount() const { return m_RepeatCount; }

    protected:
        ~KeyEvent() = default;

        KeyEvent(int keycode, int repeatCount)
            : m_KeyCode(keycode), m_RepeatCount(repeatCount) {}
        int m_KeyCode;
        int m_RepeatCount;
    };

    class UMBER_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode, repeatCount) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        ~KeyPressedEvent() = default;
    };

    class UMBER_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode, 0) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        ~KeyReleasedEvent() = default;
    };

    class UMBER_API KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(int keycode)
            : KeyEvent(keycode, 0) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
        
    protected:
        ~KeyTypedEvent() = default;
    };
}
