#include <Umber.h>

class Sandbox : public Umber::Application
{
public:
    Sandbox() {}
    ~Sandbox() {}
};

Umber::Application* Umber::CreateApplication()
{
    return new Sandbox();
}