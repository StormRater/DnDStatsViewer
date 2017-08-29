#pragma warning (disable:4996)

#include <iostream>
#include <string.h>
#include <memory.h>
#include "NRJ_String.h"
using namespace std;

String::String ()
	{
	NumChar = 0;
	NumSlots = NumChar;
	pChar = new char[NumChar + 1];
	pChar[0] = '\0';
	}

String::String ( const String & copy )
	{
	NumChar = copy.NumChar;
	NumSlots = NumChar;
	pChar = new char[NumChar + 1];
	strcpy ( pChar, copy.pChar );
	}

String::String ( const char Str[] )
	{
	NumChar = strlen ( Str );
	NumSlots = NumChar;
	pChar = new char[NumChar + 1];
	strcpy ( pChar, Str );
	}

String::~String ()
	{
	delete [] pChar;
	}

// Adds the passed argument to the end of the String object calling this method
//make sure that if i were to pass S1.Concat(S1), that the output is ABCDABCD if S1.pChar == ABCD;
void String::Concat ( const String & Str )
	{
	NumChar += Str.Len ();
	char * temp = new char[NumChar + 1];
	strcpy ( temp, pChar );
	delete[] pChar;
	pChar = temp;
	strcat ( pChar, Str.pChar );
	}

void String::Concat ( const char Str[] )
	{
	NumChar += strlen ( Str );
	char * temp = new char[NumChar + 1];
	strcpy ( temp, pChar );
	delete[] pChar;
	pChar = temp;
	strcat ( pChar, Str );
	}
// The argument replaces the content of char* in the particular String object
void String::Copy ( const String & Str )
	{
	if ( this != &Str )
		{
		NumChar = Str.NumChar;
		if ( NumSlots <= Str.NumChar )
			{
			delete[] pChar;
			NumSlots = NumChar;
			pChar = new char[NumChar + 1];

			}
		else;
		}
	
	strcpy ( pChar, Str.pChar );
	}

void String::Copy ( const char Str[] )
	{
	NumChar = strlen ( Str );
	if ( NumSlots <= NumChar )
		{
		delete[] pChar;
		NumSlots = NumChar;
		pChar = new char[NumChar + 1];
		}
	else;
	strcpy ( pChar, Str );
	}

void String::Read ( istream & in )
	{
	char c;

	NumChar = 0;
	if ( NumSlots == 0 )
		{
		NumSlots = 50;
		delete[] pChar;
		pChar = new char[NumSlots + 1];
		}
		else;
		while ( ( c = in.get () ) != '\n' )
		{
		pChar[NumChar++] = c;
		if ( NumChar == NumSlots ) // array is full, get a bigger array
			{
			char * Temp;
			Temp = new char[NumSlots += 50];
			memcpy ( Temp, pChar, NumChar );
			delete[] pChar; //no longer needed
			pChar = Temp;
			}
		}
	pChar[NumChar] = '\0';
	}

String String::operator & ( const String & Str ) const
	{
	String Temp ( *this );
	Temp.Concat ( Str );
	return Temp;
	}

String String::operator & ( const char cStr[] ) const
	{
	String Temp ( *this );
	Temp.Concat ( cStr );
	return Temp;
	}

String String::operator&= ( const String & Str ) 
	{
	*this = *this&Str;
	return *this;
	}

String String::operator&= ( const char cStr[] )
	{
	*this = *this&cStr;
	return *this;
	}

