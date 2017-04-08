#include "GameCommon.h"

void EffectManager::CreateEffect(int x, int y)
{
	/*Explosion* explosion = new Explosion;
	explosion->Init(x, y, 40, 40, 320, 40, 1, IMAGETYPE::IT_EXPLOSION);
	mListEffects.push_back(explosion);*/
}

void EffectManager::Update()
{
	//for_each(mListEffects.begin(), mListEffects.end(), [&](BaseImageObject* bio){bio->Update(); });

	/*for (auto iter = mListEffects.begin();  iter != mListEffects.end();)
	{
		BaseImageObject* pObj = (BaseImageObject*)(*iter);
		if (pObj->Update() == false)
		 {
			delete (*iter);
			iter = mListEffects.erase(iter);
		}
		else
		{
			iter++;
		}
	}*/
}

void EffectManager::Render(HDC backDC)
{

	/*for(auto iter = mListEffects.begin(); iter != mListEffects.end(); iter++)
	{
		BaseImageObject* pObj = (BaseImageObject*)(*iter);
		pObj->Render(backDC);
	}*/
	//for_each(mListEffects.begin(), mListEffects.end(), [&](BaseImageObject* bio){bio->Render(backDC);});
}

void EffectManager::Release()
{
	/*for_each(mListEffects.begin(), mListEffects.end(), [&](BaseTransform* bco){delete bco; });
	mListEffects.clear();*/
}

EffectManager::EffectManager()
{
	mListEffects.clear();
}

EffectManager::~EffectManager()
{
	Release();
}
