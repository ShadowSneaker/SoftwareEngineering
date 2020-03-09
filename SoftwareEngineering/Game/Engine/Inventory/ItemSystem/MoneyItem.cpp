#include "MoneyItem.h"

MoneyItem::MoneyItem()
{
	this->SetValue(1);
	this->SetWeight(1);
	SetIsStackable(true);
	SetIsQuestItem(false);
}

void MoneyItem::OnAdded()
{
}

void MoneyItem::OnRemoved()
{
}
