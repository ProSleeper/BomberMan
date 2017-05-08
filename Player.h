#pragma once
class Player : public BaseImageObject
{
public:
	void Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime);
	bool Update();
	void Render(HDC backDC);
	void Release();
	void DropBomb();

	Player();
	virtual ~Player();
private:
	HDC mHmemDC;
	int useSizeX;
	int useSizeY;
	int startX;
	int startY;
	Image* mpImage;
	Bomb* bomb;
	bool mIsBomb = false;
	Animation* mPlayerAnimation;
	Animation* mDirection[4];
};

