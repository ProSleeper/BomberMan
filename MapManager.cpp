#include "GameCommon.h"
#include "MapData.h"

//여기 전부 갈아 없어야 함!
//문제를 찾아서 출발~

MapManager::MapManager()
{
	TileMap.assign(TILECOUNTX, vector<Map>(TILECOUNTY));

	MapSetting();
	
	for (int x = 0; x < 13; x++)
	{
		for (int y = 0; y < 17; y++)
		{
			TileMap[x][y] = tile[mapData[x][y]];
			TileMap[x][y].SetPosX(TILESIZE * y + 300);
			TileMap[x][y].SetPosY(TILESIZE * x + 60);
			if (mapData[x][y] < 2)
			{
				TileMap[x][y].SetIsMove(true);
			}
			else
			{
				TileMap[x][y].SetIsMove(false);
			}
			
		}
	}
}

MapManager::~MapManager()
{
}

Map MapManager::GetIdx(int x, int y)
{
	return TileMap[x - 1][y - 5];
}

bool MapManager::IsMove(int x, int y)
{
	return TileMap[x - 1][y - 5].GetIsMove();
}

void MapManager::SetMove(int x, int y, bool bMove)
{
	return TileMap[x - 1][y - 5].SetIsMove(bMove);
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
	tile[TT(TT_DEFAULT)].Init(0, 0, 52, 49, 16, 16, IMAGETYPE::IT_OBJECT);
	tile[TT(TT_DEFAULT_BUILDING_SHADOW)].Init(0, 0, 52, 32, 16, 16, IMAGETYPE::IT_OBJECT);
	tile[TT(TT_INNER_BUILDING)].Init(0, 0, 35, 32, 16, 16, IMAGETYPE::IT_OBJECT);
	tile[TT(TT_OUTTER_BUILDING)].Init(0, 0, 35, 49, 16, 16, IMAGETYPE::IT_OBJECT);

}

bool MapManager::IsCollision(int x, int y, ACTORDIRECTION pDir)
{
	int MoveLTgap = 25;
	int MoveRBgap = 35;
	x -= 300;
	y -= 60;

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