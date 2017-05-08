#pragma once

class GameManager : public SingleTon<GameManager>
{
public:
	void Init();
	void Loop();
	void Update();
	void Render();
	void Release();
	void DebugView();
	list<BaseImageObject*> mListObjects;
	GameManager();
	virtual ~GameManager();
private:
	
	Image* mScreen;
	Image* mBackGround;

	PROPERTY_FUNC(HDC, HDC, mHdc)
		PROPERTY_FUNC(float, pPointX, pPointX)
		PROPERTY_FUNC(float, pPointY, pPointY)
};


