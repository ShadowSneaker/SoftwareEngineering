#include "Consumable.h"

void Consumable::OnUsed()
{
	GetOwner()->RemoveItem(this);
}
