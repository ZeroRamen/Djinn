#pragma once

namespace Djinn {
	class _declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
}

