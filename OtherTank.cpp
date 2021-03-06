
#include "OtherTank.h"
#include "MainTank.h"
#include "MyOtherDot.h"
#include <time.h>
#include <stdlib.h>

OtherTank* OtherTank::OtherTankP = NULL;

OtherTank::OtherTank()
{
	srand(time(NULL));
	m_dot = 0;
	
	m_color = BLUE;
	m_theDir = m_dir = (Dir)(rand() % 4);
	m_numberP = NULL;
	m_step = 1;
	int js = 8;
	if (OtherTank::OtherTankP == NULL)
	{
		m_next = NULL;
		m_up = NULL;
		OtherTank::OtherTankP = this;
		new OtherTank();
		return;
	}
	else
	{
		while (js)
		{
			m_x = rand() % 880 + 20;
			m_y = rand() % 580 + 20;
			if (Legal(m_x, m_y))
				break;
			--js;
		}
		if (js == 0)
		{
			m_x = 20;
			m_y = 20;
		}
		Draw();
	}
	m_next = OtherTankP->GetNext();
	if (OtherTankP->GetNext())
		OtherTankP->GetNext()->SetUp(this);
	m_up = OtherTankP;
	OtherTankP->SetNext(this);
}

OtherTank::~OtherTank()
{
	Clean();
	m_up->SetNext(m_next);
	if (m_next)
		m_next->SetUp(m_up);
	m_next = NULL;
	m_up = NULL;
	m_numberP = NULL;
}

int OtherTank::GetX()
{
	return m_x;
}

int OtherTank::GetY()
{
	return m_y;
}

void OtherTank::SetNext(OtherTank * next)
{
	m_next = next;
}

OtherTank * OtherTank::GetNext()
{
	return m_next;
}

void OtherTank::SetUp(OtherTank * up)
{
	m_up = up;
}

OtherTank * OtherTank::GetUp()
{
	return m_up;
}

void OtherTank::DisPlay()
{
	if (m_dot == 120)
	{
		///////////////////make dot/////////////
		new MyOtherDot(m_x, m_y, m_theDir);
		m_dot = 0;
		return;
	}
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
	++m_dot;
}

bool OtherTank::Legal(int x, int y)
{
	if (m_x < 20 || m_y < 20 || m_x >= 880 || m_y >= 580)
		return false;
	int tx = MainTank::MainTankP->GetX() - x;
	int ty = MainTank::MainTankP->GetY() - y;
	if (tx < 0)
		tx = -tx;
	if (ty < 0)
		ty = -ty;
	if (tx <= 40 && ty <= 40)
		return false;

	OtherTank* oTP = OtherTank::OtherTankP->GetNext();
	while (oTP)
	{
		if (oTP == this)
		{
			oTP = oTP->GetNext();
			continue;
		}
		tx = oTP->GetX() - x;
		ty = oTP->GetY() - y;
		if (tx < 0)
			tx = -tx;
		if (ty < 0)
			ty = -ty;
		if (tx <= 40 && ty <= 40)
			return false;
		oTP = oTP->GetNext();
	}
	return true;
}

void OtherTank::Draw()
{
	MyNumber(m_dir);
	setfillcolor(m_color);
	solidrectangle(m_numberP[0], m_numberP[1], m_numberP[2], m_numberP[3]);
	solidrectangle(m_numberP[4], m_numberP[5], m_numberP[6], m_numberP[7]);
	solidrectangle(m_numberP[8], m_numberP[9], m_numberP[10], m_numberP[11]);
	solidrectangle(m_numberP[12], m_numberP[13], m_numberP[14], m_numberP[15]);
	solidrectangle(m_numberP[16], m_numberP[17], m_numberP[18], m_numberP[19]);
	solidrectangle(m_numberP[20], m_numberP[21], m_numberP[22], m_numberP[23]);

	delete[] m_numberP;
}

