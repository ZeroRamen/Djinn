#include "dngpch.h"
#include "Application.h"

namespace Djinn {
	Djinn::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Djinn::Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
