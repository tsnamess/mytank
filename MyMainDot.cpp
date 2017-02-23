#include "MyMainDot.h"

MyMainDot::MyMainDot(int x, int y, Dir dir)
{
	m_color = WHITE;
	m_r = 7;
	m_step = 1;
	m_dir = dir;
	m_next = NULL;
	if (dir == UP)
		y -= 38;
	if (dir == DOWN)
		y += 38;
	if (dir == LEFT)
		x -= 38;
	if (dir == RIGHT)
		x += 38;
	m_x = x;
	m_y = y;
	setfillcolor(m_color);
	solidcircle(m_x, m_y, m_r);
	if (Judge())
	{
		//////////////////exspotend////////////////////
	}
}

MyMainDot::~MyMainDot()
{
	clearcircle(m_x, m_y, m_r);
}

void MyMainDot::Display()
{
	clearcircle(m_x, m_y, m_r);
	setfillcolor(m_color);
	solidcircle(m_x, m_y, m_r);
	Judge();
}

bool MyMainDot::Judge()
{
	if (m_x <= 3 || m_y <= 3 || m_x >= 897 || m_y >= 597)
	{
		//////////////expend///////////
		return false;
	}
	OtherTank* oTP = OtherTank::OtherTankP;
	while (oTP->GetNext())
	{
		int theX = oTP->GetNext()->GetX() - m_x;
		int theY = oTP->GetNext()->GetY() - m_y;
		if (theX < 0)
			theX = -theX;
		if (theY < 0)
			theY = -theY;
		if (theX < 38 && theY < 38)
		{
			//////////exspent//////////////
			return false;
		}
		oTP = oTP->GetNext();
	}
	return true;
}
