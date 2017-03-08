#include "MyOtherDot.h"
#include "OtherTank.h"
#include "MainTank.h"
#include "OtherExplote.h"

MyOtherDot* MyOtherDot::MyOtherDotP = NULL;

MyOtherDot::MyOtherDot(int x, int y, Dir dir)
{
	m_color = YELLOW;
	m_r = 7;
	m_step = 1;
	if (MyOtherDotP)
	{
		m_dir = dir;
		m_next = MyOtherDotP->m_next;
		if (MyOtherDotP->m_next)
			MyOtherDotP->m_next->m_up = this;
		m_up = MyOtherDotP;
		MyOtherDotP->m_next = m_next;
	}
	else
	{
		MyOtherDotP = this;
		m_next = NULL;
		m_up = NULL;
		new MyOtherDot(x, y, dir);
		return;
	}
	if (dir == UP)
		y -= 39;
	if (dir == DOWN)
		y += 39;
	if (dir == LEFT)
		x -= 39;
	if (dir == RIGHT)
		x += 39;
	m_x = x;
	m_y = y;
	setfillcolor(m_color);
	solidcircle(m_x, m_y, m_r);
	Judge();
}

MyOtherDot::~MyOtherDot()
{
	m_up->m_next = m_next;
	if (m_next)
		m_next->m_up = m_up;
	clearcircle(m_x, m_y, m_r);
}

void MyOtherDot::Display()
{
	clearcircle(m_x, m_y, m_r);
	setfillcolor(m_color);
	if (m_dir == UP)
		m_y -= m_step;
	else if (m_dir == DOWN)
		m_y += m_step;
	else if (m_dir == LEFT)
		m_x -= m_step;
	else if (m_dir == RIGHT)
		m_x += m_step;
	solidcircle(m_x, m_y, m_r);
	Judge();
}

bool MyOtherDot::Judge()
{
	if (m_x <= 3 || m_y <= 3 || m_x >= 897 || m_y >= 597)
	{
		//////////////expend///////////
		OtherExplote* oEP = OtherExplote::Start();
		oEP->Add(this);
		return false;
	}
	MainTank* mTP = MainTank::MainTankP;
	
	int theX = mTP->GetX() - m_x;
	int theY = mTP->GetY() - m_y;
	if (theX < 0)
		theX = -theX;
	if (theY < 0)
		theY = -theY;
	if (theX < 38 && theY < 38)
	{
		//////////exspent//////////////
		OtherExplote* oEP = OtherExplote::Start();
		oEP->Add(this, mTP);
		mTP->SetLife();
		return false;
	}
	return true;
}