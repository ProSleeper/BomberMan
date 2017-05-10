#pragma once
class Box : public BaseImageObject
{
public:

	void Init(int x, int y, float tTime);
	bool Update() override;
	void Render(HDC backDC) override;
	void Release();
	void DestroyBox();

	Box();
	virtual ~Box();

private:
	Animation* mBoxAnimation[2];
	Animation* mBox;

};