void OtherTank::Clean()
{
	MyNumber(m_theDir);
	clearrectangle(m_numberP[0], m_numberP[1], m_numberP[2], m_numberP[3]);
	clearrectangle(m_numberP[4], m_numberP[5], m_numberP[6], m_numberP[7]);
	clearrectangle(m_numberP[8], m_numberP[9], m_numberP[10], m_numberP[11]);
	clearrectangle(m_numberP[12], m_numberP[13], m_numberP[14], m_numberP[15]);
	clearrectangle(m_numberP[16], m_numberP[17], m_numberP[18], m_numberP[19]);
	clearrectangle(m_numberP[20], m_numberP[21], m_numberP[22], m_numberP[23]);
	delete[] m_numberP;
}

void OtherTank::TankAi()
{
	int mainX = MainTank::MainTankP->GetX();
	int mainY = MainTank::MainTankP->GetY();
	int findMin[5];
	findMin[0] = m_y - mainY;
	findMin[1] = mainY - m_y;
	findMin[2] = m_x - mainX;
	findMin[3] = mainX - m_x;
	findMin[4] = 2000;
	
	int js, jMin, jNum;
	int turnX[4] = { 0, 0, -m_step, m_step };
	int turnY[4] = { -m_step, m_step, 0, 0 };
	while (1)
	{
		jMin = 5000;
		for (js = 0; js < 5; ++js)
		{
			if (findMin[js] < jMin && findMin[js] >= 0)
			{
				jNum = js;
				jMin = findMin[js];
			}
			if (findMin[js] == 0)
			{
				int jjs, jjMin = 5000, jjNum;
				for (jjs = 0; jjs < 5; ++jjs)
				{
					if (findMin[jjs] < jjMin && findMin[jjs] > 0)
					{
						jjNum = jjs;
						jjMin = findMin[jjs];
					}
				}
				m_dir = (Dir)jjNum;
				if (m_dir == m_theDir)
				{
					////////////////make dot//////////////////
					if (m_dot > 80)
					{
						new MyOtherDot(m_x, m_y, m_theDir);
						m_dot = 0;
					}
					m_dir = STOP;
					++m_dot;
					return;
				}
				else
					return;
			}
		}
		if (jMin == 2000)
		{
			m_dir = STOP;
			return;
		}
		if ((Dir)jNum == m_theDir)
		{
			if (Legal(m_x + turnX[jNum], m_y + turnY[jNum]))
				return;
			else
				findMin[jNum] = 3000;
		}
		else
		{
			m_dir = (Dir)jNum;
			return;
		}
	}
}

void OtherTank::MyNumber(Dir dir)
{
	m_numberP = new int[24];

	m_numberP[0] = m_x - 20;	m_numberP[1] = m_y - 20;
	m_numberP[2] = m_x - 12;	m_numberP[3] = m_y - 12;

	m_numberP[4] = m_x + 12;	m_numberP[5] = m_y - 20;
	m_numberP[6] = m_x + 20;	m_numberP[7] = m_y - 12;

	m_numberP[8] = m_x - 20;	m_numberP[9] = m_y + 12;
	m_numberP[10] = m_x - 12;	m_numberP[11] = m_y + 20;

	m_numberP[12] = m_x + 12;	m_numberP[13] = m_y + 12;
	m_numberP[14] = m_x + 20;	m_numberP[15] = m_y + 20;

	m_numberP[20] = m_x - 10;	m_numberP[21] = m_y - 10;
	m_numberP[22] = m_x + 10;	m_numberP[23] = m_y + 10;
	switch (dir)
	{
	case UP:
		m_numberP[16] = m_x - 2;	m_numberP[17] = m_y - 30;
		m_numberP[18] = m_x + 2;	m_numberP[19] = m_y - 10;
		break;
	case DOWN:
		m_numberP[16] = m_x - 2;	m_numberP[17] = m_y + 10;
		m_numberP[18] = m_x + 2;	m_numberP[19] = m_y + 30;
		break;
	case RIGHT:
		m_numberP[16] = m_x + 10;	m_numberP[17] = m_y + 2;
		m_numberP[18] = m_x + 30;	m_numberP[19] = m_y - 2;
		break;
	case LEFT:
		m_numberP[16] = m_x - 30;	m_numberP[17] = m_y - 2;
		m_numberP[18] = m_x - 10;	m_numberP[19] = m_y + 2;
		break;
	}
}