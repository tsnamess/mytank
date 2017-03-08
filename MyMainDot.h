#ifndef __MY_MAIN_DOT__
#define __MY_MAIN_DOT__

#include "MyDot.h"
class MyMainDot : public MyDot
{
public:
	static MyMainDot* MyMainDotP;
	MyMainDot(int x, int y, Dir dir);
	~MyMainDot();
	void Display();
	MyMainDot* m_next;
	MyMainDot* m_up;

private:

	bool Judge();
};


#endif __MY_MAIN_DOT__