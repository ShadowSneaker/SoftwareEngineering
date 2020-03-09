#pragma once
#include "UsableItem.h"
class Consumable :
	public UsableItem
{
public:
	Item* Clone() override { return new Consumable(*this); }
protected:
	void OnUsed() override;
	void OnAdded() override;
	void OnRemoved() override;
};

