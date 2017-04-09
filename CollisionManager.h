#pragma once
class CollisionManager : public SingleTon<CollisionManager>
{
public:
	void CreateCollider(BaseTransform* pTarget);
	void Update();
	void Render(HDC backDC);
	void Release();

	void DeleteCollider(BaseTransform* pTarget);

	CollisionManager();
	virtual ~CollisionManager();
private:
	vector<vector<BaseTransform*>> mObjectVector;
	RECT rect;

};

