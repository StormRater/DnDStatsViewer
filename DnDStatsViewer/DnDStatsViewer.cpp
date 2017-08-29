// DnDStatsViewer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <typeinfo>
#include "Character.h"
//#include "GenericArray.h"
#include "Array.h"
//#include "stdafx.h"


using namespace std;


int main(int argc, char* argv[])
{
	unsigned int numOfCharacters, input;
	if (argc < 2)
	{
		cout << "\e[1m" << "How many characters do you have? ";
		while (cin.fail() != true) {
			cin >> input;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT32_MAX, '\n');
				cout << "Please enter an actual integer, an integer greater than 2: ";
			}
			else {
				numOfCharacters = input;
				break;
			}
		}
	}

	//GenericArray<Character> CharacterList = GenericArray<Character>(numOfCharacters);

	//Character * array = new Character [numOfCharacters];
	//vector CharacterArray;


	return 0;
}

