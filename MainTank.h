#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
	MainTank();
	~MainTank();
	void Display(char play);

private:
	void Draw();
	void Clean();
	void MyNumber(Dir dir);
	void TankAi();
	int m_otherDot;
};

#endif __MAIN_TANK__