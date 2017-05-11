#include "GameCommon.h"
#include "MapData.h"

//여기 전부 갈아 없어야 함!
//문제를 찾아서 출발~

MapManager::MapManager()
{
	TileMap.assign(TILECOUNTX, vector<Map>(TILECOUNTY));

	tile[TT(TT_DEFAULT)].Init(0,0, 52, 49, 16, 16, IMAGETYPE::IT_OBJECT);
	tile[TT(TT_DEFAULT_BUILDING_SHADOW)].Init(0, 0, 52, 32, 16, 16, IMAGETYPE::IT_OBJECT);
	tile[TT(TT_INNER_BUILDING)].Init(0, 0, 35, 32, 16, 16, IMAGETYPE::IT_OBJECT);
	tile[TT(TT_OUTTER_BUILDING)].Init(0, 0, 35, 49, 16, 16, IMAGETYPE::IT_OBJECT);


	for (int x = 0; x < 13; x++)
	{
		for (int y = 0; y < 17; y++)
		{
			
		}
	}

	for(int x = 1; x < TILECOUNTX - 1; x++)
	{
		for(int y = 5; y < TILECOUNTY - 5; y++)
		{
			TileMap[x][y].Init(TILESIZE * y, TILESIZE * x, 52, 32, 16, 16, IMAGETYPE::IT_OBJECT);
		}
	}
	MapSetting();
}

MapManager::~MapManager()
{
}
Map MapManager::GetIdx(int x, int y)
{
	return TileMap[x - 6][y - 2];
}

bool MapManager::IsMove(int x, int y)
{
	return TileMap[x - 6][y - 2].GetIsMove();
}

void MapManager::SetMove(int x, int y, bool bMove)
{
	return TileMap[x - 6][y - 2].SetIsMove(bMove);
}

void MapManager::Render(HDC backDC)
{
	for(int x = 0; x < TILECOUNTX; x++)
	{
		for(int y = 0; y < TILECOUNTY; y++)
		{
			TileMap[x][y].Render(backDC);
		}
	}
}

void MapManager::MapSetting()
{
	////세로벽
	//for(int y = 1; y < 14; y++)
	//{
	//	TileMap[y][5].ImageChange(35, 49);
	//	TileMap[y][5].SetIsMove(false);

	//	TileMap[y][21].ImageChange(35, 49);
	//	TileMap[y][21].SetIsMove(false);
	//}

	////가로벽
	//for(int x = 6; x < 21; x++)
	//{
	//	TileMap[1][x].ImageChange(35, 49);
	//	TileMap[1][x].SetIsMove(false);

	//	TileMap[13][x].ImageChange(35, 49);
	//	TileMap[13][x].SetIsMove(false);
	//}

	//for (int i = 0; i < 11 ; i++)
	//{
	//	for (int j = 0; j < 15 ; j++)
	//	{
	//		if (arr[i][j] == 1)
	//		{
	//			TileMap[i + 2][j + 6].ImageChange(35, 32);
	//			TileMap[i + 2][j + 6].SetIsMove(false);
	//		}
	//	}
	//}

}

bool MapManager::IsCollision(int x, int y, ACTORDIRECTION pDir)
{
	int MoveLTgap = 25;
	int MoveRBgap = 35;

	switch(pDir)
	{
		case ACTORDIRECTION::AD_UP:
		{
			rect.left = (x + MoveLTgap) / TILESIZE;
			rect.top = y / TILESIZE;

			rect.right = (x + MoveRBgap) / TILESIZE;
			rect.bottom = y / TILESIZE;
			return !(TileMap[rect.top][rect.left].GetIsMove() && TileMap[rect.bottom][rect.right].GetIsMove());
		}
		case ACTORDIRECTION::AD_DOWN:
		{
			rect.left = (x + MoveLTgap) / TILESIZE;
			rect.top = (y + TILESIZE - PLAYERSPEED) / TILESIZE;

			rect.right = (x + MoveRBgap) / TILESIZE;
			rect.bottom = (y + TILESIZE - PLAYERSPEED) / TILESIZE;
			return !(TileMap[rect.top][rect.left].GetIsMove() && TileMap[rect.bottom][rect.right].GetIsMove());
		}
		case ACTORDIRECTION::AD_LEFT:
		{
			rect.left = x / TILESIZE;
			rect.top = (y + MoveLTgap) / TILESIZE;

			rect.right = x / TILESIZE;
			rect.bottom = (y + MoveRBgap) / TILESIZE;
			return !(TileMap[rect.top][rect.left].GetIsMove() && TileMap[rect.bottom][rect.right].GetIsMove());
		}
		case ACTORDIRECTION::AD_RIGHT:
		{
			rect.left = (x + TILESIZE - PLAYERSPEED) / TILESIZE;
			rect.top = (y + MoveLTgap) / TILESIZE;

			rect.right = (x + TILESIZE - PLAYERSPEED) / TILESIZE;
			rect.bottom = (y + MoveRBgap) / TILESIZE;
			return !(TileMap[rect.top][rect.left].GetIsMove() && TileMap[rect.bottom][rect.right].GetIsMove());
		}
		default:
		{
			break;
		}
	}
	return true;
}