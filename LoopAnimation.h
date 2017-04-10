#pragma once
class LoopAnimation : public Animation
{
public:

	bool Update(int x, int y) override;
	void Render(HDC backDC) override;
	void Release();

	LoopAnimation(IMAGETYPE pType, OBJECTTAG pTag);
	virtual ~LoopAnimation();
};

