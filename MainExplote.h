#ifndef __MAIN_EXPLOTE__
#define __MAIN_EXPLOTE__

#include "Explote.h"
//#include "MyMainDot.h"
#include "OtherTank.h"

class MainExplote : public Explote
{
public:
	void Add(MyMainDot* mMDP);
	void Add(MyMainDot* mMDP, OtherTank* oTP);
	~MainExplote();
	void DisPlay();
	static MainExplote* Start();
private:
	class DuiLie
	{
	public:
		DuiLie* m_next;
		MyMainDot* m_mMDP;
		OtherTank* m_oTP;
	};
	DuiLie* m_head;
	static MainExplote* MainExploteP;
	MainExplote();
};

#endif __MAIN_EXPLOTE__
