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
	OtherTank* uu = new OtherTank;
	u->SetNext(uu);
	while (1)
	{
		uu->DisPlay();
		Sleep(20);
		if (kbhit())
		{
			pp->Display(getch());
		}
	}
	delete pp;
	delete p;
	return 0;
}

