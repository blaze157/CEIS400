#include "GUI_Screen_Class.h"

//destroy class
ScreenClass::~ScreenClass()
{
}

// delete class
void ScreenClass::terminate_ScreenClass()
{
	delete this;
}

const TCHAR* ScreenClass::szTitle[MaxScreens] = {
	_T("CEIS400 Team A GP"),
	_T("Manager Login"),
	_T("Manager Main"),
	_T("Manager Create New Employee"),
	_T("Manager Problem Employees"),
	_T("Manager Employee Terminated"),
	_T("Manager New Employee Created"),
	_T("Employee Login"),
	_T("Employee Main"),
	_T("Employee Equipment Check in"),
	_T("Employee Equipment Check out"),
	_T("Employee Equipment Ordered"),
	_T("Employee Depot Inventory"),
	_T("Exit Application")
};

const TCHAR* ScreenClass::szWindowClass[MaxScreens] = {
	_T("0") ,
	_T("1") ,
	_T("2") ,
	_T("3") ,
	_T("4") ,
	_T("5") ,
	_T("6") ,
	_T("7") ,
	_T("8") ,
	_T("9") ,
	_T("10") ,
	_T("11") ,
	_T("12") ,
	_T("13")
};

const TCHAR* ScreenClass::szButtonNames[13] = {
	_T("Manager Login"),
	_T("Employee Login"),
	_T("Create New Login"),
	_T("Problem Employees"),
	_T("Print Employees"),
	_T("Terminate Employee"),
	_T("Check In Equipment"),
	_T("Check Out Equipment"),
	_T("Order Equipment"),
	_T("Depot Inventory"),
	_T("Print Depot Inventory"),
	_T("Enter"),
	_T("Back")
};

int ScreenClass::ScreenNum = 0;
int ScreenClass::ButtonWidth = 150;
int ScreenClass::ButtonHeight = 100;
int ScreenClass::ButtonCenterX = 300;
int ScreenClass::ButtonLeftX = (600 - ButtonCenterX) / 4;
int ScreenClass::ButtonRightX = ButtonCenterX + ButtonLeftX;
int ScreenClass::ButtonYstart = 300;

bool ScreenClass::ManAger = false;

// set class class name must = label
ScreenClass::ScreenClass(HINSTANCE hInst)
{
	// set WNDCLASS
	Wc.style = CS_VREDRAW | CS_HREDRAW;
	Wc.lpfnWndProc = &ScreenClass::WndProc;
	Wc.cbClsExtra = 0;
    Wc.cbWndExtra = 0;
	Wc.hInstance = hInst;
	Wc.hIcon = 0;
	Wc.hCursor = LoadCursor(0, IDC_ARROW);
	Wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = szWindowClass[ScreenNum];
}

// szTitle definition

