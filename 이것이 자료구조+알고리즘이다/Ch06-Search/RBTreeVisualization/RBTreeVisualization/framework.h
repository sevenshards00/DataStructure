/*
* 이것이 자료구조+알고리즘이다 - 탐색(Search)
* 파일명: framework.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-25
* 이전 버전 작성 일자: 
* 버전 내용: 레드 블랙 트리 시각화 구현 (C++, Template)
* 이전 버전 내용: 
*/

// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <windowsx.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include <iostream>

#include "ITree.h"
#include "CBSTree.h"
#include "CRBTree.h"
#include "CAVLTree.h"