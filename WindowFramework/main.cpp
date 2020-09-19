#include <iostream>
#include <chrono>
#include <ctime>

#include "CoreWindow.h"

using namespace std;
#pragma warning(disable:4996)

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine,int nCmdShow) // If a errpr happens, make this line comment and use main() function instead of WinMain
//int main()                                                                                    //Error occurs because you have not required library or header. WinMain function is better optimized than main                                                                                                 () function. it is better to use WinMain but using main() is not imposibble either
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	int ReturnValue = 0;
	
	char NowText[9] = "        ";
	
	strftime(NowText,sizeof(NowText),"%H:%M:%S",now);

	CoreWindow* Window = new CoreWindow();
	now = std::localtime(&t);
	WriteDebug("Window is initializing",NowText,"CoreWindow");
	if (Window->InitializeWindow("WindowName",0,0,800,600))
	{
		now = std::localtime(&t);
		strftime(NowText, sizeof(NowText), "%H:%M:%S", now);
		WriteDebug("Window has initialized!", NowText, "CoreWindow");
		now = std::localtime(&t);
		strftime(NowText, sizeof(NowText), "%H:%M:%S", now);
		WriteDebug("Message processing is started!", NowText, "CoreWindow");
		Window->ProcessMessages();
		ReturnValue = Window->ReturnValue;
	}

	delete Window;
	return ReturnValue;
}