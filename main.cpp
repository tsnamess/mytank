//#include "allhead.h"
#include "TheHand.h"
#include "MainTank.h"
#include "MyMainDot.h"
#include "MyOtherDot.h"
#include "OtherTank.h"
#include "OtherExplote.h"
#include "MainExplote.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
//#include <graphics.h>
void OtherTankDisplay();
void MyMainDotDisplay();
void MyOtherDotDisplay();
int main()
{

	TheHand* begin = TheHand::Start();
	MainExplote* mEPP = MainExplote::Start();
	OtherExplote* oEPP = OtherExplote::Start();
	new MainTank;
	int i;
	for (i = 10; i > 0; --i)
		new OtherTank;
	while (1)
	{
		//if (MyMainDot::MyMainDotP)
		oEPP->DisPlay();
		mEPP->DisPlay();
		MyOtherDotDisplay();
		OtherTankDisplay();
		MyMainDotDisplay();
		Sleep(20);
		if (kbhit())
		{
			MainTank::MainTankP->Display(getch());
		}
	}
		
#if 0
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
#endif
	getchar();
	delete begin;
	return 0;
}

void OtherTankDisplay()
{
	OtherTank* oTDP = OtherTank::OtherTankP;
	if (oTDP == 0)
		return;
	oTDP = oTDP->GetNext();
	while (oTDP)
	{
		oTDP->DisPlay();
		oTDP = oTDP->GetNext();

	}
}

void MyMainDotDisplay()
{
	MyMainDot* mMDDP = MyMainDot::MyMainDotP;
	if (mMDDP == 0)
		return;
	mMDDP = mMDDP->m_next;
	while (mMDDP)
	{
		mMDDP->Display();
		mMDDP = mMDDP->m_next;

	}
}

void MyOtherDotDisplay()
{
	MyOtherDot* mODDP = MyOtherDot::MyOtherDotP;
	if (mODDP == 0)
		return;
	mODDP = mODDP->m_next;
	while (mODDP)
	{
		mODDP->Display();
		mODDP = mODDP->m_next;

	}
}
