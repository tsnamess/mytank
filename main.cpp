#include "MainTank.h"
#include "Tank.h"
#include "OtherTank.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <graphics.h>

int main()
{
	TheHand* p = TheHand::Start();
	MainTank* pp = new MainTank;
	MainTank::MainTankP = pp;
	OtherTank* u = new OtherTank;
	while (1)
	{
		u->DisPlay();
		Sleep(2000);
		if (kbhit())
		{
			pp->Display(getch());
		}
	}
	delete pp;
	delete p;
	return 0;
}

