#pragma once

#include "Djinn/Window.h"

#include <GLFW/glfw3.h>

struct GLFWwindow;

namespace Djinn
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width;  }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		LRESULT CALLBACK DjinnProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		inline virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		//GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width = 0, Height = 0;
			bool VSync = false;

			EventCallbackFn EventCallback;
		};

		WindowData	m_Data;				// Storage for window values & event callback
		HWND		m_Window;			// Handler to window
		HINSTANCE	m_Instance;			// Handle to application instance
	};
	extern WindowsWindow* pWindow;
}


