#ifndef COREWINDOW_H_ 
#define COREWINDOW_H_
#define WIN32_LEAN_AND_MEAN

#define DEFAULT_LOCATION 0

#include <Windows.h>
#include <iostream>

#define WriteDebug(Text,Clock,ClassName) std::cout<<"["<<Clock<<"] "<<ClassName<< ": " << Text <<std::endl;

typedef struct Locatio 
{
	int X;
	int Y;
	int Width;
	int Height;
};

class CoreWindow
{
public:
	CoreWindow();
	 ~CoreWindow();

	//Variables
private:
	int X;
    int Y;
	int Width;
	int Height;

	bool Visible;

	LPCSTR ClassName;
	LPCSTR WindowName;

	HMENU Menu;

	MSG Messanger;

	HWND hWnd;
	HINSTANCE hInstance;
public:
	int ReturnValue = 0;

public:
	bool InitializeWindow(LPCSTR WindowName, int X, int Y, int Width, int Height);
	virtual void DisplayWindow(bool Show);
	void ProcessMessages();
	void DestroyWindow();

	bool isinShow();

	void SetLocation(RECT Location);
	RECT GetLocation();
	void SetSize(int Width,int Height);
	RECT GetSize();
	void SetWindowClass(WNDCLASSEX wnd);
	WNDCLASSEX GetWindowClass();


	HWND GetHWND();
	HINSTANCE GetHinstance();

private:
	WNDCLASSEX CreateWindowClass(LPCSTR ClassName, LPCSTR MenuName);

};

#endif // ! 
