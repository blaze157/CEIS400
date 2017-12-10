#pragma once

// includes
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h> 

//defines
#define MaxScreens 14
#define MaxButtons 14

// class
class ScreenClass
{
public:

	ScreenClass(HINSTANCE hInst);
	~ScreenClass();

	void terminate_ScreenClass();
	
	static const int i = 0;

	//callback procedure
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Create_Window(HINSTANCE h);

	int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

	WNDCLASS getWc();

private:
	// main and button handles
	HWND hWnd;

	//create instance of window class
	WNDCLASS Wc; // = { 0 };

	RECT CenterWindow;

	const static int ScreenClassWidth = 600;
	const static int ScreenClassHeight = 600;

	void Center_Window(HWND Parent_Window, int width, int height);

	static const TCHAR* szTitle[MaxScreens];

	static const TCHAR* szWindowClass[MaxScreens];

	static const TCHAR* szButtonNames[13];

	// set starting screen
	static int ScreenNum;

	// button starting loc
	static int ButtonWidth;
	static int ButtonHeight;
	static int ButtonCenterX;
	//600 is screen width
	static int ButtonLeftX;
	static int ButtonRightX;
	static int ButtonYstart;

	static bool ManAger;

};