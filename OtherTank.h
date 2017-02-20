#ifndef __OTHER_TANK__
#define __OTHER_TANK__
#include "Tank.h"

class OtherTank : public Tank
{
public:
	OtherTank();
	~OtherTank();
	void SetNext(OtherTank* next);
	OtherTank* GetNext();

protected:
	bool Legal(int x, int y);
	void Draw();
	void Clean();
	void TankAi();
	void MyNumber(Dir dir);
	int m_dot;
	OtherTank* m_next;
}

#endif __OTHER_TANK__