LRESULT ScreenClass::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//button and text box handles
	HWND hwnd_login_label, hwnd_login_input, hwnd_pword_label, hwnd_pword_input;

	// xy and width height for manipulation
	int x, y, w, h;

	switch (message)
	{
	case WM_CREATE:
	{
		switch (ScreenNum)
		{
			// start screen
		case 0:
		{
			// to set location on form
			x = ButtonCenterX - (ButtonWidth / 2); y = (ButtonYstart / 4) + (ButtonHeight / 4);
			w = ButtonWidth; h = ButtonHeight;
			
			CreateWindow(TEXT("button"), szButtonNames[0],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)1, NULL, NULL);

			y = ButtonYstart + y;
			CreateWindow(TEXT("button"), szButtonNames[1],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)7, NULL, NULL);
			break;
		}
		//manager login
		case 1:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER | ES_PASSWORD,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			//pword box
			x = ButtonCenterX - (w); y += h;
			hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)502,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

			x += w;
			hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER | ES_PASSWORD,
				x, y, w, h,
				hwnd, (HMENU)503,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_input, TEXT("*****"));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)0, NULL, NULL);

			y += h + 20;
			CreateWindow(TEXT("button"), szButtonNames[11],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)2, NULL, NULL);
			break;
		}
		//manager main
		case 2:
		{
			ManAger = true;
			w = ButtonWidth; h = ButtonHeight;
			x = ButtonLeftX; y = (ButtonYstart / 2) - (h / 2);
			//left buttons
			CreateWindow(TEXT("button"), szButtonNames[2],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)3, NULL, NULL);

			y += (h + 50);
			CreateWindow(TEXT("button"), szButtonNames[3],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)4, NULL, NULL);

			y += (h + 50);
			CreateWindow(TEXT("button"), szButtonNames[5],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)5, NULL, NULL);

			// right buttons
			x = ButtonRightX; y = (ButtonYstart / 4) - (h / 2);
			CreateWindow(TEXT("button"), szButtonNames[6],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)9, NULL, NULL);

			y += (h + 35);
			CreateWindow(TEXT("button"), szButtonNames[7],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)10, NULL, NULL);

			y += (h + 35);
			CreateWindow(TEXT("button"), szButtonNames[8],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)11, NULL, NULL);

			y += (h + 35);
			CreateWindow(TEXT("button"), szButtonNames[9],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)12, NULL, NULL);

			//ManAger = true;

			break;
		}
		//manager create new
		case 3:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			//pword box
			x = ButtonCenterX - (w); y += h;
			hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)502,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

			x += w;
			hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)503,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_input, TEXT("*****"));


			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)2, NULL, NULL);

			y += h + 20;
			CreateWindow(TEXT("button"), szButtonNames[11],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)6, NULL, NULL);
			break;
		}
		//manager problem employees
		case 4:
		{
			w = 200; h = 20;
			x = ButtonCenterX - (w / 2); y = 20;
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)504,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("Problem Employees:"));

			y += h; w = 500; h = 300;  x = ButtonCenterX - (w / 2);
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)505,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT(""));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = (ButtonCenterX / 2) - (w / 2); y = (ButtonYstart * 2) - (h * 2);
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)2, NULL, NULL);

			x = ButtonCenterX + (w / 2);
			CreateWindow(TEXT("button"), szButtonNames[4],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)20, NULL, NULL);
			break;
		}
		//manager terminated employees
		case 5:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			//pword box
			/*x = ButtonCenterX - (w); y += h;
			hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
			WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			x, y, w, h,
			hwnd, (HMENU)502,
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

			x += w;
			hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_TABSTOP
			| ES_LEFT | WS_BORDER | ES_PASSWORD,
			x, y, w, h,
			hwnd, (HMENU)503,
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_input, TEXT("*****"));*/

			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)2, NULL, NULL);

			y += h + 20;
			CreateWindow(TEXT("button"), szButtonNames[11],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)24, NULL, NULL);
			break;
		}
		//manager new employee created
		case 6:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			//pword box
			x = ButtonCenterX - (w); y += h;
			hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)502,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

			x += w;
			hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)503,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_input, TEXT("*****"));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)2, NULL, NULL);

			break;
		}
		//employee login
		case 7:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER | ES_PASSWORD,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			//pword box
			x = ButtonCenterX - (w); y += h;
			hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)502,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

			x += w;
			hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER | ES_PASSWORD,
				x, y, w, h,
				hwnd, (HMENU)503,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_pword_input, TEXT("*****"));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)0, NULL, NULL);

			y += h + 20;
			CreateWindow(TEXT("button"), szButtonNames[11],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)8, NULL, NULL);

			break;
		}
		//employee main
		case 8:
		{
			// center buttons
			w = ButtonWidth; h = ButtonHeight;
			x = ButtonCenterX - (ButtonWidth / 2); y = (ButtonYstart / 4) - (h / 2);
			CreateWindow(TEXT("button"), szButtonNames[6],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)9, NULL, NULL);

			y += (h + 35);
			CreateWindow(TEXT("button"), szButtonNames[7],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)10, NULL, NULL);

			y += (h + 35);
			CreateWindow(TEXT("button"), szButtonNames[8],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)11, NULL, NULL);

			y += (h + 35);
			CreateWindow(TEXT("button"), szButtonNames[9],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)12, NULL, NULL);

			//ManAger = false;

			break;
		}
		//employee equipment check in
		case 9:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("Equipment I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)8, NULL, NULL);

			y += h + 20;
			CreateWindow(TEXT("button"), szButtonNames[11],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)23, NULL, NULL);
			break;
		}
		//employee equipment check out
		case 10:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("Equipment I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)8, NULL, NULL);

			y += h + 20;
			CreateWindow(TEXT("button"), szButtonNames[11],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)22, NULL, NULL);
			break;
		}
		//employee equipment ordered
		case 11:
		{
			w = 100; h = 20;
			x = ButtonCenterX - (w); y = (ButtonYstart / 4) + (h / 4);
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, w, h,
				hwnd, (HMENU)500,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("Equipment I.D:"));

			x += w;
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)501,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT("*****"));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = ButtonCenterX - (ButtonWidth / 2); y = ((ButtonYstart / 4) + (h / 4)) + ButtonYstart;
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)8, NULL, NULL);

			y += h + 20;
			CreateWindow(TEXT("button"), szButtonNames[11],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)21, NULL, NULL);
			break;
		}
		//employee depot inventory
		case 12:
		{
			w = 200; h = 20;
			x = ButtonCenterX - (w / 2); y = 20;
			// login box
			hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_CENTER,
				x, y, w, h,
				hwnd, (HMENU)506,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_label, TEXT("Depot Inventory:"));

			y += h; w = 500; h = 300;  x = ButtonCenterX - (w / 2);
			hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP
				| ES_LEFT | WS_BORDER,
				x, y, w, h,
				hwnd, (HMENU)507,
				(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE) , NULL);
			SetWindowText(hwnd_login_input, TEXT(""));

			w = ButtonWidth; h = ButtonHeight - 50;
			x = (ButtonCenterX / 2) - (w / 2); y = (ButtonYstart * 2) - (h * 2);
			CreateWindow(TEXT("button"), szButtonNames[12],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)8, NULL, NULL);

			x = ButtonCenterX + (w / 2);
			CreateWindow(TEXT("button"), szButtonNames[10],
				WS_VISIBLE | WS_CHILD,
				x, y, w, h,
				hwnd, (HMENU)20, NULL, NULL);
			break;
		}
		//exit
		case 13:
		{
			//MessageBox(0, L"Exiting application", L"Exiting", MB_OK);
			//ScreenNum = 13;
			break;
		}
		//print feature
		case 20:
		{

			break;
		}
		default:
			break;
		}


		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 0:
		{
			ScreenNum = 0;
			DestroyWindow(hwnd);
			break;
		}
		case 1:
		{
			ScreenNum = 1;
			DestroyWindow(hwnd);
			break;
		}
		case 2:
		{
			
			ScreenNum = 2;
			DestroyWindow(hwnd);
			break;
		}
		case 3:
		{
			ScreenNum = 3;
			DestroyWindow(hwnd);
			break;
		}
		case 4:
		{
			ScreenNum = 4;
			DestroyWindow(hwnd);
			break;
		}
		case 5:
		{
			ScreenNum = 5;
			DestroyWindow(hwnd);
			break;
		}
		case 6:
		{
			ScreenNum = 6;
			DestroyWindow(hwnd);
			break;
		}
		case 7:
		{
			ScreenNum = 7;
			DestroyWindow(hwnd);
			break;
		}
		case 8:
		{
			if (ManAger)
			{
				ScreenNum = 2;
			}
			else
			{
				ScreenNum = 8;
			}
			DestroyWindow(hwnd);
			break;
		}
		case 9:
		{
			ScreenNum = 9;
			DestroyWindow(hwnd);
			break;
		}
		case 10:
		{
			ScreenNum = 10;
			DestroyWindow(hwnd);
			break;
		}
		case 11:
		{
			ScreenNum = 11;
			DestroyWindow(hwnd);
			break;
		}
		case 12:
		{
			ScreenNum = 12;
			DestroyWindow(hwnd);
			break;
		}
		case 13:
		{
			ScreenNum = 13;
			DestroyWindow(hwnd);
			break;
		}
		default:
			break;
		}

		break;
	}
	case WM_CLOSE:
	{
		int m = MessageBox(0, L"Are you sure you want to exit?", L"Exit Application", MB_YESNO);
		if (m == IDYES)
		{
			ScreenNum = 13;
			DestroyWindow(hwnd);
		}
		break;
	}
	case WM_SIZE:
	{
		//MessageBox(0, L"SIZE", L"SIZE", MB_OK);
		break;
	}
	case WM_SIZING:
		{
			//MessageBox(0, L"SIZEing", L"SIZEing", MB_OK);
			break;
		}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}

	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

