#pragma once

#ifdef UM_PLATFORM_WINDOWS

extern Umber::Application* Umber::CreateApplication();

int main(int argc, char** argv)
{
    printf("Welcome to Umber Engine!\n");
    auto app = Umber::CreateApplication();
    app->Run();
    delete app;
}

#endif