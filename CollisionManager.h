#pragma once
class CollisionManager : public SingleTon<CollisionManager>
{
public:
	void CreateCollider(BaseTransform* pTarget);
	void Update();
	void Render(HDC backDC);
	void Release();

	void DeleteCollider(BaseTransform* pTarget);
	bool IsCollision(BaseCollObject* pSrc, BaseCollObject* pDest);
	bool GetCollTag(OBJECTTAG pSrc, OBJECTTAG pTarget);
	void SetCollTag(OBJECTTAG pSrc, OBJECTTAG pTarget, bool value, bool setBoth = true);

	bool RePosCheck(BaseTransform* pTarget);

	PROPERTYARRAY_FUNC(list<BaseCollObject*>*, Collider, &mCollObj)
	CollisionManager();
	virtual ~CollisionManager();
private:
	list<BaseCollObject*> mCollObj;
	bool collTag[static_cast<int>(OBJECTTAG::TAG_MAX)][static_cast<int>(OBJECTTAG::TAG_MAX)] = {0,};


};

