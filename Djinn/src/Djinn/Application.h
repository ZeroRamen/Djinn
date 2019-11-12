#pragma once

#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Djinn {
	class DJINN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be created in client
	Application* CreateApplication();
}

