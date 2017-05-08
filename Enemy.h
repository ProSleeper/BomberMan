#pragma once
class Enemy : public BaseImageObject
{
public:
	void Init(int x, int y, int w, int h, int useSizeX, int useSizeY, float tTime);
	bool Update() override;
	void Render(HDC backDC);
	void Release();
	void RandomDirection();

	Enemy();
	virtual ~Enemy();
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

	ACTORDIRECTION mEnemyDirection;
	Animation* mDirection[4];
	Animation* mEnemyAnimation;

};

