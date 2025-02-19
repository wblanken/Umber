#include "umpch.h"

#include "Application.h"

namespace Umber
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    void Application::Run()
    {        
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
}
