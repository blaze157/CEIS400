#include "GUIWeek6ScreenClass.h"

// set class
ScreenClass::ScreenClass(HINSTANCE hInst)
{
	setszWC_szT(ScreenNum);
	Wc.hInstance = hInst;
	Wc.hCursor = LoadCursor(0, IDC_ARROW);
	Wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	Wc.lpszClassName = szWC;
	Wc.lpfnWndProc = &ScreenClass::WndProc;
}

//destroy class
ScreenClass::~ScreenClass()
{
}

void ScreenClass::terminate_ScreenClass()
{
	delete this;
}

LRESULT ScreenClass::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//button and text box handles
	HWND hwnd_1, hwnd_2, hwnd_3, hwnd_4, hwnd_5, hwnd_6, hwnd_7, hwnd_8, hwnd_9, hwnd_10,
		hwnd_login_label, hwnd_login_input, hwnd_pword_label, hwnd_pword_input;
	
	switch (message)
	{
		case WM_CREATE:
		{
			
			switch (ScreenNum)
			{
				// start screen
			case 0:
			{
				CreateWindow(TEXT("button"), szManagerLogin,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)1, NULL, NULL);

				CreateWindow(TEXT("button"), szEmployeeLogin,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart + ButtonHeight + 100, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)2, NULL, NULL);
				break;
			}
			//manager login
			case 1:
			{
				int x, y, w, h;
				y = 10; h = 20;
				x = 10; w = 100;
				// login box
				hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(505),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

				x += w; w = 60;
				hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER | ES_PASSWORD,
					x, y, w, h,
					hwnd, (HMENU)(506),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_input, TEXT("*****"));

				//pword box
				x = 10; w = 100; y += h;
				hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(507),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

				x += w; w = 60;
				hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER | ES_PASSWORD,
					x, y, w, h,
					hwnd, (HMENU)(508),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_input, TEXT("*****")),

					CreateWindow(TEXT("button"), szBack,
						WS_VISIBLE | WS_CHILD,
						ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight - 50,
						hwnd, (HMENU)3, NULL, NULL);

				CreateWindow(TEXT("button"), szEnter,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart + ButtonHeight, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);
				break;
			}
			//manager main
			case 2:
			{
				CreateWindow(TEXT("button"), szCreateNew,
					WS_VISIBLE | WS_CHILD,
					ButtonLeftX, ButtonCenterYstart - 65, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)6, NULL, NULL);

				CreateWindow(TEXT("button"), szGenProbEmp,
					WS_VISIBLE | WS_CHILD,
					ButtonLeftX, ButtonCenterYstart + 45, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)7, NULL, NULL);

				CreateWindow(TEXT("button"), szTermEmp,
					WS_VISIBLE | WS_CHILD,
					ButtonLeftX, ButtonCenterYstart + 155, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)8, NULL, NULL);

				CreateWindow(TEXT("button"), szCheckIn,
					WS_VISIBLE | WS_CHILD,
					ButtonRightX, ButtonCenterYstart - 65, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)9, NULL, NULL);

				CreateWindow(TEXT("button"), szCheckOut,
					WS_VISIBLE | WS_CHILD,
					ButtonRightX, ButtonCenterYstart + 45, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)10, NULL, NULL);

				CreateWindow(TEXT("button"), szOrdEquip,
					WS_VISIBLE | WS_CHILD,
					ButtonRightX, ButtonCenterYstart + 145, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)11, NULL, NULL);

				CreateWindow(TEXT("button"), szDepInv,
					WS_VISIBLE | WS_CHILD,
					ButtonRightX, ButtonCenterYstart - 255, ButtonWidth, ButtonHeight,
					hwnd, (HMENU)12, NULL, NULL);

				break;
			}
			//manager create new
			case 3:
			{
				int x, y, w, h;
				y = 10; h = 20;
				x = 10; w = 100;
				// login box
				hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(509),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

				x += w; w = 60;
				hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER,
					x, y, w, h,
					hwnd, (HMENU)(510),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_input, TEXT("*****"));

				//pword box
				x = 10; w = 100; y += h;
				hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(511),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

				x += w; w = 60;
				hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER,
					x, y, w, h,
					hwnd, (HMENU)(512),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_input, TEXT("*****")),

				CreateWindow(TEXT("button"), szBack,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);

				CreateWindow(TEXT("button"), szEnter,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart + ButtonHeight, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);
				break;
			}
			//manager problem employees
			case 4: 
			{
				int x, y, w, h;
				y = 10; h = 20;
				x = 10; w = 100;
				// login box
				hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(510),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_label, TEXT("Problem Employees:"));

				x += w; w = 60;
				hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER,
					x, y, w, h,
					hwnd, (HMENU)(511),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_input, TEXT("*****"));

				CreateWindow(TEXT("button"), szBack,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);

				CreateWindow(TEXT("button"), szPrintProblemEmp,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart + ButtonHeight, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);
				break;
			}
			//manager terminated employees
			case 5:
			{
				int x, y, w, h;
				y = 10; h = 20;
				x = 10; w = 100;
				// login box
				hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(512),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_label, TEXT("Terminate Employees:"));

				x += w; w = 60;
				hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER,
					x, y, w, h,
					hwnd, (HMENU)(513),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_input, TEXT("*****"));

				CreateWindow(TEXT("button"), szBack,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);

				CreateWindow(TEXT("button"), szTermEmp,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart + ButtonHeight, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);
				break;
			}
			//manager new employee created
			case 6:
			{
				int x, y, w, h;
				y = 10; h = 20;
				x = 10; w = 100;
				// login box
				hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(512),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_label, TEXT("New Employee Created:"));

				x += w; w = 60;
				hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER,
					x, y, w, h,
					hwnd, (HMENU)(513),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_input, TEXT("*****"));

				CreateWindow(TEXT("button"), szBack,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)5, NULL, NULL);

				break;
			}
			//employee login
			case 7:
			{
				int x, y, w, h;
				y = 10; h = 20;
				x = 10; w = 100;
				// login box
				hwnd_login_label = CreateWindow(TEXT("static"),TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP, 
					x, y, w, h,
					hwnd, (HMENU)(501),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

				x += w; w = 60;
				hwnd_login_input = CreateWindow(TEXT("edit"),TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER, 
					x, y, w, h,
					hwnd, (HMENU)(502),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_input, TEXT("*****"));
				
				//pword box
				x = 10; w = 100; y += h;
				hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
						WS_CHILD | WS_VISIBLE | WS_TABSTOP,
						x, y, w, h,
						hwnd, (HMENU)(503),
						(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

				x += w; w = 60;
				hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER,
					x, y, w, h,
					hwnd, (HMENU)(504),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_input, TEXT("*****")),

				CreateWindow(TEXT("button"), szBack,
						WS_VISIBLE | WS_CHILD,
						ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight - 50,
						hwnd, (HMENU)3, NULL, NULL);

				CreateWindow(TEXT("button"), szEnter,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart + ButtonHeight, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)4, NULL, NULL);

				break;
			}
			//employee main
			case 8:
			{
				int x, y, w, h;
				y = 10; h = 20;
				x = 10; w = 100;
				// login box
				hwnd_login_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(505),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_label, TEXT("USER I.D:"));

				x += w; w = 60;
				hwnd_login_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER | ES_PASSWORD,
					x, y, w, h,
					hwnd, (HMENU)(506),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_login_input, TEXT("*****"));

				//pword box
				x = 10; w = 100; y += h;
				hwnd_pword_label = CreateWindow(TEXT("static"), TEXT("login"),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP,
					x, y, w, h,
					hwnd, (HMENU)(507),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_label, TEXT("PASSWORD:"));

				x += w; w = 60;
				hwnd_pword_input = CreateWindow(TEXT("edit"), TEXT(""),
					WS_CHILD | WS_VISIBLE | WS_TABSTOP
					| ES_LEFT | WS_BORDER | ES_PASSWORD,
					x, y, w, h,
					hwnd, (HMENU)(508),
					(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
				SetWindowText(hwnd_pword_input, TEXT("*****")),

					CreateWindow(TEXT("button"), szBack,
						WS_VISIBLE | WS_CHILD,
						ButtonCenterX, ButtonCenterYstart, ButtonWidth, ButtonHeight - 50,
						hwnd, (HMENU)3, NULL, NULL);

				CreateWindow(TEXT("button"), szEnter,
					WS_VISIBLE | WS_CHILD,
					ButtonCenterX, ButtonCenterYstart + ButtonHeight, ButtonWidth, ButtonHeight - 50,
					hwnd, (HMENU)4, NULL, NULL);
				break;
			}
			//employee equipment check in
			case 9:
			{

				break;
			}
			//employee equipment check out
			case 10:
			{

				break;
			}
			//employee equipment ordered
			case 11:
			{

				break;
			}
			//employee depot inventory
			case 12:
			{

				break;
			}
			//exit
			case 13:
			{
				MessageBox(0, L"Exiting application", L"Exiting", MB_OK);
				ScreenNum = 13;
				break;
			}
			default:
				break;
			}
			

			break;
		}
		case WM_COMMAND:
		{
			if (LOWORD(wParam) == 1) {
				ScreenNum = 1;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 2) {
				ScreenNum = 7;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 3)
			{
				ScreenNum = 0;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 4)
			{
				ScreenNum = 8;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 5)
			{
				ScreenNum = 2;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 6)
			{
				ScreenNum = 3;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 7)
			{
				ScreenNum = 4;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 8)
			{
				ScreenNum = 5;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 9)
			{
				ScreenNum = 9;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 10)
			{
				ScreenNum = 10;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 11)
			{
				ScreenNum = 11;
				DestroyWindow(hwnd);
			}

			if (LOWORD(wParam) == 12)
			{
				ScreenNum = 12;
				DestroyWindow(hwnd);
			}

			break;
		}
		case WM_CLOSE:
		{
			m = MessageBox(0, L"Are you sure you want to exit?", L"Exit Application", MB_YESNO);
			if (m == IDYES)
			{
				ScreenNum = 13;
				DestroyWindow(hwnd);
			}
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
	hWnd = CreateWindow(szWC, szT, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CenterWindow.left, CenterWindow.top, ScreenClassWidth, ScreenClassHeight, 0, 0, h, 0);
}

