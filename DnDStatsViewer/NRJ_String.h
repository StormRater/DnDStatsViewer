// Author:		Nicholas Johnson
// Program:		Program/Lab 1
// Section:		1437.S02
// Date:		January 28, 2015

#ifndef NRJ_STRING_H
#define NRJ_STRING_H

#include <iostream>
#include <string.h>
//#pragma warning (disable:4800)

// TODO: Note to self, MSVC shortcut to collapse all methods: CTRL + M + O
// CTRL + M + L will expand all
// CTRL + M + P will expand all and disable outlining
// CTRL + M + M will collapse/expand the current section

using namespace std;

enum Exceptions {
	InvalidCharacterForType,
	OutOfBoundsException,
	InvalidLength
	};

class String
	{
		protected:
			int NumChar;
			int NumSlots;
			char * pChar;

		public:
				 String (); //Default constructor
				 String ( const String & ); //Copy constructor
		explicit String ( const char[] ); //Allows for rogue character arrays to be encapsulated by a String object
virtual			~String (); // Destructor
		int			GetSize	() const;
		int			Compare ( const String &) const;
		int			Compare ( const char[] ) const;
		void		Concat ( const String & ); //Adds the argument string to the end of this string object
		void		Concat ( const char[] );
		void		Copy ( const String & ); //Copies this string object to the end of the argument string/char[]
		void		Copy ( const char[] );
		ostream & 	Display ( ostream & = cout) const; //Displays to the console the contents of the string. Similar to toString() usage in Java
		int			Len () const; // Returns the number of characters in a string object
virtual	void		Read ( istream & = cin );		// the = means that if no parameter is passed to this method, the compiler will automatically make cin the parameter
		char*		GetpChar () const;
		//void		Show ( ostream & = cout ) const;	// const after the parens means that this method cannot change anything in the class

virtual	bool		IsValid() const{ return true; };
		String &	operator =	( const String & );		// the space between the word and the symbol is optional
		String &	operator =	( const char[] );
		bool		operator <	( const String & ) const;
		bool		operator <	( const char[] ) const;
		bool		operator <= ( const String & ) const;
		bool		operator <= ( const char[] ) const;
		bool		operator == ( const String & ) const;
		bool		operator == ( const char[] ) const;
		bool		operator != ( const String & ) const;
		bool		operator != ( const char[] ) const;
		bool		operator >= ( const String & ) const;
		bool		operator >= ( const char[] ) const;
		bool		operator >  ( const String & ) const;
		bool		operator >  ( const char[] ) const;
		String		operator &	( const String & ) const;	// note the return by value
		String		operator &	( const char[] ) const;
		String		operator &= ( const String & );
		String		operator &= ( const char[] );
		
		// << and >> operator overloads are included towards the bottom of this header

	};
inline int String::GetSize() const
{
	return NumChar;
}

inline int String::Compare ( const String & Str ) const
	{
	return strcmp ( pChar, Str.pChar );
	}

inline int String::Compare ( const char Chars[] ) const
	{
	return strcmp ( pChar, Chars );
	}

inline ostream & String::Display (ostream & out) const
	{
	out << pChar;
	return out;
	}

inline int String::Len () const
	{
	return NumChar;
	}

inline char* String::GetpChar () const
	{
	return pChar;
	}

//inline void String::Show ( ostream & out ) const
//	{
//	out << pChar;
//	}

inline String & String::operator= ( const String & Str)
	{
	Copy ( Str );
	return *this;
	}

inline String & String::operator= ( const char cStr[] )
	{
	Copy ( cStr );
	return *this;
	}


inline bool String::operator < ( const String & str ) const
	{
	return Compare ( str ) < 0;
	}

inline bool String::operator < ( const char str[] ) const
	{
	return Compare ( str ) < 0;
	}

inline bool operator < ( const char cStr[], const String & Str )
	{
	return ( strcmp ( cStr, Str.GetpChar() ) < 0 );
	}


inline bool String::operator <= ( const String & str ) const
	{
	return Compare ( str ) <= 0;
	}

inline bool String::operator <= ( const char str[] ) const
	{
	return Compare ( str ) <= 0;
	}

inline bool operator <= ( const char cStr[], const String & Str )
	{
	return ( strcmp ( cStr, Str.GetpChar() ) <= 0 );
	}


inline bool String::operator == ( const String & str ) const
	{
	return Compare ( str ) == 0;
	}

inline bool String::operator == ( const char str[] ) const
	{
	return (Compare ( str ) == 0);
	}

inline bool operator == ( const char cStr[], const String & Str )
	{
	if ( strcmp ( cStr, Str.GetpChar() ) == 0 )
		return true;
	else
		return false;
	}


inline bool String::operator != ( const String & str ) const
	{
	return !( strcmp ( pChar, str.GetpChar () ) == 0 );
	}

inline bool String::operator != ( const char str[] ) const
	{
	return !( strcmp ( pChar, str ) == 0 );
	}
// For the C String interacting with my String object
inline bool operator != ( const char cStr[], const String & str )
	{
	return !( str.Compare ( cStr ) == 0 );
	}


inline bool String::operator >= ( const String & Str ) const
	{
	return ( Compare ( Str ) >= 0 );
	}

inline bool String::operator >= ( const char Str[] ) const
	{
	return ( Compare ( Str ) >= 0 );
	}

inline bool operator >= ( const char cStr[], const String & Str )
	{
	return ( strcmp ( cStr, Str.GetpChar () ) >= 0 );
	}


inline bool String::operator > ( const String & Str ) const
	{
	return ( Compare ( Str ) > 0 );
	}

inline bool String::operator > ( const char Str[] ) const
	{
	return ( Compare ( Str ) > 0 );
	}

inline bool operator > ( const char cStr[], const String & Str )
	{
	return ( strcmp ( cStr, Str.GetpChar() ) > 0 );
	}


// Concat operator is in the cpp for this header
// Concat and assign operator is in the cpp for this header

inline ostream & operator << ( ostream & out, const String & Str )
	{
	return Str.Display ( out );
	}

inline istream & operator >> ( istream & in, String & Str )
	{
	Str.Read ( in );
	return in;
	}


#endif
