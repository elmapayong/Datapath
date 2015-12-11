#include "Mux.h"

Mux::Mux()
{
	a, b, result = 0;
	chooseA = true;
}


void Mux::setChoiceA(bool isA)
{
	chooseA = isA;

	if (chooseA)
		result = a;
	else
		result = b;
}

int Mux::getResult()
{
	return result;
}