int CALLBACK ScreenClass::WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;

	if (!RegisterClass(&Wc))
	{
		DWORD dw = GetLastError();
		MessageBox(NULL, (LPCWSTR)dw,
			_T("Call to RegisterClass failed!"),
			NULL);
		return 13;
	}

	Create_Window(hInstance);

	if (!hWnd)
	{
		DWORD dw = GetLastError();
		MessageBox(NULL, (LPCWSTR)dw,
			_T("Create Window Failed!"),
			NULL);
		return 13;
	}

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}	

	//exit window
	return ScreenNum;
}

void ScreenClass::setszWC_szT(int SC)
{
	switch (ScreenNum)
	{
	case 0:
	{
		szWC = szWindowClass0;
		szT = szTitle0;
		break;
	}
	case 1:
	{
		szWC = szWindowClass1;
		szT = szTitle1;
		break;
	}
	case 2:
	{
		szWC = szWindowClass2;
		szT = szTitle2;
		break;
	}
	case 3:
	{
		szWC = szWindowClass3;
		szT = szTitle3;
		break;
	}
	case 4:
	{
		szWC = szWindowClass4;
		szT = szTitle4;
		break;
	}
	case 5:
	{
		szWC = szWindowClass5;
		szT = szTitle5;
		break;
	}
	case 6:
	{
		szWC = szWindowClass6;
		szT = szTitle6;
		break;
	}
	case 7:
	{
		szWC = szWindowClass7;
		szT = szTitle7;
		break;
	}
	case 8:
	{
		szWC = szWindowClass8;
		szT = szTitle8;
		break;
	}
	case 9:
	{
		szWC = szWindowClass9;
		szT = szTitle9;
		break;
	}
	case 10:
	{
		szWC = szWindowClass10;
		szT = szTitle10;
		break;
	}
	case 11:
	{
		szWC = szWindowClass11;
		szT = szTitle11;
		break;
	}
	case 12:
	{
		szWC = szWindowClass12;
		szT = szTitle12;
		break;
	}
	case 13:
	{
		szWC = szWindowClass13;
		szT = szTitle13;
		break;
	}
	default:
		break;
	}
}





