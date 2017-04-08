#pragma once
class MapManager : public SingleTon<MapManager>
{
public:
	
	Map GetIdx(int x, int y);
	bool IsMove(int x, int y);
	void Render(HDC backDC);

	MapManager();
	virtual ~MapManager();

	

private:
	

	//Map arrMap[arrSizeX][arrSizeY];
	vector<vector<Map>> arrMap;
};