void ScreenClass::Center_Window(HWND Parent_Window, int width, int height)
{
	GetClientRect(Parent_Window, &CenterWindow);
	CenterWindow.left = (CenterWindow.right / 2) - (width / 2);
	CenterWindow.top = (CenterWindow.bottom / 2) - (height / 2);
}

void ScreenClass::Create_Window(HINSTANCE h)
{
	Center_Window(GetDesktopWindow(), ScreenClassWidth, ScreenClassHeight);
	hWnd = CreateWindow(szWindowClass[ScreenNum], szTitle[ScreenNum], WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CenterWindow.left, CenterWindow.top, ScreenClassWidth, ScreenClassHeight, 0, 0, h, 0);
}

int CALLBACK ScreenClass::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//MSG msg;

	if (!RegisterClass(&Wc))
	{
		DWORD dw = GetLastError();
		WCHAR szTest[sizeof(dw)]; 
		swprintf_s(szTest, sizeof(dw), L"%d", dw); 

		MessageBox(NULL, szTest,
			_T("Call to RegisterClass failed!"),
			MB_OK);
		return 13;
	}

	Create_Window(hInstance);

	if (!hWnd)
	{
		DWORD dw = GetLastError();
		WCHAR szTest[sizeof(dw)]; 
		swprintf_s(szTest, sizeof(dw), L"%d", dw); 
		MessageBox(NULL, szTest,
			_T("Create Window Failed!"),
			MB_OK);
		return 13;
	}

	//exit window
	return ScreenNum;
}

WNDCLASS ScreenClass::getWc()
{
	return WNDCLASS(Wc);
}












