#pragma once
#include "UsableItem.h"
class Consumable :
	public UsableItem
{
protected:
	void OnUsed() override;
	void OnAdded() override;
	void OnRemoved() override;
};

