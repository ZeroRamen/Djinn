#include "dngpch.h"
#include "WindowsWindow.h"

#include "Djinn/Events/ApplicationEvent.h"
#include "Djinn/Events/KeyEvent.h"
#include "Djinn/Events/MouseEvent.h"

#include <glad/glad.h>

namespace Djinn
{
	WindowsWindow* pWindow = nullptr;

	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (pWindow)
			return pWindow->DjinnProc(hWnd, msg, wParam, lParam);
		else
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	Window* Window::Create(const WindowProps& props)
	{
		pWindow = new WindowsWindow(props);
		return pWindow;
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow() 
	{ 
		Shutdown(); 
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		std::wstring winText(m_Data.Title.begin(), m_Data.Title.end());

		Djinn_Core_Info("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		// Register the window class.
		const wchar_t CLASS_NAME[] = L"Sample Window Class";

		WNDCLASS wc = { };

		wc.lpfnWndProc = WndProc;
		wc.hInstance = m_Instance;
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);
		
		HWND hWnd = CreateWindowEx(
			0,                              // Optional window styles.
			CLASS_NAME,                     // Window class
			winText.c_str(),				// Window text
			WS_OVERLAPPEDWINDOW,            // Window style

			// Size and position
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

			NULL,       // Parent window    
			NULL,       // Menu
			m_Instance, // Instance handle
			NULL        // Additional application data
		);

		if (hWnd == NULL) throw 0;
		ShowWindow(hWnd, SW_SHOW);

		/*if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			DJINN_CORE_ASSERT(success, "Could Not Initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}*/
		/*m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int stats = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		DJINN_CORE_ASSERT(status, "Failed to initialize Glad!");
		glfwSetWindowUserPointer(m_Window, &m_Data);*/
		// Set GLFW callbacks
		//glfwSetWindowSizeCallback((GLFWwindow*)m_Window, [](GLFWwindow* window, int width, int height)
		//	{
		//		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		//		
		//		data.Width = width;
		//		data.Height = height;

		//		WindowResizeEvent event(width, height);
		//		data.EventCallback(event);
		//	});

		//glfwSetWindowCloseCallback((GLFWwindow*)m_Window, [](GLFWwindow* window)
		//	{
		//		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//		WindowCloseEvent event;
		//		data.EventCallback(event);
		//	});

		//glfwSetKeyCallback((GLFWwindow*)m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		//	{
		//		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//		switch (action)
		//		{
		//			case GLFW_PRESS:
		//			{
		//				KeyPressedEvent event(key, 0);
		//				data.EventCallback(event);
		//				break;
		//			}
		//			case GLFW_RELEASE:
		//			{
		//				KeyReleasedEvent event(key);
		//				data.EventCallback(event);
		//				break;
		//			}
		//			case GLFW_REPEAT:
		//			{
		//				KeyPressedEvent event(key, 1);
		//				data.EventCallback(event);
		//				break;
		//			}
		//		}
		//	});

		//glfwSetCharCallback((GLFWwindow*)m_Window, [](GLFWwindow* window, unsigned int keycode)
		//	{
		//		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		//		KeyTypedEvent event(keycode);
		//		data.EventCallback(event);
		//	});

		//glfwSetMouseButtonCallback((GLFWwindow*)m_Window, [](GLFWwindow* window, int button, int action, int mods)
		//	{
		//		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//		switch (action)
		//		{
		//			case GLFW_PRESS:
		//			{
		//				MouseButtonPressedEvent event(button);
		//				data.EventCallback(event);
		//				break;
		//			}
		//			case GLFW_RELEASE:
		//			{
		//				MouseButtonReleasedEvent event(button);
		//				data.EventCallback(event);
		//				break;
		//			}
		//		}
		//	});

		//glfwSetScrollCallback((GLFWwindow*)m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		//	{
		//		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		//		data.EventCallback(event);
		//	});

		//glfwSetCursorPosCallback((GLFWwindow*)m_Window, [](GLFWwindow* window, double xPos, double yPos)
		//	{
		//		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

		//		MouseMovedEvent event((float)xPos, (float)yPos);
		//	data.EventCallback(event);
		//	});
	}

	void WindowsWindow::Shutdown()
	{
		
	}

	void WindowsWindow::OnUpdate()
	{
		// glfwPollEvents();
		MSG msg;
		while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
		}
	}

	void WindowsWindow::SetVSync(bool enabled)
	{

	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	LRESULT WindowsWindow::DjinnProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		
		switch (msg)
		{
		case WM_CLOSE:
		{
			WindowCloseEvent event;
			m_Data.EventCallback(event);
		}
		case WM_LBUTTONDOWN:
		{
			MouseButtonPressedEvent event(VK_LBUTTON);
			m_Data.EventCallback(event);
		} break;
		case WM_LBUTTONUP:
		{
			MouseButtonReleasedEvent event(VK_LBUTTON);
			m_Data.EventCallback(event);
		} break;
		case WM_RBUTTONDOWN:
		{
			MouseButtonPressedEvent event(VK_RBUTTON);
			m_Data.EventCallback(event);
		} break;
		case WM_RBUTTONUP:
		{
			MouseButtonReleasedEvent event(VK_RBUTTON);
			m_Data.EventCallback(event);
		} break;
		case WM_KEYDOWN:
		{
			int repeat = HIWORD(wParam);
			int key = LOWORD(wParam);
			KeyPressedEvent event(key, repeat);
			m_Data.EventCallback(event);
		} break;
		case WM_CHAR:
		{
			char key = LOWORD(wParam);
			KeyTypedEvent event(key);
			m_Data.EventCallback(event);
		} break;

		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
			EndPaint(hWnd, &ps);
		} break;

		default:
			// If no specified message is handled above, 
			// let windows OS handle as per default
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		return 0;
	}
}