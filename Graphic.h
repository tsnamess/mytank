#ifndef __GRAPHIC__
#define __GRSPHIC__

#include <graphics.h>
class Graphic
{
public:
	static Graphic* Start(int x, int y);
	static int ShowX();
	static int ShowY();
	~Graphic();

private:
	int m_x;
	int m_y;
	COLORREF m_color;
	static Graphic* onlyOneP;
	Graphic(int x, int y);
	
};

#endif __GRSPHIC__