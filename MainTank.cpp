#include "MainTank.h"

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
	m_dot = false;
	m_dir = m_theDir = RIGHT;
	m_step = 2;
	m_x = 450;
	m_y = 300;
	Draw();
}

MainTank::~MainTank()
{
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
		////////////////////////////
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
	///////////////////////////////Î´Íê//////////////////////////////////////////
}
