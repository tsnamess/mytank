#ifndef __OTHER_EXPLOTE__
#define __OTHER_EXPLOTE__
#include "Explote.h"
#include "MyOtherDot.h"
#include "MainTank.h"
//#include "allhead.h"
class OtherExplote : public Explote
{
public:
	//void Add(MyOtherDot* mODP);
	void Add(MyOtherDot* mODP, MainTank* mTP = NULL);
	~OtherExplote();
	void DisPlay();
	static OtherExplote* Start();
private:
	class DuiLie
	{
	public:
		DuiLie* m_next;
		MyOtherDot* m_mODP;
		MainTank* m_mTP;
	};
	DuiLie* m_head;
	static OtherExplote* OtherExploteP;
	OtherExplote();
};
#endif __OTHER_EXPLOTE__
