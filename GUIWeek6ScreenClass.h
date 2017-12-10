#pragma once

#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h> 

// The string that appears in the application's title bar. 
static TCHAR* szTitle0 = { _T("CEIS400 Team A GP") };
static TCHAR* szTitle1 = { _T("Manager Login") };
static TCHAR* szTitle2 = { _T("Manager Main") };
static TCHAR* szTitle3 = { _T("Manager Create New Employee") };
static TCHAR* szTitle4 = { _T("Manager Problem Employees") };
static TCHAR* szTitle5 = { _T("Manager Employee Terminated") };
static TCHAR* szTitle6 = { _T("Manager New Employee Created") };
static TCHAR* szTitle7 = { _T("Employee Login") };
static TCHAR* szTitle8 = { _T("Employee Main") };
static TCHAR* szTitle9 = { _T("Employee Equipment Check in") };
static TCHAR* szTitle10 = { _T("Employee Equipment Check out") };
static TCHAR* szTitle11 = { _T("Employee Equipment Ordered") };
static TCHAR* szTitle12 = { _T("Employee Depot Inventory") };
static TCHAR* szTitle13 = { _T("Exit Application") };

// The main window class name. 
static TCHAR* szWindowClass0 = { _T("0") };
static TCHAR* szWindowClass1 = { _T("1") };
static TCHAR* szWindowClass2 = { _T("2") };
static TCHAR* szWindowClass3 = { _T("3") };
static TCHAR* szWindowClass4 = { _T("4") };
static TCHAR* szWindowClass5 = { _T("5") };
static TCHAR* szWindowClass6 = { _T("6") };
static TCHAR* szWindowClass7 = { _T("7") };
static TCHAR* szWindowClass8 = { _T("8") };
static TCHAR* szWindowClass9 = { _T("9") };
static TCHAR* szWindowClass10 = { _T("10") };
static TCHAR* szWindowClass11 = { _T("11") };
static TCHAR* szWindowClass12 = { _T("12") };
static TCHAR* szWindowClass13 = { _T("13") };

// generic TCHAr to set by screen
static TCHAR* szWC;
static TCHAR* szT;

// button starting loc
static int ButtonWidth = 150;
static int ButtonHeight = 100;
static int ButtonCenterX = 300;
//600 is screen width
static int ButtonLeftX = (600 - ButtonCenterX)/4;
static int ButtonRightX = ButtonCenterX + ButtonLeftX;
static int ButtonYstart = 300;

// set starting screen
static int ScreenNum;

// button names
static TCHAR szManagerLogin[] = _T("Manager Login");
static TCHAR szEmployeeLogin[] = _T("Employee Login");
static TCHAR szCreateNew[] = _T("Create New Login");
static TCHAR szGenProbEmp[] = _T("Problem Employees");
static TCHAR szPrintProblemEmp[] = _T("Print Employees");
static TCHAR szTermEmp[] = _T("Terminate Employee");
static TCHAR szCheckIn[] = _T("Check In Equipment");
static TCHAR szCheckOut[] = _T("Check Out Equipment");
static TCHAR szOrdEquip[] = _T("Order Equipment");
static TCHAR szDepInv[] = _T("Depot Inventory");
static TCHAR szPrintDepInv[] = _T("Print Depot Inventory");
static TCHAR szEnter[] = _T("Enter");
static TCHAR szBack[] = _T("Back");


class ScreenClass
{
public:

	ScreenClass(HINSTANCE hInst);
	~ScreenClass();

	void terminate_ScreenClass();
	//create instance of window class
	WNDCLASS Wc = { 0 };

	// main and button handles
	HWND hWnd;

	//callback procedure
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Create_Window(HINSTANCE h);

	int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

	static void setszWC_szT(int SC);
	
private:
	RECT CenterWindow;

	int ScreenClassWidth = 600;
	int ScreenClassHeight = 600;

	void Center_Window(HWND Parent_Window, int width, int height);

};





