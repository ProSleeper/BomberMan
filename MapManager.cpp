#include "GameCommon.h"

MapManager::MapManager()
{
	for (int x = 0; x < arrSizeX; x++)
	{
		for (int y = 0; y < arrSizeY; y++)
		{
			arrMap[x][y].Init(MapSize * y, MapSize * x, MapSize, MapSize,/**/ 17, 14, 16, 16, IMAGETYPE::IT_MAP);
		}
	}
}

MapManager::~MapManager()
{
}

void MapManager::Render(HDC backDC)
{
	for(int x = 0; x < arrSizeX; x++)
	{
		for(int y = 0; y < arrSizeY; y++)
		{
			arrMap[x][y].Render(backDC);
		}
	}
}
