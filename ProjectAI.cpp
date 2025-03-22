//main.cpp
#include <Windows.h>
#include "WindowApp.h"		//Header module view

//khai bao mot intance toan cuc cua windowApp de xu ly cac su kien cua so
WindowApp g_windowApp;

//Ham callback xu ly thong diep cua cua so chinh
static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return g_windowApp.HandleMessage(hWnd, message, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//1. lop cua so
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = TEXT("AppWindowClass");

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, TEXT("Dang ki lop cua so that bai!"), TEXT("Loi!!!"), MB_ICONEXCLAMATION | MB_OK);
		return 1;
	}

    //2. tao cua so chinh
    HWND hWnd = CreateWindow(
        TEXT("AppWindowClass"),
        TEXT("Expert System MVC"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL, NULL,
        hInstance,
        NULL
    );

	if (!hWnd)
	{
		MessageBox(NULL, TEXT("Tao cua so that bai!!!"), TEXT("loi!!!"), MB_ICONEXCLAMATION);
		return 1;

	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//3. vong lap thong diep
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}