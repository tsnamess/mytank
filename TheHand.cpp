#include "TheHand.h"
#include <stdio.h>

TheHand* TheHand::onlyOneP = NULL;


TheHand* TheHand::Start()
{
	if (onlyOneP == NULL)
	{
		onlyOneP = new TheHand(1200, 600);
	}
	return onlyOneP;
}

int TheHand::ShowX()
{
	if (onlyOneP)
		return onlyOneP->m_x;
	return 0;
}

int TheHand::ShowY()
{
	if (onlyOneP)
		return onlyOneP->m_y;
	return 0;
}

void TheHand::End()
{
}

TheHand::TheHand(int x, int y) : m_x(x), m_y(y)
{
	m_color = DARKGRAY;
	Beggin();
}

void TheHand::Beggin()
{
	initgraph(m_x, m_y);
	setbkcolor(m_color);
	cleardevice();
	setlinecolor(GREEN);
	line(900, 0, 900, 600);
	TCHAR dft[] = _T("敌方坦克:");
	TCHAR zd[] = _T("子弹:");
	TCHAR life[] = _T("生命:");
	settextcolor(GREEN);
	outtextxy(950, 100, dft);
	outtextxy(950, 300, life);
	outtextxy(950, 400, zd);
}

TheHand::~TheHand()
{
	closegraph();
	onlyOneP = NULL;
}
