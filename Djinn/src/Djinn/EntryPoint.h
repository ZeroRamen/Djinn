#pragma once

#ifdef DJINN_PLATFORM_WINDOWS

extern Djinn::Application* Djinn::CreateApplication();

int main(int arc, char** arcv)
{
	Djinn::Log::Init();
	Djinn_Core_Info("Initialized Log!");

	Djinn_Core_Warn("Testing warning log!");
	Djinn_Core_Error("Testing error log!");
	Djinn_Core_Trace("Testing trace log!");
	Djinn_Core_Fatal("Testing fatal log!");
	Djinn_Core_Info("Testing info log!");

	Djinn_Warn("Testing warning log!");
	Djinn_Error("Testing error log!");
	Djinn_Trace("Testing trace log!");
	Djinn_Fatal("Testing fatal log!");
	Djinn_Info("Testing info log!");

	auto app = Djinn::CreateApplication();
	app->Run();
	delete app;
}

#endif