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
	~UsableItem();
	
	void Use();
	Item* Clone() override { return new UsableItem(*this); }

protected:
	virtual void OnUsed();
};

