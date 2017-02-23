#ifndef __MY_DOT__
#define __MY_DOT__

#include "Tank.h"
#include <graphics.h>

class MyDot
{
public:
	virtual ~MyDot() {}
	virtual void Display() = 0;

protected:
	int m_x;
	int m_y;
	int m_r;
	int m_step;
	Dir m_dir;
	COLORREF m_color;
	virtual bool Judge() = 0;
};

#endif __MY_DOT__