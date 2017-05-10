#pragma once
class Bomb : public BaseImageObject
{
public:
	

	void Init(int x, int y, int tw, int th, float tTime);
	bool Update() override;
	void Render(HDC backDC);
	void Release();
	void DistanceExplode();
	void TimeBomb();

	Bomb();
	virtual ~Bomb();
private:
	HDC mHmemDC;
	Image* mpImage;
	RECT mBombRect;
	Animation* mBombAnimation;
	bool mUp;
	bool mDown;
	bool mLeft;
	bool mRight;
};

