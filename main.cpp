#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <graphics.h>
#include "Graphic.h"
#include "MainTank.h"
#include "Tank.h"


int main()
{
	Graphic* p = Graphic::Start();
	getchar();
	/*MainTank* hp = new MainTank;
	while (1)
	{
		char q;
		Sleep(20);
		if (kbhit())
		{
			q = getch();
			if (q == 'a')
				hp->SetDir(LEFT);
			if (q == 'd')
				hp->SetDir(RIGHT);
			if (q == 'w')
				hp->SetDir(UP);
			if (q == 's')
				hp->SetDir(DOWN);
		}
		hp->Move();
	}
	delete hp;*/
	delete p;
	return 0;
}