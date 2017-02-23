#ifndef __MY_OTHER_DOT__
#define __MY_OTHER_DOT__

#include "MyDot.h"
#include "MainTank.h"
#include <graphics.h>

class MyOtherDot : public MyDot
{
public:
	~MyOtherDot();
	MyOtherDot(int x, int y, Dir dir);
	void Display();
	MyOtherDot* m_next;

protected:

	bool Judge() = 0;
};





#endif __MY_OTHER_DOT__