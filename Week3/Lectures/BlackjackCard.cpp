#include "BlackjackCard.h"

int BlackjackCard::Value()
{
	int val = 0;
	if (face_ == "K" || face_ == "Q" || face_ == "J")
		val = 10;
	else
		val = Card::Value();

	return val;
}