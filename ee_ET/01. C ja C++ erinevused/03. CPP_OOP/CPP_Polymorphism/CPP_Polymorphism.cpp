#include "pch.h"
#include <iostream>

// Polümorfism aitab implementeerida abstraktsust.
// Inimene on abstraktne klass. Võib öelda, et polümorfism omab mitut head omadust.
// 1) Näitena, võib alamklass kirjutada üle abstraktse klassi funktsiooni, kui see on omab tähistust "virtual".
// 2) Aitab käivitada abstraktset funktsiooni lihtsamalt, kui seda on vaja teha iga objekti kohta.

//Polümorfne klass CInimene public ligipääsuga.
class CInimene {
public:
	virtual void Say(void) { }; //Virtuaalne funktsioon, mida alamklassid saavad üle kirjutada.
};

//CTudeng pärib CInimeselt funktsioonid ja muutujad.
class CTudeng : public CInimene {
public:
	//Initsialiseerib enda variandi virtuaalsest funktsioonist Say.
	void Say(void) { std::cout << "Ma olen tudeng.\n"; };
};

class CProfessor : public CInimene {
public:
	//Initsialiseerib enda variandi virtuaalsest funktsioonist Say.
	void Say(void) { std::cout << "Ma olen professor.\n"; };
};

int main(int argc, char *argv[])
{
	//Objektide arv. (const, sest ilma ei saa omistada massiiv suuruse CInimene array jaoks.)
	const int iObjektideArv = 3;

	//3 CInimese abstraksest klassi pointeri.
	CInimene *pInimene[iObjektideArv];

	//Initsialiseerime klassi CInimene() ja viitame selle pointeri pInimene[0]
	pInimene[0] = &CInimene();

	//Initsialiseerime klassi CTudeng() ja viitame selle pointeri pInimene[1]
	pInimene[1] = &CTudeng();
	
	//Initsialiseerime klassi CProfessor() ja viitame selle pointeri pInimene[2]
	pInimene[2] = &CProfessor();

	//For tsükkel näitamaks tulemusi. 3 tsükklit kokku.
	for (int i = 0; i < iObjektideArv; i++)
		pInimene[i]->Say();
	//Väljastab: Ma olen tudeng.
	//			 Ma olen professor.
	//CInimene ei väljastanud midagi, sest et abstraktne klass ei sisalda implementatsiooni.

	return 0;
}