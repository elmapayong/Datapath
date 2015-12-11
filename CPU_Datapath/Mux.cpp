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

void Mux::setA(int A)
{
	a = A;
}

void Mux::setB(int B)
{
	b = B;
}


int Mux::getResult()
{
	return result;
}