#include "pch.h"
#include <iostream>

// Kapseldamine on kasutusel selleks, et anda ligipääs piiratud õigusega muutujatele või funktsioonidele. (private ligipääsuga)
// Teiseks tähtsaks omadusega on see, et see tekitab modulaarset koodi, mida on hiljem tõhus muuta.

class CInimene {
public:
	// Tavaliselt, on mõistlik algväärtustada klassi muutujad, millele on kuvamise ligipääs.
	// Kui algväärtustamist poleks ja programmeerija kasutaks PrintLocation(), siis antud rakendus
	// väljastaks ettearvamatuid väärtusi.
	CInimene() { SetLocation(0, 0, 0); };
	~CInimene() {};

	void PrintLocation() {
		//Klassi sees võib sammuti kasutada kapseldatud funktsioone, kui ka klassi muutujaid.
		std::cout << "x: " << m_iLoc[0] << " " << GetLocation(0) << std::endl
				  << "y: " << m_iLoc[1] << " " << GetLocation(1) << std::endl
				  << "z: " << m_iLoc[2] << " " << GetLocation(2) << std::endl;
	}

	// Kapseldamise näidis
	// Kapseldatava väärtuse omistamine
	void SetLocation(int x, int y, int z) { m_iLoc[0] = x, m_iLoc[1] = y, m_iLoc[2] = z; };
	// Kapseldatava väärtuse pärimine
	int GetLocation(int iAxis) { return m_iLoc[iAxis]; }
private:
	int m_iLoc[3]; //x, y, z - inimese asukoht (Kapseldatav väärtus)
};

int main(int argc, char *argv[])
{
	// Klassi initsialiseerimine
	CInimene cInimene;

	// Kuvab asukohaks 0 0 0
	cInimene.PrintLocation();

	// Asukoha omistamine
	cInimene.SetLocation(200, 400, 500);

	// Asukoha kuvamine väljundisse.
	cInimene.PrintLocation();

	return 0;
}