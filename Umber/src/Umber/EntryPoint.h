#pragma once

#ifdef UM_PLATFORM_WINDOWS

extern Umber::Application* Umber::CreateApplication();

int main(int argc, char** argv)
{
    Umber::Log::Init();
    UM_CORE_WARN("Initialed Log");    
    UM_INFO("Initialed Client Log");    
    
    auto app = Umber::CreateApplication();
    app->Run();
    delete app;
}

#endif