#pragma once



class GameManager : public SingleTon<GameManager>
{
public:
	PROPERTY_FUNC(HDC, HDC, mHdc)
	PROPERTY_FUNC(float, pPointX, pPointX)
	PROPERTY_FUNC(float, pPointY, pPointY)
	void Init();
	void Loop();
	void Update();
	void Render();
	void Release();
	void DebugView();
	bool IsCrashObject(BaseTransform* lhs, BaseTransform* rhs);

	void CreateObject(BaseImageObject* pObj, bool bColl);
	
	PROPERTYARRAY_FUNC(list<BaseTransform*>*, Objects, &mListObjects)
	

	GameManager();
	virtual ~GameManager();
private:
	HDC mHdc;
	//HDC mHbackDc;
	Image* mScreen;
	Image* mBackGround;
	float pPointX;
	float pPointY;

	
	
	Bomb* bomb;
	Wall* mWall;
	Box* mBox;

	RECT mRect1;
	RECT mRect2;

	//BaseImageObject* mpObjects[static_cast<int>(OBJECTTYPE::OT_MAX)];
	list<BaseTransform*> mListObjects;
	
	void DeleteObjectCheck();
	/*static GameManager* instance;*/
};


