#ifndef __OTHER_EXPLOTE__
#define __OTHER_EXPLOTE__
//#include "OtherTank.h"
//#include "OtherTank.h"
#include "MainTank.h"
#include "Explote.h"
//#include "MyOtherDot.h"
class OtherExplote : public Explote
{
public:
	void Add(MyOtherDot* mODP);
	void Add(MyOtherDot* mODP, MainTank* mTP);
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
