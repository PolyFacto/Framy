#include <Framy.h>

class ExampleLayer : public Framy::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        LOG_INFO("ExampleLayer::Update");
    }

    void OnEvent(Framy::Event& event) override
    {
        LOG_TRACE("{0}", event);
    }
};

class Sandbox : public Framy::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {
    }
};

Framy::Application* CreateApplication()
{
    return new Sandbox();
}