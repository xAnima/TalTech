#include "pch.h"
#include <iostream>

// C++ erinevus struct muutujas seisneb selles, et struct-s ei tohi kasutada funktsioone.
// C++-s on struktuurid kui klassid, seega tohib siin kasutada funktsioone. Erinevus klassidega seisneb selles,
// et C++ struct on standardi põhiselt "public" ligipääsuga.

struct SExample {
	//Initsialiseerimise funktsioon
	SExample(int iCnt) { i_privCount = iCount = iCnt; }

	//Standardi põhiselt on struct ligipääs "public"
	int iCount;
	void Print() { std::cout << "Count: " << iCount << std::endl; }
	void PrintPriv() { std::cout << "Private count: " << i_privCount << std::endl; }

private:
	int i_privCount; //"private" ligipääsuga muutuja
};

int main(int argc, char *argv[])
{
	SExample test(99);	// struct initsialiseerimine algväärtusega 99
	test.iCount = 50;	// iCount on "public" ligipääsuga.

	test.Print();		// Väljastab: 50
	test.PrintPriv();	// Väljastab: 99

	return 0;
}