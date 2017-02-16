#include <stdio.h>
#include <graphics.h>
#include "Graphic.h"

Graphic* Graphic::onlyOneP = NULL;

Graphic* Graphic::Start(int x, int y)
{
	if (onlyOneP == NULL)
	{
		onlyOneP = new Graphic(x, y);
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
	initgraph(m_x, m_y);
	setbkcolor(m_color);
	cleardevice();
}

Graphic::~Graphic()
{
	closegraph();
	onlyOneP = NULL;
}
