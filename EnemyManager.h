#pragma once
class EnemyManager : public SingleTon<EnemyManager>
{
public:
	
	void Init();
	void Update();
	void DeleteEnemy(BaseTransform* pTarget);
	void CreateEnemy(int x, int y, BaseImageObject* pObj, bool coll = false);
	


	PROPERTYARRAY_FUNC(list<BaseTransform*>*, Enemys, &mListEnemy)
	PROPERTY_FUNC(int, EnemyCount, miTotalEnemyCount)


	EnemyManager();
	virtual ~EnemyManager();

private:
	list<BaseTransform*> mListEnemy;
	int miTotalEnemyCount;
};

