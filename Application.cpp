#include <GameEngine/Core/Application.h>
#include <GameEngine/Core/EntryPoint.h>
#include <GameEngine/Core/Layer.h>
#include <GameEngine/Core/InputPoll.h>
#include <GameEngine/Events/KeyEvent.h>

/**
 * 
 * 
 * @class MyApplication is a type of application for the app-developer specifically
 * @note Will be the entry point for every project created using the engine.
 * 
 * @class ExampleLayer allows in grouping context and allowing to pre-rendering things
 * @note ExampleLayer wil be the first example of how to create a layer, and how to render stuff to the screen.
 * 
*/

class ExampleLayer : public RendererEngine::Layer{
public:
    virtual void onAttach() override{}

    virtual void onDetach() override {}

    virtual void onEvent(RendererEngine::Event& event){
        if(RendererEngine::InputPoll::isKeyPressed(RendererEngine::KeyCode::Escape)){
            RendererEngine::Application::Get().close();
        }
    }


};

class MyApplication : public RendererEngine::Application{
public:
    MyApplication(RendererEngine::ApplicationCommandLineArgs args) : Application("Project", args){
        pushLayer(new ExampleLayer());
    }

    ~MyApplication() {}
};

RendererEngine::Application* RendererEngine::CreateApplication(RendererEngine::ApplicationCommandLineArgs args){
    return new MyApplication(args);
}