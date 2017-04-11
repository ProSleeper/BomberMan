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
	void DeleteObject();
	bool GetTag(int x, int y);

	
	ObjectManager();
	virtual ~ObjectManager();
	list<BaseImageObject*> mObjectList;
	Box * box;
};

