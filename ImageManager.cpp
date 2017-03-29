#include "GameCommon.h"

void ImageManager::LoadImages(HDC dc)
{
	mImage[static_cast<int>(IMAGEBIT::OBJ_BACK)].LoadBitImage(dc, "BackGround.bmp");
	mImage[static_cast<int>(IMAGEBIT::OBJ_MAP)].LoadBitImage(dc, "Stage1Object.bmp", RGB(16, 88, 48));
	mImage[static_cast<int>(IMAGEBIT::ACTOR_PLAYER)].LoadBitImage(dc, "player.bmp", RGB(255, 255, 255));

	/*
	mImage[static_cast<int>(IMAGEBIT::OBJ_WALL)].LoadBitImage(dc, "enemy.bmp");
	mImage[static_cast<int>(IMAGEBIT::OBJ_BOX)].LoadBitImage(dc, "bullet.bmp");
	mImage[static_cast<int>(IMAGEBIT::OBJ_BOMB)].LoadBitImage(dc, "bullet.bmp");
	
	mImage[static_cast<int>(IMAGEBIT::ACTOR_PLAYER)].LoadBitImage(dc, "bullet.bmp");
	mImage[static_cast<int>(IMAGEBIT::ACTOR_ENEMY)].LoadBitImage(dc, "bullet.bmp");

	mImage[static_cast<int>(IMAGEBIT::IMGBIT_MAX)].LoadBitImage(dc, "bullet.bmp");*/
}

Image* ImageManager::GetImage(IMAGEBIT type)
{
	return &mImage[static_cast<int>(type)];
}

ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
}
