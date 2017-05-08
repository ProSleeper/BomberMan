#pragma once
class ObjectManager : public SingleTon<ObjectManager>
{
public:
	void Init();
	void Update();
	void Render(HDC backDC);
	void Release();
	bool DistanceExplode(int x, int y);
	void DrawRect(HDC backDC, int x, int y);

	void CreateObject(BaseImageObject* pObj);
	void CreateBomb(BaseImageObject* pObj);
	void DeleteObject();
	bool GetTag(int x, int y);
	bool IsCrashObject(BaseTransform* lhs, BaseTransform* rhs);
	
	ObjectManager();
	virtual ~ObjectManager();

private:
	GETTER(list<BaseImageObject*>, ObjectList, mObjectList)
	list<BaseImageObject*> mBombList;
	Box * box;
	Enemy* arrEnemy[3];
	int enemyCount;
	int arr[11][15] = {{10, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1},
						{0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
						{0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
						{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
						{0, 0, 9, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1},
						{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
						{0, 0, 1, 0, 9, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
						{0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0}};
};

