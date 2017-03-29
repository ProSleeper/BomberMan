#pragma once

enum class Direction{ DOWN = 0, UP, LEFT, RIGHT};


class Actor
{
public:
	
	void Init();
	void Update();
	void Render(HDC backDC);
	void Release();


	PROPERTY_FUNC(POINT, Pos, mPos)
	PROPERTY_FUNC(Direction, Dir, mDir)
	PROPERTY_FUNC(bool, isDead, isDead)

	Actor();
	virtual ~Actor();
private:
	POINT mPos;
	Direction mDir;
	bool isDead;
	HDC mHmemDC;
	HDC hdc;

	//애니메이션 변수
};
