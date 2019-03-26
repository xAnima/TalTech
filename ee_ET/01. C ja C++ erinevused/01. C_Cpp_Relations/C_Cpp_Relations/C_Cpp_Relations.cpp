/* 
/ Eelkompileeritud header(päise) fail, mis tagab kiirendust tulevasel kompilatsioonil
/ Kiirendus tuleneb sellest, et header failidel on ajatempel, ning kui fail ei muutu,
/ kasutatakse olemasolevat kompileeritud faili objekti.
*/
#include "pch.h" // Tuntud kui "stdafx.h" vanasti.

/*
/ Sisend/väljund objektide teek (C++ sisaldab objekte).
/ std::cout - (Puhverdatud) Väljund konsooli							| stdout
/ std::cin - Sisend konsoolilt											| stdin
/ std::cerr - (Puhverdamata) Väljund konsooli (Vigade kuvamiseks)		| stderr
/ std::clog - (Puhverdatud) Väljund konsooli (Teadete jaoks)			| stderr
*/
#include <iostream>

/*
* Teegi lisamine, mis tagab std::string klassi funksionaalsust.
* Täpsemalt "Sisendi näide" teema all.
*/
#include <string>

/*
/ argc - argumentide arv
/ *argv[] - viide 2 mõõtmelisele array-le.
/			NB! argv[0] on argument, mis sisaldab binaari asukohta.
/				argv[1+n] on kasutaja sisestatud väärtused rakenduse käivitamisel ( n >= 0 )
*/
int main(int argc, char *argv[])
{
	////////////////////////////////////////////////////////////////////////////////
	// Standard väljundi näide
	////////////////////////////////////////////////////////////////////////////////

	// Puhvri allokeerimine pinumällu suurusega 14 baiti.
	char szBuffer[14] = "Hello World!"; // Hello world väärtuse omistamine

	// Output objektile cout puhvri szBuffer kirjutamine
	// std:endl tähendab kirjuta väljundisse \n
    std::cout << szBuffer << std::endl;

	// C analoog ülemisele C++ versioonile.
	printf("%s\n", szBuffer);

	////////////////////////////////////////////////////////////////////////////////
	// Sisendi näide
	////////////////////////////////////////////////////////////////////////////////

	// string on kapseldatud class char massivile, milles tähtsaim funktsionaalsus on kirjeldatud klassi funktsioonidena
	// Eelistatuim viis tektsiliste andmete töötlusel C++-s
	// Vajab #include <string>, et sisendi objektid saaks antud muutuja tüüpi kasutada.
	std::string strBuffer;

	// Sisestab konsooli sisestatud kasutaja andmed(Kasutaja kirjutab ning vajutab ENTER) std::string puhvrisse.
	std::cin >> strBuffer;
	
	// For tsükkel, mis kirjeldab igat sisestatud tähte.
	// unsigned int - 0-st kuni 4294967295. Loengus näidatud link: https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=vs-2017
	// strBuffer.size() tagastab strBuffer muutujas olevate andmete suurust.
	// NB. Kui strBuffer omaks väärtust "Hello", siis tagastatav väärtus on 5.
	//	   See on tingitud sellest, et strBuffer ei sisalda \0 . (Null terminaatorit)
	//	   Seega sisesed char massiivi väärtused on järgmised:
	//			strBuffer[0] = 'H';
	//			strBuffer[1] = 'e';
	//			strBuffer[2] = 'l';
	//			strBuffer[3] = 'l';
	//			strBuffer[4] = 'o';
	for (unsigned int i = 0; i < strBuffer.size(); i++)
		std::cout << strBuffer[i];

	std::cout << std::endl;

	// Ülemise funktsiooni analoog C-s.
	// strBuffer.c_str(), tagastab massiivi salvestatud väärtused C kujul.
	// See tähendab seda, et funktsiooni tulemuseks on const char* massiiv.
	// Erinevus seisneb selles, et "Hello" puhul, lisab funktsioon lõppu \0
	// ning tagab antud andmete säilimist, ehk siis mäluhaldust korraldab std::string class.
	// strlen on C teegi funktsioon, mis tagastab char massiivi suuruse.
	for (unsigned int i = 0; i < strlen(strBuffer.c_str()); i++)
		printf("%c", strBuffer[i]);

	std::cout << std::endl;

	// NB. Kui on soov väljastada std::string printf() abil, tuleb alati kasutada .c_str() funktsiooni,
	// teisendamaks std::string klassi objekti C teegile arusaadavaks.
	printf("%s\n", strBuffer.c_str());
	
	// C++ objektide puhul ei pea, sest et #include <string> lisab operaatoreid, et tagada antud funktsionaalsus.
	std::cout << strBuffer << std::endl;

	////////////////////////////////////////////////////////////////////////////////
	// LISA: Väljundi näide (Error)
	////////////////////////////////////////////////////////////////////////////////

	// Sammuti väljastab alloleva teksti konsooli. Kuid, kui kasutada näiteks Linuxi operatsioonisüsteemi, 
	// siis kirjutades shelli "ProgrammiNimi.exe > out.txt" (Andmevoo ümbersuunamine faili) on failis 
	// ainult std::cout objekti edastatud tekstid.
	// Juhul, kui on soov salvestada ainult stderr faili, siis tuleb kirjutada shelli "ProgrammiNimi.exe 2> out.txt"
	// Juhul, kui on soov salvestada nii stderr, kui ka stdout, siis tuleb kirjutala shelli "ProgrammiNimi.exe &> out.txt"
	std::cerr << "Programmis on viga!\n";

	// Funktsioon lõpetab tegevuse heatahtlikult 0
	return 0;
}