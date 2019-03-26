#include "pch.h"
#include <iostream>

// NB. malloc-ga allokeeritud mälu ei tohi kustutada delete-ga! 
//	   new-ga allokeeritud mälu ei tohi kustutada free-ga!

int main(int argc, char *argv[])
{
	//Dünaamilise mälu kasutus. Allokeerime 4*20 byte dünaamilisse mällu!
	int *p_iArray = new int[20];
    

	//Kui seda rida kustutada, tekib memory leak. Halb programmeerimise stiil.
	delete[] p_iArray;

	// Kui kasutada järgmist rida, tekib memory leak,
	// sest "delete" funktsioon kustutab ühe ainsa allokeeritud üksuse ja kaotab selle viida.
	// Halb programmeerimise stiil.
	//delete p_iArray;

	//Hea tava on peale dünaamilise mälu kustutamist, väärtustada pointer väärtusele NULL/nullptr
	p_iArray = nullptr; // Juhul, kui objekt on uuesti kustutatud, tagab see kaitset, et delete[] ei teeks midagi.


	// Ühe objekti näide
	p_iArray = new int;

	delete p_iArray;
	p_iArray = nullptr;

	///////////////////////////////////////////////////////
	// Fragmenteerimise näide
	// Eeldame, et meil on ainult 16 baiti dünaamilist mälu.
	///////////////////////////////////////////////////////
	p_iArray = new int;							// Allokeerime 4 baiti
	double *p_iB = new double;					// Allokeerime 8 baiti
	int *p_iA = (int*)malloc(1 * sizeof(int));	// Allokeerime 4 baiti

	free(p_iA);									// Kustutame 4 baiti
	p_iA = nullptr;

	delete p_iArray;							// Kustutame 4 baiti
	p_iArray = nullptr;

	double *p_iC = new double;					// Allokeerime 8 baiti
	// Kuid antud allokeerimise kutse ei hakka toimima, sest et mälus pole järjestikkust mälu plokki.
	// Seega tagastab antud kutse NULL, arvestades eelpool eeldatud tingimusi.


	delete p_iB;
	delete p_iC;


	return 0;
}