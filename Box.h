#pragma once
class Box : public BaseImageObject
{
public:

	void Init(int x, int y, int w, int h, int tw, int th, float tTime);
	bool Update() override;
	void Render(HDC backDC) override;
	void Release();
	void Box::DestroyBox();

	Box();
	virtual ~Box();

private:
	Animation* mBoxAnimation[2];
	Animation* mBox;

};

