#pragma once
class Player : public BaseImageObject
{
public:
	

	void Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime);
	bool Update();
	void Render(HDC backDC);
	void Release();
	void DropBomb();

	void MoveCheck(int pos, ACTORDIRECTION pm);
	void Player::RectColl(RECT& rect, int x, int y, int w, int h);

	Player();
	virtual ~Player();
private:
	HDC mHmemDC;
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

};

