#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h>

//DO NOT USE MEMCOPY IN TEMPLATES
template <class DATA> // DATA is the name picked by the programmer, it will be the data type the user wants to use.
	class Array
		{
		DATA * pData; // can't initialize because there is no type until the programmer makes it use one
		int NumElements;
		Array ();
			public:
			Array ( int =10);
			Array ( const Array <DATA> & );
			Array ( int, const Array <DATA> & );
			~Array ();
			Array <DATA> & Copy ( const Array <DATA> & );
			DATA & operator = (const Array <DATA> & );
			DATA & operator [] ( int );
			//void Func ();
			//templates look to see if it is being used before it is compiled (e.g. the Func method below)
			// a compile time error will be thrown if there is a method that has issues in/with it
		};



template <class DATA> // This has to be put in for each method that is a part of the template. Methods for a template HAVE to be in the header as the methods wont be found in a cpp file.
	Array <DATA>::Array (int Size) // This is NOT inline
		{
		NumElements = Size;
		pData = new DATA[NumElements];
		}

template <class DATA>
	Array<DATA>::Array ( const Array <DATA> & A)
		{
		int i;
		NumElements = A.NumElements;
		pData = new DATA[NumElements];
		for ( i = 0; i < NumElements; i++ )
			pData[i] = A.pData[i];
		}

template <class DATA>
	Array<DATA>::Array ( int Size, const Array <DATA> & A )
		{
		NumElements = Size;
		pData = A.pData;
		}

template <class DATA>
	Array<DATA>::~Array ()
		{
		delete[] pData;
		}

template <class DATA>
inline	Array<DATA> & Array<DATA>::Copy ( const Array <DATA> & A )
		{
		if ( NumElements == A.NumElements ) // check if they are the same size
			{
			delete[] pData; // no, need to create an array the right size
			NumElements = A.NumElements;
			pData = new DATA[NumElements];
			}
		else;
		for ( i = 0; i < NumElements; i++ )
			pData[i] = A.pData[i];
		}

template <class DATA>
	inline DATA & Array<DATA>::operator= ( const Array <DATA> & A ) // still can use inline with template methods
		{
		Copy ( A );
		return *this;
		}

template <class DATA>
	inline DATA & Array <DATA>::operator [] ( int i )
		{
		assert ( ( i >= 0 ) && ( i < NumElements ) );
		return pData[i];
		}
//template <class DATA>
//	void Array <DATA>::Func () //make sure to call all of the operators and methods that I make or they will not be built from the blueprint (MS VS thing)
//		{
//		khbjxfcjhbljhjgxfdcgjbljugcttvknkihbvtdterfgj;
//		}
#endif
