#include "CoreWindow.h"
#include "CoreWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam,LPARAM lParam);

CoreWindow::CoreWindow()
{
}

CoreWindow::~CoreWindow()
{
}

HWND CoreWindow::GetHWND()
{ 
	return hWnd;
}

HINSTANCE CoreWindow::GetHinstance()
{
	return hInstance;
}

WNDCLASSEX CoreWindow::CreateWindowClass(LPCSTR ClassName,LPCSTR MenuName)
{
	WNDCLASSEX wnd;
	ZeroMemory(&wnd,sizeof(WNDCLASSEX));
	wnd.cbClsExtra = NULL;
	wnd.cbSize = sizeof(WNDCLASSEX);
	wnd.cbWndExtra = NULL;
	wnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wnd.hCursor = LoadCursor(hInstance,IDC_ARROW);
	wnd.hIcon = LoadIcon(hInstance,IDI_APPLICATION);
	wnd.hIconSm = LoadIcon(hInstance,IDI_APPLICATION);
	wnd.hInstance = hInstance;
	wnd.lpfnWndProc = WndProc;
	wnd.lpszClassName = ClassName;
	wnd.style = CS_VREDRAW | CS_HREDRAW;

	this->ClassName = ClassName;

	RegisterClassEx(&wnd);

	return wnd;
}

bool CoreWindow::InitializeWindow(LPCSTR WindowName,int X,int Y,int Width,int Height)
{
	this->X = X;
	this->Y = Y;

	this->Width  = Width;
	this->Height = Height;

	this->WindowName = WindowName;

	CreateWindowClass(WindowName,NULL);

	RECT rect = {0,0,Width,Height};
	AdjustWindowRectEx(&rect,WS_OVERLAPPEDWINDOW,NULL,NULL);
	hWnd = CreateWindowEx(NULL,this->ClassName,this->WindowName,WS_OVERLAPPEDWINDOW,0,0,rect.right - rect.left,rect.bottom - rect.top,NULL,NULL,hInstance,NULL);
	if (!hWnd)return false;

	this->DisplayWindow(true);

	return true;
}

void CoreWindow::DisplayWindow(bool Show)
{
	if(Show)ShowWindow(hWnd,SW_SHOW);
	else ShowWindow(hWnd,SW_HIDE);

	this->Visible = Show;
}

void CoreWindow::ProcessMessages()
{
	ZeroMemory(&Messanger,sizeof(MSG));

	while(GetMessage(&Messanger,NULL,0,0))
	{
		TranslateMessage(&Messanger);
		DispatchMessage(&Messanger);
	}
	std::cout << "Message processing has ended.";
		ReturnValue = Messanger.wParam;
}

void CoreWindow::DestroyWindow()
{
	hWnd = NULL;
	hInstance = NULL;
	Visible = false;
	PostQuitMessage(0);
}

bool CoreWindow::isinShow()
{
	return Visible;
}

// Rect: Determines location of the window. 
void CoreWindow::SetLocation(RECT Location)
{
	X = Location.left;
	Y = Location.top;
}

RECT CoreWindow::GetLocation()
{
	RECT rect;
	rect.left = X;
	rect.top = Y;

	return rect;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}break;
	default:DefWindowProc(hWnd, Message, wParam, lParam); 
	}
}
