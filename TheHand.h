#ifndef __THEHAND__
#define __THEHAND__

#include <graphics.h>

class TheHand
{
public:
	static TheHand* Start();
	static int ShowX();
	static int ShowY();
	~TheHand();

private:
	int m_x;
	int m_y;
	COLORREF m_color;
	static TheHand* onlyOneP;
	TheHand(int x, int y);
	void Beggin();
	
};

#endif __THEHAND__