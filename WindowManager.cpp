#include "GameCommon.h"


WindowManager::WindowManager()
{
	mHinst = nullptr;
	mHwnd = nullptr;
}


WindowManager::~WindowManager()
{
}

void WindowManager::CreateWindowManager(HINSTANCE hInst, int sizeX, int sizeY, char *name)
{
	mHinst = hInst;

	WNDCLASS WndClass;
	ZeroMemory(&WndClass, sizeof(WndClass));

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject((WHITE_BRUSH));
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDC_ICON);
	WndClass.hInstance = mHinst;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = name;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	mHwnd = CreateWindow(name, name, WS_BORDER | WS_CAPTION | WS_SYSMENU, 100, 100, sizeX, sizeY, NULL, (HMENU)NULL, mHinst, NULL);

	ShowWindow(mHwnd, SW_SHOW);
}

int WindowManager::GameLoop()
{
	MSG Message;
	while(true)
	{
		if(PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
		{
			if(Message.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
		else
		{
			GAMEMGR->Loop();
		}
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK  WindowManager::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch(iMessage)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		default:
		{
			return DefWindowProc(hWnd, iMessage, wParam, lParam);
		}
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

