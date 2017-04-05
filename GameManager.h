#pragma once

enum class OBJECTTYPE
{
	OT_MAP,
	OT_PLAYER,
	OT_ENEMY,

	OT_MAX
};

class GameManager : public SingleTon<GameManager>
{
public:

	
	PROPERTY_FUNC(HDC, HDC, mHdc)
	PROPERTY_FUNC(float, pPointX, pPointX)
	PROPERTY_FUNC(float, pPointY, pPointY)
		/*static GameManager* Instance()
		{
			if(instance == nullptr)
			{
				instance = new GameManager;
			}
			return instance;
		}*/
	
	void Init();
	void Loop();
	void Update();
	void Render();
	void Release();
	void DebugView();


	void CreateObject(BaseTransform* pObj, bool bColl);
	
	PROPERTYARRAY_FUNC(list<BaseTransform*>*, Objects, &mListObjects)
	

	GameManager();
	virtual ~GameManager();
private:
	HDC mHdc;
	//HDC mHbackDc;
	Image* mMap;
	float pPointX;
	float pPointY;

	Player *mAnimation;
	Bomb* bomb;

	//BaseImageObject* mpObjects[static_cast<int>(OBJECTTYPE::OT_MAX)];
	list<BaseTransform*> mListObjects;
	
	void DeleteObjectCheck();
	/*static GameManager* instance;*/
};


