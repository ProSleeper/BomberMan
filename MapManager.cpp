#include "GameCommon.h"

MapManager::MapManager()
{
	arrMap.assign(arrSizeX, vector<Map>(arrSizeY));

	for (int x = 0; x < arrSizeX; x++)
	{
		for (int y = 0; y < arrSizeY; y++)
		{
			arrMap[x][y].Init(MapSize * y, MapSize * x, MapSize, MapSize,/**/ 52, 49, 16, 16, IMAGETYPE::IT_OBJECT);
		}
	}

//if(y > 6 && y < 20 && x > 2 && x < 12)
//{
//	arrMap[x][y].Init(MapSize * y, MapSize * x, MapSize, MapSize,/**/ 35, 49, 16, 16, IMAGETYPE::IT_OBJECT);
//}
//else
//{
//}
	//for(int i = 3; i < 13; i++)
	//{
	//	for(int j = 7; j < 21; j++)
	//	{
	//		arrMap[i][j].Init(MapSize * y, MapSize * x, MapSize, MapSize,/**/ 52, 49, 16, 16, IMAGETYPE::IT_OBJECT);
	//	}
	//}
}

MapManager::~MapManager()
{
}
Map MapManager::GetIdx(int x, int y)
{
	return arrMap[x][y];
}
bool MapManager::IsMove(int x, int y)
{
	return arrMap[x][y].GetIsMove();
}
void MapManager::Render(HDC backDC)
{
	//int temp = SetROP2(backDC, R2_MASKPEN);
	for(int x = 0; x < arrSizeX; x++)
	{
		for(int y = 0; y < arrSizeY; y++)
		{
			arrMap[x][y].Render(backDC);
			//Rectangle(backDC, arrMap[x][y].GetPosX(), arrMap[x][y].GetPosY(), arrMap[x][y].GetPosX() + MapSize, arrMap[x][y].GetPosY() + MapSize);
		}
	}
	//SetROP2(backDC, temp);
}
