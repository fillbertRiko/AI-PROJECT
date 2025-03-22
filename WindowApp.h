#pragma once
//WindowApp.h
#ifndef WINDOW_APP_H
#define WINDOW_APP_H

#include <Windows.h>

class WindowApp {
public:
    //ham xu ly thonf diep cua so
    LRESULT HandleMessage(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    //ham khoi tao render, cap nhat giao dien
};
#endif // !WINDOW_APP_H


