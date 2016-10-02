#pragma once
#pragma comment(lib, "dsound.lib")

#include "Header.h"

#if DEBUG
const bool WINDOWED = true; 
#else if RELEASE
const bool WINDOWED = false;
#endif

#ifdef _DEBUG 
#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
#endif 
#endif  // _DEBUG

const int	WINDOW_WIDTH = 1280;
const int	WINDOW_HEIGHT = 720;

inline	bool	InCollision(const RECT& lhs, const RECT& rhs)
{
	if (lhs.left <= rhs.right && lhs.right >= rhs.left &&
		lhs.top <= rhs.bottom && lhs.bottom >= rhs.top)
		return true;

	return false;
}