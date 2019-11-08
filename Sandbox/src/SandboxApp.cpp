#include <Djinn.h>

class Sandbox : public Djinn::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Djinn::Application* Djinn::CreateApplication()
{
	return new Sandbox();
}