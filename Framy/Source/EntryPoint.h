#pragma once

#ifdef _WIN32
extern Framy::Application* CreateApplication();

int main(int argc, char** argv)
{
    Framy::Log::Init();

    Framy::Application* app = CreateApplication();
    app->Run();
    delete app;
}
#else
    #error Framy only support Windows!
#endif