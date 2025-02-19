#include "umpch.h"
#include "Win_Window.h"

namespace Umber
{
    static bool s_GLFWInitialized = false;
    Window* Window::Create(const WindowProps& props)
    {
        return new Win_Window(props);        
    }
    
    Win_Window::Win_Window(const WindowProps& props)
    {
        Win_Window::Init(props);
    }

    Win_Window::~Win_Window()
    {
        Win_Window::Shutdown();        
    }

    void Win_Window::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        UM_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            UM_CORE_ASSERT(success, "Could not initialize GLFW!");
            
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(static_cast<int>(props.Width), static_cast<int>(props.Height), m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void Win_Window::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void Win_Window::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void Win_Window::SetVSync(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }

    bool Win_Window::IsVSync() const
    {
        return m_Data.VSync;
    }
}
