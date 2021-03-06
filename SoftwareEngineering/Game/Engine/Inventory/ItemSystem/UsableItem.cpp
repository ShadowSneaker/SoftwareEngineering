#include "UsableItem.h"

UsableItem::~UsableItem()
{
	for (int i = 0; i < m_effects.size(); i++)
	{
		delete m_effects[i];
	}
	m_effects.clear();
}

void UsableItem::Use()
{
	for (int i = 0; i < m_effects.size(); i++)
	{
		if (m_effects[i]->GetIsActive())
			m_effects[i]->EndEffect();
		else
			m_effects[i]->StartEffect();
	}
	OnUsed();
}

void UsableItem::OnUsed()
{
}
