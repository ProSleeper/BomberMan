#pragma once

class ImageManager : public SingleTon<ImageManager>
{
public:

	void LoadImages(HDC dc);

	Image* GetImage(IMAGETYPE type);

	ImageManager();
	virtual ~ImageManager();

private:
	Image mImage[static_cast<int>(IMAGETYPE::IT_MAX)];
};

