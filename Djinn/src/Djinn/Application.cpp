#include "dngpch.h"
#include "Application.h"

namespace Djinn {
	Djinn::Application::Application()
	{
	}

	Djinn::Application::~Application()
	{
	}

	void Application::Run()
	{
		/*WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication))
			Djinn_Trace(e);
		if (e.IsInCategory(EventCategoryInput))
			Djinn_Trace(e);*/
		while (true);
	}
}
