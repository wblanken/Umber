#pragma once

#include "Core.h"

namespace Umber
{
    class UMBER_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();       
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}
