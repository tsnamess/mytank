#include <stdio.h>
#include <graphics.h>
#include "Graphic.h"

Graphic* Graphic::onlyOneP = NULL;

Graphic* Graphic::Start()
{
	if (onlyOneP == NULL)
	{
		onlyOneP = new Graphic(1200, 600);
	}
	return onlyOneP;
}

int Graphic::ShowX()
{
	if (onlyOneP)
		return onlyOneP->m_x;
	return 0;
}

int Graphic::ShowY()
{
	if (onlyOneP)
		return onlyOneP->m_y;
	return 0;
}

Graphic::Graphic(int x, int y) : m_x(x), m_y(y)
{
	m_color = DARKGRAY;
	Beggin();
}

void Graphic::Beggin()
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

Graphic::~Graphic()
{
	closegraph();
	onlyOneP = NULL;
}
