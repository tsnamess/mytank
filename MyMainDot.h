#ifndef __MY_MAIN_DOT__
#define __MY_MAIN_DOT__

#include "MyDot.h"
#include "OtherTank.h"
class MyMainDot : public MyDot
{
public:
	MyMainDot(int x, int y, Dir dir);
	~MyMainDot();
	void Display();
	MyMainDot* m_next;

protected:

	bool Judge();
};


#endif __MY_MAIN_DOT__