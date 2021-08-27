// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <ctime>

#include "debug.h"
#include "BMP.h"			//이미지를 불러오고 그리는 객체
#include "graphic.h"
#include "deltaTime.h"
#include "Random.h"
#include "Input.h"
#include "Sprite.h"			//단일 이미지 로드하는 확장
#include "GameObject.h"
#include "ObjectManager.h"	//오브젝트들을 한번에 돌리게 하는 매니저
#include "GameBG.h"			
#include "Player.h"			
#include "PlayerLaser.h"	//이미지가 단일일경우 (레이저,,,)
#include "Animation.h"		//이미지가 두개 이상인 객체는 애니메이션을 포함//
#include "Enemy.h"
#include "EnemyBullet.h"

#define WIDTH 480
#define HEIGHT 800

