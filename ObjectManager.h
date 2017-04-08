#pragma once
class ObjectManager : public SingleTon<ObjectManager>
{
public:

	void Init();
	void Update();
	void Render(HDC backDC);
	void Release();
	bool IsCollision(int x, int y, PLAYERDIRECTION pDir);

	void CreateObject(BaseImageObject* pObj);
	void ChangeObject(int x, int y, int w, int h, bool bMove = true);
	void DeleteObject();
	bool IsMove(int x, int y);
	RECT GetRECT(int x, int y);
	
	ObjectManager();
	virtual ~ObjectManager();
private:
	vector<vector<BaseImageObject*>> mListObject;
	RECT rect;
};

