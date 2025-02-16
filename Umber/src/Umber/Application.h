#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Umber
{
    class UMBER_API Application
    {
    public:
        Application() = default;
        virtual ~Application() = default;

        void Run();       
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}
