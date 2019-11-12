#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include "Window.h"

namespace Djinn {
	class DJINN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be created in client
	Application* CreateApplication();
}

