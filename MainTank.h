#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
	MainTank();
	~MainTank();
	//void SetDir(Dir dir);
	void Display(Dir dir);

private:
	void Draw();
	void Clean();
	void MyNumber(Dir dir);
	void TankAi(Dir dir);
};

#endif __MAIN_TANK__