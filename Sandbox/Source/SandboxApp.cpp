#include <Framy.h>

class Sandbox : public Framy::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Framy::Application* CreateApplication()
{
    return new Sandbox();
}