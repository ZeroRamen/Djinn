#pragma once

#ifdef DJINN_PLATFORM_WINDOWS

extern Djinn::Application* Djinn::CreateApplication();

int main(int arc, char** arcv)
{
	Djinn::Log::Init();
	Djinn_Core_Warn("Initialized Log!");
	int a = 5;
	Djinn_Info("Hello var={0}", a);

	auto app = Djinn::CreateApplication();
	app->Run();
	delete app;
}

#endif