#include "dngpch.h"
#include "Core.h"

namespace Djinn
{
 

	void PollEvents(void)
	{
		MSG msg;
		HWND handle;
		
		while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				// Do something to close window here
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
		}
	}


}