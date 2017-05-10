#include "GameCommon.h"

void Bomb::Init(int x, int y, int tw, int th, float tTime)
{
	miPosX = x;
	miPosY = y;

	mUp = true;
	mDown = true;
	mLeft = true;
	mRight = true;

	mBombRect.left = 1;
	mBombRect.top = 1;
	mBombRect.right = 1;
	mBombRect.bottom = 1;

	mTag = OBJECTTAG::TAG_BOMB;
	mBombAnimation = new LoopAnimation(IMAGETYPE::IT_OBJECT, OBJECTTAG::TAG_BOMB);
	mBombAnimation->Init(miPosX, miPosY, 103, 151, 16, 16, 51, 17, 0.3f, true);
	//DistanceExplode();
	mTime.SetUpTime(2);
}

bool Bomb::Update()
{
	if (mTime.TimeCheck())
	{
		Explosion* explosion;
		explosion = new Explosion;
		explosion->Init(miPosX, miPosY, 1, 117, 85, 17, 0.05f);
		OBJECTMGR->CreateObject(explosion);
		for (int y = 1; y <= mBombRect.top; y++)
		{
			if (y == mBombRect.top)
			{
				explosion = new Explosion;
				explosion->Init(miPosX, miPosY - y * TILESIZE, 1, 202, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX , miPosY - y * TILESIZE , 1, 134, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
		}
		//�Ʒ�
		for(int y = 1; y <= mBombRect.bottom; y++)
		{
			if(y == mBombRect.bottom)
			{
				explosion = new Explosion;
				explosion->Init(miPosX, miPosY + y * TILESIZE, 1, 185, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX, miPosY + y * TILESIZE, 1, 134, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
		}
		//����
		for(int x = 1; x <= mBombRect.left; x++)
		{
			if(x == mBombRect.left)
			{
				explosion = new Explosion;
				explosion->Init(miPosX - x * TILESIZE, miPosY, 1, 66, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX - x * TILESIZE, miPosY, 1, 100, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
		}
		//������
		for(int x = 1; x <= mBombRect.right; x++)
		{
			if(x == mBombRect.right)
			{
				explosion = new Explosion;
				explosion->Init(miPosX + x * TILESIZE, miPosY, 1, 83, 85, 17, 0.05f);
				OBJECTMGR->CreateObject(explosion);
				continue;
			}
			explosion = new Explosion;
			explosion->Init(miPosX + x * TILESIZE, miPosY, 1, 100, 85, 17, 0.05f);
			OBJECTMGR->CreateObject(explosion);
		}
		MAPMGR->SetMove(miPosY / TILESIZE, miPosX / TILESIZE, true);
		delete mBombAnimation;
		return false;
	}

	mBombAnimation->Update(miPosX, miPosY);
	return true;
}


void Bomb::Render(HDC backDC)
{
	mBombAnimation->Render(backDC);
}

void Bomb::Release()
{
}

void Bomb::TimeBomb()
{
	mTime.SetUpTime(0.1f);
}

Bomb::Bomb()
{
	miPosX = 0;
	miPosY = 0;
}

Bomb::~Bomb()
{
	Release();
}

void Bomb::DistanceExplode()
{
	for(int i = 0; i < 5; i++)
	{
		//���⼭�� ��ǥ�� �ְ�
		//��
		if(mUp &&MAPMGR->IsMove(miPosY / TILESIZE - 1 - i, miPosX / TILESIZE))
		{
			mBombRect.top++;
		}
		else
		{
			mUp = false;
		}
		//�Ʒ�
		if(mDown &&MAPMGR->IsMove(miPosY / TILESIZE + 1 + i, miPosX / TILESIZE))
		{
			mBombRect.bottom++;
		}
		else
		{
			mDown = false;
		}
		//����
		if(mLeft && MAPMGR->IsMove(miPosY / TILESIZE, miPosX / TILESIZE - 1 - i))
		{
			mBombRect.left++;
		}
		else
		{
			mLeft = false;
		}
		//������
		if(mRight && MAPMGR->IsMove(miPosY / TILESIZE, miPosX / TILESIZE + 1 + i))
		{
			mBombRect.right++;
		}
		else
		{
			mRight = false;
		}
	}
}
