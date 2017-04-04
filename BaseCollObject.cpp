#include "GameCommon.h"



void BaseCollObject::Init(BaseTransform * pTarget)
{
	mpTarget = pTarget;
}

void BaseCollObject::Update()
{
	mfPosX = mpTarget->GetPosX();
	mfPosY = mpTarget->GetPosY();

	miWidth = mpTarget->GetWidth();
	miHeight = mpTarget->GetHeight();
}

void BaseCollObject::Render(HDC backDC)
{
	//= GetROP2(backDC);
	int temp = SetROP2(backDC, R2_MASKPEN);
	Rectangle(backDC, mfPosX, mfPosY, mfPosX + miWidth, mfPosY + miHeight);
	SetROP2(backDC, temp);
}

BaseCollObject::BaseCollObject()
{
}


BaseCollObject::~BaseCollObject()
{
}
