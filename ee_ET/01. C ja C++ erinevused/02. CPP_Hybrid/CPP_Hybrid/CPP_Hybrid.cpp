#include "pch.h"
#include <iostream>

/*
* C põhineb protseduurilisel paradigmal. (Rõhutab programmi jaotamist alamprogrammideks)
* C++ põhineb nii protseduurilisel, kui ka objektorienteeritud paradigmal. (Objektide ja andmeväljade kasutamine on OOP põhi).
*/

// INTRO>
// C++ objekt on klass.
// Kui klassis puudub ligipääsu kirjeldus, on standard ligipääs klassi puhul "private", 
// ehk ühtegi meetodit ega andmevälja ei saa klassist välja kutsuda.

// Ligipääsu tüüpe on 3 - public, protected, private
class CBase
{
public:
	CBase() {};  // Initsialiseerimise funktsioon. Kui muutuja initsialiseerida, kutsutakse antud funktsioon.
	~CBase() {}; // Destruktor funktsioon. Kui klassi kasutus funktsioonis lõppeb, kutsutakse antud funktsioon. 

public:
	int m_Public;
protected:
	int m_Protected;
private:
	int m_Private;
};

int main(int argc, char *argv[])
{
	CBase cBase; // Initsialiseerimise funktsioon.
	cBase.m_Public = 0;
	
	//cBase.m_Protected = 0; <- Pole võimalik, sest protected ligipääsuga meetodid ja andmeväljad pole nähtavad väljaspoole klassi
	//cBase-m_Private = 0; <- Pole võimalik, sest protected ligipääsuga meetodid ja andmeväljad pole nähtavad väljaspoole klassi

	return 0; // Destruktor funktsioon.
}