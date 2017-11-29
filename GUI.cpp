// CEIS400 Course Project GUI Starting/login screen by Sam Bowlin 11/20/17 rev 1 sourced from
// https://msdn.microsoft.com/en-us/library/bb384843.aspx and https://www.youtube.com/watch?v=7K6HCeog09c
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c  
// GUI main cpp file


// includes
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

// defines
#define Screen_New 1
#define Screen_Open 2
#define Screen_Exit 3
#define Screen_Change_Title 4

// namespaces
using namespace std;

// constants screen class names
const wchar_t StartScreen[] = L"StartScreen";
const wchar_t MangerLoginScreen[] = L"ManagerLoginScreen";
const wchar_t EmployeeLoginScreen[] = L"EmployeeLoginScreen";
const wchar_t ManagerMainScreen[] = L"ManagerMainScreen";
const wchar_t EmployeeMainScreen[] = L"EmployeeMainScreen";
const wchar_t ManagerCreateNewIDScreen[] = L"ManagerCreateNewIDScreen";
const wchar_t ResultsScreen[] = L"ResultsScreen";
const wchar_t ExitScreen[] = L"ExitScreen";

// constants screen titles
const wchar_t CEIS400[] = L"CEIS400 Team A GP";
const wchar_t MangerLogin[] = L"Manger Login";
const wchar_t EmployeeLogin[] = L"Employee Login";
const wchar_t ManagerMain[] = L"Manager Main";
const wchar_t EmployeeMain[] = L"Employee Main";
const wchar_t CreateID[] = L"Create New ID";
const wchar_t Results[] = L"Results";
const wchar_t Exit[] = L"Exit";

// menu
//HMENU hMenu;
//HWND hEdit;
HINSTANCE hInst;

// functions def
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);
void AddControls(HWND);


// main window api
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevtInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//set window
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = StartScreen;
	wc.hIconSm = LoadIcon(wc.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	//return -1 if window fails to load
	if (!RegisterClassEx(&wc))
	{
		return 1;
	}

	// Store instance handle in our global variable
	hInst = hInstance; 

	//create the window
	HWND hWnd = CreateWindow(StartScreen, CEIS400, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
		500, 500, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return 1;
	}

	// show window
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//set and get messages
	MSG msg;

	//window loop
	while (GetMessage(&msg, NULL, 0, 0));
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//functions
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (msg)
	{
		case WM_PAINT:

			/*
			switch (wParam)
			{
				case Screen_Exit:
					DestroyWindow(hWnd);
					break;
				case Screen_New:
		
					break;
				case Screen_Change_Title:
					wchar_t text[100];
					GetWindowText(hEdit, text, 100);
					SetWindowText(hWnd, text);
					break;
			}*/
			hdc = BeginPaint(hWnd, &ps);
			AddControls(hWnd);
			EndPaint(hWnd, &ps);
			break;

		/*case WM_CREATE:
			//AddMenus(hWnd);
			AddControls(hWnd);
			break;*/
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hWnd, msg, wParam, lParam);
			break;
	}
	return 0;
}



