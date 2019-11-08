#pragma once

#ifdef DJINN_PLATFORM_WINDOWS

extern Djinn::Application* Djinn::CreateApplication();

int main(int arc, char** arcv)
{
	auto app = Djinn::CreateApplication();
	app->Run();
	delete app;
}

#endif