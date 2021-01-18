#pragma once
class Pole
{
private:
	unsigned aPocet = 0;
	int* aPole = nullptr;
public:
	Pole(unsigned pocet = 0) : aPocet(pocet), aPole(aPocet != 0 ? new int[aPocet] : nullptr) {}
};

