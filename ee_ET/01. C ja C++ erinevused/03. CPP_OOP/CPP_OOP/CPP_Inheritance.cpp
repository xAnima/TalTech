#include "pch.h"
#include <iostream>
#include <string>

// OOP Põhi teematika seisneb pärivuses, kapseldamises ja polümorfismis.
// Pärivus kirjeldab objekti omaduste pärimist alamklassile. Nt: Laps pärib välimuse vanematelt.

// Loengus lugesin pärivuse ligipääsude omavahelist sõltuvust, kuid arvan, et tabelina on seda lihtsam aru saada.
// Pärivuse tabel:
//	CInimese	|	Pärivuse tüüp alamklassis (CTudeng, CProfessor jne.)
//	Ligipääs	|		  Public		 Protected		  Private
//----------------------------------------------------------------------
//	Public		|		1.Public		4.Protected		7.Private
//	Protected	|		2.Protected		5.Protected		8.Private
//	Private		|		3.Kaitstud		6.Kaitstud		9.Kaitstud

/*
1. Public - CInimese "public" funktsioonid/muutujad on nähtavad/kutsutavad ka väljapoole läbi alamklasside CTudeng, CProfessor jne.
2. Protected - CInimese "protected" funktsioonid/muutujad on päritavad ka CTudeng, CProfessorist alamklassides. Pole väljapoole alamklassi nähtavad/kutsutavad.
3. Kaitstud - CInimese "private" funktsioonid/muutujad on nähtamatud alamklasside jaoks.
4. Protected - CInimese "public" funktsioonid/muutujad on päritavad alamklassidele. Pole väljapoole alamklassi nähtavad/kutsutavad.
5. Protected - CInimese "protected" funktsioonid/muutujad on päritavad alamklassidele. Pole väljapoole alamklassi nähtavad/kutsutavad.
6. Kaitstud - CInimese "private" funktsioonid/muutujad on nähtamatud alamklassidele.
7. Private - CInimese "public" funktsioonid/muutujad on päritavad alamklassidele. Pole väljapoole alamklassi nähtavad/kutsutavad ega päritavad edasi.
8. Private - CInimese "protected" funktsioonid/muutujad on päritavad alamklassidele. Pole väljapoole alamklassi nähtavad/kutsutavad ega päritavad edasi.
9. Private - CInimese "private" funktsioonid/muutujad on nähtamatud alamklassidele.
*/

class CInimene {
public:
	// Initsialiseerimise funktsioone võib olla mitu.
	// Seda nimetatakse funktsioonide ülekoormamiseks. (Function overloading)
	// Toimub see argumentide võrdluse kaudu.
	CInimene(void) { m_strSay = "Mina olen initialiseeritud!"; };	// Argumente pole
	CInimene(std::string strSay) { m_strSay = strSay; };			// Argument std::string strSay
	~CInimene(void) {};

	void Print(void) { std::cout << m_strSay << std::endl; }
protected:
	std::string m_strSay;
};

class CTudeng : public CInimene {
public:
	CTudeng(std::string strSay) { m_strSay = strSay; };
	~CTudeng(void) {};
};

class CProfessor : public CInimene {
public:
	CProfessor(std::string strSay) { m_strSay = strSay; };
	~CProfessor(void) {};
};

int main(int argc, char *argv[])
{
	//Initisialiseeri argumentideta
	CInimene cBase;
	cBase.Print();
	//Väljastab: Mina olen initialiseeritud!

	//Initisialiseeri argumendiga std::string
	CInimene cInimene("Mina olen inimene!");
	cInimene.Print();
	//Väljastab: Mina olen inimene!

	//Initisialiseeri argumendiga std::string
	CTudeng cTudeng("Mina olen tudeng!");
	cTudeng.Print();
	//Väljastab: Mina olen tudeng!
	
	//Initisialiseeri argumendiga std::string
	CProfessor cProfessor("Mina olen professor!");
	cProfessor.Print();
	//Väljastab: Mina olen professor!

	return 0;
}