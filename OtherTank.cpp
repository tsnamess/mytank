#include "OtherTank.h"

void OtherTank::SetNext(OtherTank * next)
{
	m_next = next;
}

OtherTank * OtherTank::GetNext()
{
	return m_next;
}
