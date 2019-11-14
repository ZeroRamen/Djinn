#include <Djinn.h>

class ExampleLayer : public Djinn::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		Djinn_Info("ExampleLayer::Update");
	}

	void OnEvent(Djinn::Event& event) override
	{
		Djinn_Trace("{0}", event);
	}
};

class Sandbox : public Djinn::Application
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

Djinn::Application* Djinn::CreateApplication()
{
	return new Sandbox();
}