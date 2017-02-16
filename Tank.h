#ifndef __TANK__
#define __TANK__

#include <graphics.h>

enum Dir { UP, DOWN, LEFT, RIGHT, STOP };

class Tank
{
public:
	virtual ~Tank() {}
	
protected:
	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void TankAi(Dir dir) = 0;
	virtual void MyNumber(Dir dir) = 0;
	Dir m_dir;
	Dir m_theDir;
	int m_x;
	int m_y;
	int m_step;
	int* m_numberP;
	COLORREF m_color;
};

#endif __TANK__