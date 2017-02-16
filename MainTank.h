#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
	void Move();
	void Display();
	MainTank();
	~MainTank();
	void SetDir(Dir dir);

private:
	Dir m_theDir;
	int* MyNumber(Dir dir);
};

#endif __MAIN_TANK__