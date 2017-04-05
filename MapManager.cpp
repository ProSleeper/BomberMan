#include "GameCommon.h"

MapManager::MapManager()
{
	arrMap.assign(arrSizeX, vector<Map>(arrSizeY));

	for (int x = 0; x < arrSizeX; x++)
	{
		for (int y = 0; y < arrSizeY; y++)
		{
			if ((x % 2) == 1 && (y % 2) == 1)
			{
				arrMap[x][y].Init(MapSize * y, MapSize * x, MapSize, MapSize,/**/ 69, 15, 16, 16, IMAGETYPE::IT_OBJECT);
			}
			else
			{
				arrMap[x][y].Init(MapSize * y, MapSize * x, MapSize, MapSize,/**/ 52, 49, 16, 16, IMAGETYPE::IT_OBJECT);
			}
			
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
			int temp = SetROP2(backDC, R2_MASKPEN);
			Rectangle(backDC, arrMap[x][y].GetpRendRect().left, arrMap[x][y].GetpRendRect().top, arrMap[x][y].GetpRendRect().left + MapSize, arrMap[x][y].GetpRendRect().top + MapSize);
			SetROP2(backDC, temp);
		}
	}
}
