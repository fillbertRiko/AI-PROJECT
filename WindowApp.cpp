// WindowApp.cpp
#include "WindowApp.h"

LRESULT WindowApp::HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);

			//ve giao dien
			TextOut(hdc, 10, 10, TEXT("Chao mung den voi Expert System MVC"), 36);
			EndPaint(hWnd, &ps);
		}
		return 0;
	case WM_DESTROY:
		{
		PostQuitMessage(0);
		return 0;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}