//week 6
// CEIS400 Course Project GUI Starting/login screen by Sam Bowlin 11/20/17 rev 1 sourced from
// https://msdn.microsoft.com/en-us/library/bb384843.aspx, https://www.youtube.com/watch?v=7K6HCeog09c, and
// https://msdn.microsoft.com/en-us/library/windows/desktop/hh298354(v=vs.85).aspx
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c  
// GUI main cpp file


// includes
#include "GUI_Screen_Class.h"


// main window api
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPI, LPSTR lCL, int nCS)
{

	int newScreen = 0;

	int exitScreen;

	MSG mainMSG;

	while (newScreen != 13)
	{
		ScreenClass* GUI = new ScreenClass(GetModuleHandle(0));
		
		newScreen = GUI->WinMain(hI,hPI, lCL, nCS);

		while (GetMessage(&mainMSG, NULL, 0, 0))
		{
			TranslateMessage(&mainMSG);
			DispatchMessage(&mainMSG);
		}

		UnregisterClass(GUI->getWc().lpszClassName, hI);
		GUI->terminate_ScreenClass();
		
	}

	return 0;
};