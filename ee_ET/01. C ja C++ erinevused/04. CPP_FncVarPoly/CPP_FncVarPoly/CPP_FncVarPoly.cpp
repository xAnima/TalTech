#include "pch.h"
#include <iostream>
#include <string>

// Funktsiooni polümorfism("ülekoormamine" - overloading) tähendab seda, et ühel funktsioonil nimel võib olla erineva andmetüübiga argumendid
// ning nad on sellepoolest ka erinevad.

// Overloaded funktsioon andmetüüpiga char massiiv.
void Print(const char *szBuffer) {
	printf("char massiiv: %s\n", szBuffer);
}

// Overloaded funktsioon andmetüüpiga std::string.
void Print(std::string strBuffer) {
	std::cout << "String: " << strBuffer << std::endl;
}

// Overloaded funktsioon andmetüüpiga int.
void Print(int iNum) {
	std::cout << "Number: " << iNum << std::endl;
}

// LISA HUVILISTELE:
template <class T>
void PrintTemplate(T t) {
	printf("%d\n", (int)t); //Muutuja castimine on üks muutuja polümorfismi viisidest. C keele moodi.
}
//LISA LÕPP

int main(int argc, char *argv[])
{
	std::string strText = "TalTech!";
	char szBuffer[10] = "IT People";
	int iMuutuja = 500;

	//Väljastab std::string funktsiooni
	Print(strText);

	//Väljastab int funktsiooni
	Print(iMuutuja);

	//Väljastab char massiivi funktsiooni
	Print(szBuffer);

	//Väljastab char massiivi funktsiooni, sest andmetüüp on "const char *"
	Print(strText.c_str());

	//LISA:
	PrintTemplate(20);			// Väärtus on 20
	PrintTemplate(20.9f);		// Väärtus on 20
	PrintTemplate('A');			// ASCII tähe väärtus, kõik on OK!
	PrintTemplate("Test");		// Väärtus on ettearvamatu. Halb stiil!
	//LISA LÕPP

	return 0;
}