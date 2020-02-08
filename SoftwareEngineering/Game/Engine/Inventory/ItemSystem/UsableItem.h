#pragma once
#include "Item.h"
#include "../Effects/Effect.h"
#include <vector>
class UsableItem :
	public Item
{
private:
	std::vector<Effect*> m_effects;

public:
	void Use();

protected:
	virtual void OnUsed() = 0;
};

