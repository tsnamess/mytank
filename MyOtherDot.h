#ifndef __MY_OTHER_DOT__
#define __MY_OTHER_DOT__

#include "MyDot.h"
#include "MainTank.h"
//#include "OtherTank.h"
#include "OtherExplote.h"
//#include <graphics.h>

class MyOtherDot : public MyDot
{
public:
	static MyOtherDot* MyOtherDotP;
	~MyOtherDot();
	MyOtherDot(int x, int y, Dir dir);
	void Display();
	MyOtherDot* m_next;
	MyOtherDot* m_up;

private:
	bool Judge();
};

#endif __MY_OTHER_DOT__