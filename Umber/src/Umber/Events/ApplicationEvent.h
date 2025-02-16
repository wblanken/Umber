#pragma once

#include "umpch.h"
#include "Event.h"


namespace Umber
{
    class UMBER_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {}

        unsigned int GetWidth() const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
        
    protected:
        ~WindowResizeEvent() = default;
        
    private:
        unsigned int m_Width, m_Height;    
    };

    class UMBER_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;
    
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    
    protected:
        ~WindowCloseEvent() = default;
    };
    
    class UMBER_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() = default;
    
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    
    protected:
        ~AppTickEvent() = default;
    };
    
    class UMBER_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() = default;
    
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    
    protected:
        ~AppUpdateEvent() = default;
    };
    
    class UMBER_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() = default;
    
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    
    protected:
        ~AppRenderEvent() = default;
    };
}
