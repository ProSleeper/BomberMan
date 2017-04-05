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
	TAG_PLAYER,
	TAG_PLAYER_BULLET,
	TAG_ENEMY,
	TAG_ENEMY_BULLET,
	TAG_BOSS,
	TAG_MAX
};

enum class VECTORBULLET
{
	VB_NORTH,
	VB_SOUTH,
	VB_EAST,
	VB_WEST
};

enum class IMAGETYPE
{
	IT_BACK = 0,
	IT_OBJECT,
	IT_PLAYER,
	IT_ENEMY,
	IT_WALL,
	IT_BOMB,
	IT_EXPLOSION,
	IT_SPRITE,
	IT_MAX
};

enum class PLAYERMOVE
{
	PM_UP = 0,
	PM_DOWN,
	PM_LEFT,
	PM_RIGHT
};

#include "SingleTon.cpp"
#include "WindowManager.h"
#include "Image.h"
#include "ImageManager.h"
#include "BaseTransform.h"
#include "BaseAnimTransform.h"
#include "BaseImageObject.h"
#include "BaseAnimImageObject.h"
#include "BaseTargetObject.h"
#include "BaseCollObject.h"
#include "Time.h"
#include "CollisionManager.h"
#include "Map.h"
#include "Enemy.h"

#include "EnemyManager.h"

#include "Explosion.h"
#include "EffectManager.h"
#include "Bomb.h"
#include "Player.h"
#include "GameManager.h"
#include "FrameCheckManager.h"
#include "Wall.h"
#include "RenderManager.h"

#include "Object.h"
#include "MapManager.h"
#include "Box.h"

#include "Actor.h"


static const int ScreenSizeX = 1600;
static const int ScreenSizeY = 900;



