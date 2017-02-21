#ifndef __OTHER_TANK__
#define __OTHER_TANK__

#include "Tank.h"
#include "TheHand.h"
#include "MainTank.h"

class OtherTank : public Tank
{
public:
	static OtherTank* OtherTankP;
	OtherTank();
	~OtherTank();
	int GetX();
	int GetY();
	void SetNext(OtherTank* next);
	OtherTank* GetNext();
	void DisPlay();

protected:
	bool Legal(int x, int y);
	void Draw();
	void Clean();
	void TankAi();
	void MyNumber(Dir dir);
	int m_dot;
	OtherTank* m_next;
};

#endif __OTHER_TANK__