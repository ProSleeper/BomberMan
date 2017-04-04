#include "GameCommon.h"

void ImageManager::LoadImages(HDC dc)
{
	mImage[static_cast<int>(IMAGETYPE::IT_BACK)].LoadBitImage(dc, "BackGround.bmp");
	mImage[static_cast<int>(IMAGETYPE::IT_MAP)].LoadBitImage(dc, "Stage1Object.bmp", RGB(16, 88, 48));
	mImage[static_cast<int>(IMAGETYPE::IT_PLAYER)].LoadBitImage(dc, "player.bmp", RGB(255, 255, 255));
	mImage[static_cast<int>(IMAGETYPE::IT_SPRITE)].LoadBitImage(dc, "88879.bmp", RGB(255, 255, 255));
}

Image* ImageManager::GetImage(IMAGETYPE type)
{
	return &mImage[static_cast<int>(type)];
}


ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
}
