#include "MyOtherDot.h"


MyOtherDot::MyOtherDot(int x, int y, Dir dir)
{
	m_color = YELLOW;
	m_r = 7;
	m_step = 1;
	m_dir = dir;
	m_next = NULL;
	if (dir == UP)
		y -= 33;
	if (dir == DOWN)
		y += 33;
	if (dir == LEFT)
		x -= 33;
	if (dir == RIGHT)
		x += 33;
	m_x = x;
	m_y = y;
	setfillcolor(m_color);
	solidcircle(m_x, m_y, m_r);
	if (Judge())
	{
		//////////////////exspotend////////////////////
	}
}

MyOtherDot::~MyOtherDot()
{
	clearcircle(m_x, m_y, m_r);
}

void MyOtherDot::Display()
{
	clearcircle(m_x, m_y, m_r);
	setfillcolor(m_color);
	solidcircle(m_x, m_y, m_r);
	Judge();
}

bool MyOtherDot::Judge()
{
	if (m_x <= 3 || m_y <= 3 || m_x >= 897 || m_y >= 597)
	{
		//////////////expend///////////
		return false;
	}
	MainTank* oMP = MainTank::MainTankP;
	
	int theX = oMP->GetX() - m_x;
	int theY = oMP->GetY() - m_y;
	if (theX < 0)
		theX = -theX;
	if (theY < 0)
		theY = -theY;
	if (theX < 33 && theY < 33)
	{
		//////////exspent//////////////
		return false;
	}
	return true;
}