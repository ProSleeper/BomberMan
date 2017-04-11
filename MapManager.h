#pragma once
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
	//Map arrMap[arrSizeX][arrSizeY];
	vector<vector<Map>> TileMap;
	int arr[11][15] = {{	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
};