#pragma once
class LoopAnimation : public Animation
{
public:
	void Init(int x, int y, int MoveX, int MoveY, int w, int h, int totalWidth, int useWidth, float frameTime, bool bMotion) override;
	bool Update(int x, int y) override;
	void Render(HDC backDC) override;
	void Release();

	LoopAnimation(IMAGETYPE pType, OBJECTTAG pTag);
	virtual ~LoopAnimation();

private:
	
};

