#pragma once

enum class Direction{ DOWN = 0, UP, LEFT, RIGHT};

class Actor
{
public:
	
	void Init();
	void Update();
	void Render(HDC backDC);
	void Release();


	

	Actor();
	virtual ~Actor();
private:
	PROPERTY_FUNC(POINT, Pos, mPos)
	PROPERTY_FUNC(Direction, Dir, mDir)
	PROPERTY_FUNC(bool, isDead, isDead)

	//애니메이션 변수
};
