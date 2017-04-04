#pragma once
class EffectManager : public SingleTon<EffectManager>
{
public:

	PROPERTYARRAY_FUNC(list<BaseTransform*>*, Effects, &mListEffects)

	void CreateEffect(int x, int y);
	void Update();
	void Render(HDC backDC);
	void Release();

	EffectManager();
	virtual ~EffectManager();
private:
	list<BaseTransform*> mListEffects;
};

