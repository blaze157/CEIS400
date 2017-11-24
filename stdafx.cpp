// stdafx.cpp : source file that includes just the standard includes
// GUI.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

//defines
#define Login_Menu = 1

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

//functions
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_COMMAND:

		switch (wp)
		{
		case 1:
			MessageBeep(MB_OK);
			break;
		}
		break;
	case WM_CREATE:
		AddMenus(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

//create menus
void AddMenus(HWND hWnd)
{
	hMenu = CreateMenu();
	HMENU hLoginMenu = CreateMenu();

	AppendMenu(hLoginMenu, MF_STRING, Login_Menu, L"Login");

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hLoginMenu, L"Login");

	SetMenu(hWnd, hMenu);
}
