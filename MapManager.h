#pragma once

enum class TILETYPE_PIECETOWN
{
	TT_DEFAULT,
	TT_DEFAULT_BUILDING_SHADOW,
	TT_INNER_BUILDING = 3,
	TT_OUTTER_BUILDING = 12,
	TT_MAX
};


#define TT(X) static_cast<int>(TILETYPE_PIECETOWN::X)

class MapManager : public SingleTon<MapManager>
{
public:
	
	Map GetIdx(int x, int y);
	bool IsMove(int x, int y);
	void SetMove(int x, int y, bool bMove);
	
	void Render(HDC backDC);
	bool IsCollision(int x, int y, ACTORDIRECTION pDir);
	void MapSetting();


	MapManager();
	virtual ~MapManager();

	

private:
	
	RECT rect;
	vector<vector<Map>> TileMap;
	Map tile[TT(TT_MAX)];
};