#pragma once
class WindowManager : public SingleTon<WindowManager>
{
public:

	
	WindowManager();
	virtual ~WindowManager();

	void CreateWindowManager(HINSTANCE hInst, int w, int y, char *name);
	int GameLoop();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
	//void ResizeWindow();


private:
	HINSTANCE		mHinst;
	PROPERTY_FUNC(HWND, hWnd, mHwnd)
		
	static WindowManager* instance;
};
