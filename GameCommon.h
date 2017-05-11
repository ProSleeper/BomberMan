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

#define PROPERTY_FUNC(type, funcName, value) \
    protected: type value; \
	public: type Get##funcName()		 { return value; } \
	public: void Set##funcName(type _v)  { value = _v;   } \

#define PROPERTYARRAY_FUNC(Type, FuncName, Value)\
public : Type Get##FuncName()\
{return Value;}

#define GETTER(type, funcName, value) \
    protected: type value; \
	public: type Get##funcName()		 { return value; } \


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
#include "MyQueue.h"
#include "BaseTransform.h"
#include "BaseImageObject.h"
#include "Map.h"
#include "Animation.h"
#include "IndexAnimation.h"
#include "LoopAnimation.h"
#include "Explosion.h"
#include "Bomb.h"
#include "Player.h"
#include "Enemy.h"
#include "Box.h"
#include "GameManager.h"
#include "FrameCheckManager.h"
#include "ObjectManager.h"
#include "MapManager.h"
#include "Actor.h"


const int SCREENSIZEX = 1600;
const int SCREENSIZEY = 900;

const int TILECOUNTX = 13;
const int TILECOUNTY = 17;
const int TILESIZE = 60;
const int HALFTILESIZE = 30;

const int PLAYERSPEED = 3;
const int MONSTERSPEED = 2;
