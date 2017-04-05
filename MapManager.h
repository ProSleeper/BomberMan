#pragma once
class MapManager : public SingleTon<MapManager>
{
public:
	MapManager();
	virtual ~MapManager();

	void Render(HDC backDC);

private:
	static const int arrSizeX = 18;
	static const int arrSizeY = 32;
	static const int MapSize = 50;

	//Map arrMap[arrSizeX][arrSizeY];
	vector<vector<Map>> arrMap;
};