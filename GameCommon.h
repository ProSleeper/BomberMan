#pragma once
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <list>
#include <vector>
#include <random>
#include <cstdlib>
#include <time.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

using namespace std;

#define ROOT2 1.41421f

#define PROPERTY_FUNC(_Type, _FuncName, _Value)\
public: _Type Get##_FuncName()\
{return _Value;}\
public: void Set##_FuncName(_Type _v)\
{_Value = _v;}

#define PROPERTYARRAY_FUNC(Type, FuncName, Value)\
public : Type Get##FuncName()\
{return Value;}


#define WINMGR WindowManager::Instance()
#define GAMEMGR GameManager::Instance()
#define FPSMGR FrameCheckManager::Instance()
#define IMAGEMGR ImageManager::Instance()
#define COLLMGR CollisionManager::Instance()
#define ENEMYMGR EnemyManager::Instance()
#define EFECTMGR EffectManager::Instance()
#define OBJECTMGR ObjectManager::Instance()
#define MAPMGR MapManager::Instance()

#define GETKEY(ARROW) ((GetAsyncKeyState(ARROW) & 0x8000) == 0x8000)
#define GETKEYDOWN(key, value, func)\
if((GetAsyncKeyState(key) & 0x8000) == 0x8000 &&\
value == false)\
{func(); value = true;}\
if(value)\
{\
	if((GetAsyncKeyState(key) & 0x8001) == 0x0000)\
	{value = false;}\
}

#define GETKEYUP(key, value, func)\
if((GetAsyncKeyState(key) & 0x8000) == 0x8000 &&\
value == false)\
{ value = true;}\
if(value)\
{\
	if((GetAsyncKeyState(key) & 0x8001) == 0x0000)\
	{func();value = false;}\
}
enum class OBJECTTAG
{
	TAG_NONE,
	TAG_BOX,
	TAG_PLAYER,
	TAG_ENEMY,
	TAG_BOMB,
	TAG_EXPLOSION,
	TAG_BOSS,
	TAG_MAX
};

enum class IMAGETYPE
{
	IT_BACK = 0,
	IT_BACKGROUND,
	IT_OBJECT,
	IT_PLAYER,
	IT_ENEMY,
	IT_MAX
};

enum class ACTORDIRECTION
{
	AD_UP = 0,
	AD_DOWN,
	AD_LEFT,
	AD_RIGHT
};

#include "SingleTon.cpp"
#include "WindowManager.h"
#include "Image.h"
#include "ImageManager.h"
#include "Time.h"
#include "BaseTransform.h"
#include "BaseImageObject.h"
#include "BaseTargetObject.h"
#include "BaseCollObject.h"

#include "CollisionManager.h"
#include "Map.h"

#include "Object.h"
#include "EnemyManager.h"


#include "EffectManager.h"
#include "Animation.h"
#include "IndexAnimation.h"
#include "LoopAnimation.h"
#include "Explosion.h"
#include "Bomb.h"

#include "Player.h"
#include "Enemy.h"
#include "Wall.h"
#include "Box.h"

#include "GameManager.h"
#include "FrameCheckManager.h"
#include "RenderManager.h"


#include "ObjectManager.h"
#include "MapManager.h"


#include "Actor.h"


const int SCREENSIZEX = 1600;
const int SCREENSIZEY = 900;

const int TILECOUNTX = 15;
const int TILECOUNTY = 27;
const int TILESIZE = 60;
const int HALFTILESIZE = 30;

const int PLAYERSPEED = 3;
const int MONSTERSPEED = 2;
