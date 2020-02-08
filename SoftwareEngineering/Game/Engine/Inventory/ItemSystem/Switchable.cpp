#include "Switchable.h"

void Switchable::OnUsed()
{
	m_active = !m_active;
}
