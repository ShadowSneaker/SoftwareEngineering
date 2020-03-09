#include "Equippable.h"

void Equippable::OnUsed()
{
	m_equipped = !m_equipped;
}

void Equippable::OnAdded()
{
}

void Equippable::OnRemoved()
{
}
