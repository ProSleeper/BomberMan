#pragma once
class WindowManager : public SingleTon<WindowManager>
{
public:

	PROPERTY_FUNC(HWND, hWnd, mHwnd)
	WindowManager();
	virtual ~WindowManager();

	void CreateWindowManager(HINSTANCE hInst, int w, int y, char *name);
	int GameLoop();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	//void ResizeWindow();


private:
	HINSTANCE		mHinst;
	HWND			mHwnd;
		
	static WindowManager* instance;
};
