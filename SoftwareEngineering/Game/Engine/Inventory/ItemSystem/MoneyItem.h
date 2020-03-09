#pragma once
#include "Item.h"


class MoneyItem : public Item
{
public:
	MoneyItem();
	Item* Clone() override { return new MoneyItem(*this); }

protected:
	void OnAdded() override;
	void OnRemoved() override;
};

