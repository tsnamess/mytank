#include "MainExplote.h"

MainExplote* MainExplote::MainExploteP = NULL;

/*void MainExplote::Add(MyMainDot * mMDP)
{
	DuiLie* lsh = new DuiLie;
	lsh->m_mMDP = mMDP;
	lsh->m_oTP = NULL;
	lsh->m_next = m_head;
	m_head = lsh;
}*/

void MainExplote::Add(MyMainDot * mMDP, OtherTank * oTP)
{
	DuiLie* lsh = new DuiLie;
	lsh->m_mMDP = mMDP;
	lsh->m_oTP = oTP;
	lsh->m_next = m_head;
	m_head = lsh;
}

MainExplote::~MainExplote()
{
	DuiLie* lsh = m_head;
	while (lsh)
	{
		delete lsh;
		lsh = lsh->m_next;
	}
}

void MainExplote::DisPlay()
{
	DuiLie* lsh = m_head, *olsh;
	while (lsh)
	{
		delete lsh->m_mMDP;
		if (lsh->m_oTP)
			delete lsh->m_oTP;
		olsh = lsh;
		lsh = lsh->m_next;
		delete olsh;
	}
}

MainExplote * MainExplote::Start()
{
	if (MainExploteP)
	{
		return MainExploteP;
	}
	MainExploteP = new MainExplote;
	return MainExploteP;
}

MainExplote::MainExplote()
{
}
