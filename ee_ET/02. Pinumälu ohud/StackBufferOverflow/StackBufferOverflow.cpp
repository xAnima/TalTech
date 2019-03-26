#include "pch.h"
#include <iostream>

// Pinumälu puhvri ülekurnamine(stack buffer overflow) tähendab seda, 
// et muutuja piiratud puhvrist kirjutatakse andmeid üle. Seega tekib puhvri overflow.

int main(int argc, char *argv[])
{
	char szBuffer[5];

	// Tavalise programmeerimise korral, tekib siin stack buffer overflow.
	// sprintf(szBuffer, "%s", argv[0]);

	// Windows ei salli kasutamast ohtlike funktsioone, seega on loodud turvaline variant antud funktsioonidest.
	sprintf_s(szBuffer, "%s", argv[0]); // _s tähendab, et funktsioon on turvaline ehk "safe"

	return 0;
}