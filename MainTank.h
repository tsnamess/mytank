#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "OtherTank.h"
#include "Tank.h"

class MainTank : public Tank
{
public:
	static MainTank* MainTankP;
	MainTank();
	~MainTank();
	void Display(char play);
	int GetX();
	int GetY();
	void SetLife(int life);

private:
	void Draw();
	void Clean();
	void MyNumber(Dir dir);
	void TankAi();
	int m_life;
	int m_otherDot;
};

#endif __MAIN_TANK__