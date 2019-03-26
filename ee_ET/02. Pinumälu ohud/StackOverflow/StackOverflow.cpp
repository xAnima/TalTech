#include "pch.h"
#include <iostream>

//Rakenduse jaoks on tavaliselt eraldatud 1MiB (1048576 bytes) pinumälu Windowsi operatsioonisüsteemi all.
// Linuxi op. süsteemi all, on tavaliselt eraldatud 8MiB (8388608 bytes).

// Variant 0 seletab rekursiooni stack overflow
// Mistahes muu variant seletab muutuja stack overflow
#define __VAR 0

int main(int argc, char *argv[])
{
#if __VAR == 0
	return main(argc, argv); //Lõpmata rekursioon. Tekitab stacki kuni väärtus ületab lubatud stacki suuruse.
#else
	// double andmetüüp on 8 baiti suur. Seega jagades teadaolev pinumälu suurus, saab enamvähem täpse arvu,
	// mille korral on rakenduses kasutatav pinumälu täielikult ära kasutatud.
	double dDouble[131072]; // Stack overflow!

	return 0;
#endif 
}