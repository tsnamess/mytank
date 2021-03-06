#include "MainTank.h"
#include "OtherTank.h"
#include "MyMainDot.h"
#include <stdio.h>

MainTank* MainTank::MainTankP = NULL;

void MainTank::Draw()
{
	MyNumber(m_dir);
	setfillcolor(m_color);
	setlinecolor(GREEN);
	fillrectangle(m_numberP[0], m_numberP[1], m_numberP[2], m_numberP[3]);
	fillrectangle(m_numberP[4], m_numberP[5], m_numberP[6], m_numberP[7]);
	fillrectangle(m_numberP[8], m_numberP[9], m_numberP[10], m_numberP[11]);
	fillrectangle(m_numberP[12], m_numberP[13], m_numberP[14], m_numberP[15]);
	delete[] m_numberP;
	m_dir = STOP;
}

void MainTank::Clean()
{
	MyNumber(m_theDir);
	clearrectangle(m_numberP[0], m_numberP[1], m_numberP[2], m_numberP[3]);
	clearrectangle(m_numberP[4], m_numberP[5], m_numberP[6], m_numberP[7]);
	clearrectangle(m_numberP[8], m_numberP[9], m_numberP[10], m_numberP[11]);
	clearrectangle(m_numberP[12], m_numberP[13], m_numberP[14], m_numberP[15]);
	delete[] m_numberP;
}

MainTank::MainTank()
{
	m_color = WHITE;
	m_otherDot = 50;
	MainTankP = this;
	m_dir = m_theDir = RIGHT;
	m_step = 2;
	m_x = 450;
	m_y = 300;
	m_life = 3;
	Draw();
}

MainTank::~MainTank()
{
	MainTankP = NULL;
	Clean();
}

void MainTank::Display(char play)
{
	if (play == 'a')
		m_dir = LEFT;
	else if (play == 's')
		m_dir = DOWN;
	else if (play == 'd')
		m_dir = RIGHT;
	else if (play == 'w')
		m_dir = UP;
	else if (play == ' ')
	{
		if (m_otherDot == 0)
			return;
		--m_otherDot;
		TCHAR lszdn[10] = _T("     ");
		outtextxy(1000, 400, lszdn);
		_stprintf(lszdn, _T("%d"), m_otherDot);
		//TCHAR zdn[] = _T(lszdn);
		outtextxy(1000, 400, lszdn);
		new MyMainDot(m_x, m_y, m_theDir);
		//////////////make dot//////////////
	}
	else
		return;
	TankAi();
	if (m_dir == STOP)
		return;
	Clean();
	if (m_dir == m_theDir)
	{
		if (m_dir == UP)
			m_y -= m_step;
		if (m_dir == DOWN)
			m_y += m_step;
		if (m_dir == LEFT)
			m_x -= m_step;
		if (m_dir == RIGHT)
			m_x += m_step;
	}
	else
		m_theDir = m_dir;
	Draw();
}

int MainTank::GetX()
{
	return m_x;
}

int MainTank::GetY()
{
	return m_y;
}

void MainTank::SetX(int x)
{
	m_x = x;
}

void MainTank::SetY(int y)
{
	m_y = y;
}

void MainTank::SetLife()
{
	--m_life;
	clearrectangle(1000, 280, 1080, 320);
	int theNum = 990;
	for (int i = 0; i < m_life; ++i)
	{
		setfillcolor(RED);
		solidrectangle(theNum + 10, 280, theNum + 30, 320);
		theNum += 30;
	}
}

void MainTank::AddGold()
{
}

void MainTank::MyNumber(Dir dir)
{
	
	m_numberP = new int[16];
	
	if (dir == UP || dir == DOWN)
	{
		m_numberP[0] = m_x - 20;	m_numberP[1] = m_y - 20;
		m_numberP[2] = m_x - 10;	m_numberP[3] = m_y + 20;

		m_numberP[4] = m_x - 8;		m_numberP[5] = m_y - 10;
		m_numberP[6] = m_x + 8;		m_numberP[7] = m_y + 10;

		m_numberP[8] = m_x + 10;	m_numberP[9] = m_y - 20;
		m_numberP[10] = m_x + 20;	m_numberP[11] = m_y + 20;
		if (dir == UP)
		{
			m_numberP[12] = m_x - 2;	m_numberP[13] = m_y - 35;
			m_numberP[14] = m_x + 2;	m_numberP[15] = m_y - 10;
		}
		if (dir == DOWN)
		{
			m_numberP[12] = m_x - 2;	m_numberP[13] = m_y + 10;
			m_numberP[14] = m_x + 2;	m_numberP[15] = m_y + 35;
		}
	}
	if (dir == LEFT || dir == RIGHT)
	{
		m_numberP[0] = m_x - 20;	m_numberP[1] = m_y - 20;
		m_numberP[2] = m_x + 20;	m_numberP[3] = m_y - 10;

		m_numberP[4] = m_x - 10;		m_numberP[5] = m_y - 8;
		m_numberP[6] = m_x + 10;		m_numberP[7] = m_y + 8;
		
		m_numberP[8] = m_x - 20;	m_numberP[9] = m_y + 10;
		m_numberP[10] = m_x + 20;	m_numberP[11] = m_y + 20;
		if (dir == RIGHT)
		{
			m_numberP[12] = m_x + 10;	m_numberP[13] = m_y + 2;
			m_numberP[14] = m_x + 35;	m_numberP[15] = m_y - 2;
		}
		if (dir == LEFT)
		{
			m_numberP[12] = m_x - 35;	m_numberP[13] = m_y - 2;
			m_numberP[14] = m_x - 10;	m_numberP[15] = m_y + 2;
		}
	}
}

void MainTank::TankAi()
{
	int mx = m_x;
	int my = m_y;
	if (m_dir == m_theDir)
	{
		if (m_dir == UP)
			my -= m_step;
		if (m_dir == DOWN)
			my += m_step;
		if (m_dir == LEFT)
			mx -= m_step;
		if (m_dir == RIGHT)
			mx += m_step;
	}
	if (mx < 20 || my < 20 || mx > 880 || my > 580)
	{
		m_dir = STOP;
		return;
	}

	int tx, ty;
	OtherTank* oTP = OtherTank::OtherTankP->GetNext();
	while (oTP)
	{
		tx = oTP->GetX() - mx;
		ty = oTP->GetY() - my;
		if (tx < 0)
			tx = -tx;
		if (ty < 0)
			ty = -ty;
		if (tx <= 40 && ty <= 40)
		{
			m_dir = STOP;
			return;
		}
		oTP = oTP->GetNext();
	}
}
