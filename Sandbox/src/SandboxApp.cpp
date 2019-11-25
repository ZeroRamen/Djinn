#include <Djinn.h>

class ExampleLayer : public Djinn::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Djinn::Input::IsKeyPressed(DJINN_KEY_TAB))
			Djinn_Trace("Tab Key Pressed!");

	}

	void OnEvent(Djinn::Event& event) override
	{
	}
};

class Sandbox : public Djinn::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Djinn::ImGuiLayer());
	}
	~Sandbox()
	{
	}
};

Djinn::Application* Djinn::CreateApplication()
{
	return new Sandbox();
}