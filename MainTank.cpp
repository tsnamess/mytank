#include "MainTank.h"
#include "Graphic.h"

void MainTank::Move()
{
	int* numberP = MyNumber(m_theDir);
	clearrectangle(numberP[0], numberP[1], numberP[2], numberP[3]);
	clearrectangle(numberP[4], numberP[5], numberP[6], numberP[7]);
	clearrectangle(numberP[8], numberP[9], numberP[10], numberP[11]);
	clearrectangle(numberP[12], numberP[13], numberP[14], numberP[15]);
	delete[] numberP;
	if (m_dir == UP)
		m_y -= m_step;
	if (m_dir == DOWN)
		m_y += m_step;
	if (m_dir == LEFT)
		m_x -= m_step;
	if (m_dir == RIGHT)
		m_x += m_step;
	m_theDir = m_dir;
	numberP = MyNumber(m_dir);
	setfillcolor(m_color);
	fillrectangle(numberP[0], numberP[1], numberP[2], numberP[3]);
	fillrectangle(numberP[4], numberP[5], numberP[6], numberP[7]);
	fillrectangle(numberP[8], numberP[9], numberP[10], numberP[11]);
	fillrectangle(numberP[12], numberP[13], numberP[14], numberP[15]);
	delete[] numberP;
}

void MainTank::Display()
{
	int* numberP = MyNumber(m_dir);
	setfillcolor(m_color);
	fillrectangle(numberP[0], numberP[1], numberP[2], numberP[3]);
	fillrectangle(numberP[4], numberP[5], numberP[6], numberP[7]);
	fillrectangle(numberP[8], numberP[9], numberP[10], numberP[11]);
	fillrectangle(numberP[12], numberP[13], numberP[14], numberP[15]);
	delete[] numberP;
}

MainTank::MainTank()
{
	m_color = WHITE;
	m_dir = m_theDir = RIGHT;
	m_step = 2;
	m_x = Graphic::ShowX()/2;
	m_y = Graphic::ShowY() / 2;
	Display();
}

MainTank::~MainTank()
{
	int* numberP = MyNumber(m_theDir);
	clearrectangle(numberP[0], numberP[1], numberP[2], numberP[3]);
	clearrectangle(numberP[4], numberP[5], numberP[6], numberP[7]);
	clearrectangle(numberP[8], numberP[9], numberP[10], numberP[11]);
	clearrectangle(numberP[12], numberP[13], numberP[14], numberP[15]);
	delete[] numberP;
}

void MainTank::SetDir(Dir dir)
{
	m_dir = dir;
}

int * MainTank::MyNumber(Dir dir)
{
	
	int* numberP = new int[16];
	numberP[4] = m_x - 10;
	numberP[5] = m_y - 10;
	numberP[6] = m_x + 10;
	numberP[7] = m_y + 10;
	if (dir == UP || dir == DOWN)
	{
		numberP[0] = m_x - 20;	numberP[1] = m_y - 14;
		numberP[2] = m_x - 10;	numberP[3] = m_y + 14;

		numberP[8] = m_x + 10;	numberP[9] = m_y - 14;
		numberP[10] = m_x + 20;		numberP[11] = m_y + 14;
		if (dir == UP)
		{
			numberP[12] = m_x - 2;	numberP[13] = m_y - 30;
			numberP[14] = m_x + 2;	numberP[15] = m_y - 10;
		}
		if (dir == DOWN)
		{
			numberP[12] = m_x - 2;	numberP[13] = m_y + 10;
			numberP[14] = m_x + 2;	numberP[15] = m_y + 30;
		}
	}
	if (dir == LEFT || dir == RIGHT)
	{
		numberP[0] = m_x - 14;	numberP[1] = m_y - 20;
		numberP[2] = m_x + 14;	numberP[3] = m_y - 10;

		numberP[8] = m_x - 14;	numberP[9] = m_y + 10;
		numberP[10] = m_x + 14;		numberP[11] = m_y + 20;
		if (dir == RIGHT)
		{
			numberP[12] = m_x + 10;	numberP[13] = m_y + 2;
			numberP[14] = m_x + 30;	numberP[15] = m_y - 2;
		}
		if (dir == LEFT)
		{
			numberP[12] = m_x - 30;	numberP[13] = m_y - 2;
			numberP[14] = m_x - 10;	numberP[15] = m_y + 2;
		}
	}
	return numberP;
}
