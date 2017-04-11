#include "GameCommon.h"

MapManager::MapManager()
{
	TileMap.assign(TILECOUNTX, vector<Map>(TILECOUNTY));

	for(int x = 1; x < TILECOUNTX - 1; x++)
	{
		for(int y = 5; y < TILECOUNTY - 5; y++)
		{
			TileMap[x][y].Init(TILESIZE * y, TILESIZE * x, TILESIZE, TILESIZE,/**/ 52, 49, 16, 16, IMAGETYPE::IT_OBJECT);
		}
	}
	MapSetting();
}

MapManager::~MapManager()
{
}
Map MapManager::GetIdx(int x, int y)
{
	return TileMap[x][y];
}

bool MapManager::IsMove(int x, int y)
{
	return TileMap[x][y].GetIsMove();
}

void MapManager::SetMove(int x, int y, bool bMove)
{
	return TileMap[x][y].SetIsMove(bMove);
}

void MapManager::Render(HDC backDC)
{
	for(int x = 1; x < TILECOUNTX - 1; x++)
	{
		for(int y = 5; y < TILECOUNTY - 5; y++)
		{
			TileMap[x][y].Render(backDC);
		}
	}
}

void MapManager::MapSetting()
{
	//세로벽
	for(int y = 1; y < 14; y++)
	{
		TileMap[y][5].ImageChange(35, 49);
		TileMap[y][5].SetIsMove(false);

		TileMap[y][21].ImageChange(35, 49);
		TileMap[y][21].SetIsMove(false);
	}

	//가로벽
	for(int x = 6; x < 21; x++)
	{
		TileMap[1][x].ImageChange(35, 49);
		TileMap[1][x].SetIsMove(false);

		TileMap[13][x].ImageChange(35, 49);
		TileMap[13][x].SetIsMove(false);
	}

	/*for(int y = 3; y < 13; y += 2)
	{
		for(int x = 7; x < 21; x += 2)
		{
			TileMap[y][x].ImageChange(35, 32);
			TileMap[y][x].SetIsMove(false);

			TileMap[y + 1][x].ImageChange(52, 32);
		}
	}*/

	for (int i = 0; i < 11 ; i++)
	{
		for (int j = 0; j < 15 ; j++)
		{
			if (arr[i][j] == 1)
			{
				TileMap[i + 2][j + 6].ImageChange(35, 32);
				TileMap[i + 2][j + 6].SetIsMove(false);
			}
		}
	}
	

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