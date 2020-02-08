#pragma once
#include "UsableItem.h"
class Switchable :
	public UsableItem
{
private:
	bool m_active;
protected:
	void OnUsed() override;
};

