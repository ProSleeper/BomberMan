#pragma once
class Player : public BaseImageObject
{
public:
	

	void Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime);
	bool Update();
	void Render(HDC backDC);
	void Release();

	void MoveCheck(int pos, PLAYERDIRECTION pm);
	void Player::RectColl(RECT& rect, int x, int y, int w, int h);

	PROPERTY_FUNC(POINT, pPos, mPos)
	PROPERTY_FUNC(int, Width, miWidth)
	PROPERTY_FUNC(int, Height, miHeight)

	Player(IMAGETYPE type);
	virtual ~Player();
private:
	HDC mHmemDC;
	POINT mPos;
	int miWidth;
	int miHeight;
	int useSizeX;
	int useSizeY;
	int startX;
	int startY;
	bool mIsBomb;
	Image* mpImage;
	Bomb* bomb;
	bool IsBomb = false;

	RECT up;
	RECT down;
	RECT left;
	RECT right;

	bool mbUp;
	bool mbDown;
	bool mbLeft;
	bool mbRight;

	int arrX;
	int arrY;

};

