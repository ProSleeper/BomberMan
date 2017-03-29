#pragma once
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <list>
#include <random>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

using namespace std;

#define PROPERTY_FUNC(_Type, _FuncName, _Value)\
public: _Type Get##_FuncName()\
{return _Value;}\
public: void Set##_FuncName(_Type _v)\
{_Value = _v;}

#define PROPERTYGET_FUNC(Type, FuncName, Value)\
public : Type Get##FuncName()\
{return Value;}

#define WINMGR WindowManager::Instance()
#define GAMEMGR GameManager::Instance()
#define FPSMGR FrameCheckManager::Instance()
#define IMAGEMGR ImageManager::Instance()

#define GETKEY(ARROW) ((GetAsyncKeyState(ARROW) & 0x8000) == 0x8000)
#define GETKEYDOWN(key, value, func)\
if((GetAsyncKeyState(key) & 0x8000) == 0x8000 &&\
value == false)\
{func(); value = true;}\
if(value)\
{\
	if((GetAsyncKeyState(key) & 0x8001) == 0x8000)\
	{value = false;}\
}

#define GETKEYUP(key, value, func)\
if((GetAsyncKeyState(key) & 0x8000) == 0x8000 &&\
value == false)\
{ value = true;}\
if(value)\
{\
	if((GetAsyncKeyState(key) & 0x8001) == 0x8000)\
	{func();value = false;}\
}

enum class IMAGEBIT
{
	OBJ_BACK = 0,
	OBJ_MAP,
	OBJ_OBJECT,
	OBJ_WALL,
	OBJ_BOX,
	OBJ_BOMB,
	ACTOR_PLAYER,
	ACTOR_ENEMY,
	IMGBIT_MAX
};


#include "Singleton.cpp"
#include "Image.h"
#include "BaseTransform.h"
#include "BaseImageObject.h"
#include "ImageManager.h"
#include "Time.h"
#include "FrameCheckManager.h"
#include "Map.h"
#include "Object.h"
#include "Wall.h"
#include "Box.h"
#include "Bomb.h"
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Explosion.h"
#include "WindowManager.h"
#include "GameManager.h"



static const int ScreenSizeX = 1600;
static const int ScreenSizeY = 900;


