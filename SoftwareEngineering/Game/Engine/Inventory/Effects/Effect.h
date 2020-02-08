#pragma once
class Effect
{
public:
	virtual void StartEffect(/*pass entity here*/) = 0;
	virtual void EndEffect(/*pass entity here*/) = 0;
};