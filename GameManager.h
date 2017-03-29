#pragma once
class GameManager : public SingleTon<GameManager>
{
public:
	
	PROPERTY_FUNC(HDC, Hdc, mHdc)
	PROPERTY_FUNC(HDC, BackHdc, mHbackDc)
	
	void Init();
	void Loop();
	void Update();
	void Render();
	void Release();
	void DebugView();
	

	GameManager();
	virtual ~GameManager();
private:
	HDC mHdc;
	HDC mHbackDc;
	Image* mBackImg;

	Player mPlayer;
	Map mMap;
	Map mMap2;
	/*Map mBomb2;
	Map mBomb1;
	Map mBomb;*/

};


