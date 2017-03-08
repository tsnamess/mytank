#include "MyMainDot.h"
#include "MainTank.h"
#include "MainExplote.h"

MyMainDot* MyMainDot::MyMainDotP = NULL;

MyMainDot::MyMainDot(int x, int y, Dir dir)
{
	m_color = WHITE;
	m_r = 7;
	m_step = 1;
	m_dir = dir;
	if (MyMainDotP)
	{
		if (MyMainDotP->m_next)
			MyMainDotP->m_next->m_up = this;
		m_up = MyMainDotP;
		m_next = MyMainDotP->m_next;
		MyMainDotP->m_next = this;
	}
	else
	{
		m_next = NULL;
		m_up = NULL;
		MyMainDotP = this;
		new MyMainDot(x, y, dir);
		return;
	}
	if (dir == UP)
		y -= 39;
	else if (dir == DOWN)
		y += 39;
	else if (dir == LEFT)
		x -= 39;
	else if (dir == RIGHT)
		x += 39;
	m_x = x;
	m_y = y;
	setfillcolor(m_color);
	solidcircle(m_x, m_y, m_r);
	Judge();
}

MyMainDot::~MyMainDot()
{
	m_up->m_next = m_next;
	if (m_next)
		m_next->m_up = m_up;
	clearcircle(m_x, m_y, m_r);
}

void MyMainDot::Display()
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

bool MyMainDot::Judge()
{
	if (m_x <= 3 || m_y <= 3 || m_x >= 896 || m_y >= 596)
	{
		//////////////expend///////////
		MainExplote* mEP = MainExplote::Start();
		mEP->Add(this);
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
		if (theX < 23 && theY < 23)
		{
			//////////exspent//////////////
			MainExplote* mEP = MainExplote::Start();
			mEP->Add(this, oTP->GetNext());
			MainTank::MainTankP->AddGold();
			return false;
		}
		oTP = oTP->GetNext();
	}
	return true;
}
