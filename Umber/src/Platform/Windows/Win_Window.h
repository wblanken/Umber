#pragma once
#include "Umber/Window.h"

#include <GLFW/glfw3.h>

namespace Umber
{
    class UMBER_API Win_Window : public Window
    {
    public:
        explicit Win_Window(const WindowProps& props);
        virtual ~Win_Window();
        
        void OnUpdate() override;

        inline unsigned GetWidth() const override { return m_Data.Width; }
        inline unsigned GetHeight() const override { return m_Data.Height; }        
        
        void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        } m_Data;
    };
}
