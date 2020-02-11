#include "Consumable.h"
#include "..\Inventory.h"

void Consumable::OnUsed()
{
	GetOwner()->RemoveItem(this);
}
