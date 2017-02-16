#ifndef __TANK__
#define __TANK__

#include <graphics.h>

enum Dir { UP, DOWN, LEFT, RIGHT };

class Tank
{
public:
	virtual ~Tank() {}
	virtual void Move() = 0;
	virtual void Display() = 0;
protected:
	Dir m_dir;
	int m_x;
	int m_y;
	int m_step;
	COLORREF m_color;
};

#endif __TANK__