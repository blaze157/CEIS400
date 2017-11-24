// GUI.cpp : Defines the entry point for the console application.
//

//defines


#include "stdafx.h"


//main window api
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevtInst, LPSTR args, int ncmdShow)
{
	//set window
	WNDCLASS wc = { 0 };

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"StartingScreen";
	wc.lpfnWndProc = WindowProcedure;

	//return -1 if window fails to load
	if (!RegisterClassW(&wc))
	{
		return -1;
	}

	//create the window
	CreateWindowW(L"StartingScreen", L"Course Project", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	//set and get messages
	MSG msg = { 0 };

	while (GetMessage(&msg, NULL, NULL, NULL));
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

    return 0;
}



