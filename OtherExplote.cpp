#include "OtherExplote.h"

OtherExplote* OtherExplote::OtherExploteP = NULL;

/*void OtherExplote::Add(MyOtherDot * mODP)
{
	DuiLie* lsh = new DuiLie;
	lsh->m_mODP = mODP;
	lsh->m_mTP = NULL;
	lsh->m_next = m_head;
	m_head = lsh;
}*/

void OtherExplote::Add(MyOtherDot * mODP, MainTank * mTP)
{
	DuiLie* lsh = new DuiLie;
	lsh->m_mODP = mODP;
	lsh->m_mTP = mTP;
	lsh->m_next = m_head;
	m_head = lsh;
}

OtherExplote::~OtherExplote()
{
	DuiLie* lsh = m_head;
	while (lsh)
	{
		delete lsh;
		lsh = lsh->m_next;
	}
}

void OtherExplote::DisPlay()
{
	DuiLie* lsh = m_head, *olsh;
	while (lsh)
	{
		delete lsh->m_mODP;
		if (lsh->m_mTP)
		{
			lsh->m_mTP->Clean();
			lsh->m_mTP->SetX(450);
			lsh->m_mTP->SetY(300);
		}

		olsh = lsh;
		lsh = lsh->m_next;
		delete olsh;
	}
	m_head = NULL;
}

OtherExplote * OtherExplote::Start()
{
	if (OtherExploteP)
	{
		return OtherExploteP;
	}
	OtherExploteP = new OtherExplote;
	return OtherExploteP;
}

OtherExplote::OtherExplote()
{
	m_head = NULL;
}
