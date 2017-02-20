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
	MainTank* pp = new MainTank;
	
	while (1)
	{
		Sleep(10);
		if (kbhit())
		{
			pp->Display(getch());
		}
	}
	delete pp;
	delete p;
	return 0;
}