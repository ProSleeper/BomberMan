#pragma once
class IndexAnimation : public Animation
{
public:

	void Init(int x, int y, POINT* arrPoint, int w, int h, int index, float frameTime);
	bool Update(int x, int y) override;
	void Render(HDC backDC) override;
	void Release();

	IndexAnimation(IMAGETYPE pType, OBJECTTAG pTag);
	~IndexAnimation();
};

