#pragma once
#include "Item.h"


class MoneyItem : public Item
{
public:
	MoneyItem();
	void OnAdded() override;
	void OnRemoved() override;
};

