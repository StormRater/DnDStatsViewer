#ifndef GEN_ARRAY_H
#define GEN_ARRAY_H

template <class DATA> class GenericArray {
private:
    int size, pos;
    DATA objArray[];
explicit    GenericArray ();
public:
explicit    GenericArray (const int s);
    //        Copy
    void    addObject ( const DATA );
    DATA    getObject ( int ) const;
//    DATA &   getArray () const;

};

template<class DATA> GenericArray<DATA>::GenericArray ( const int s ) {
    size = s;
    this.objArray = new DATA [size];
}

template<class DATA>
inline void GenericArray<DATA>::addObject ( const DATA obj ) {
    
    this.objArray[size-1] = obj;    
}

template<class DATA>
inline DATA GenericArray<DATA>::getObject(int) const
{
	return this.objArray[pos];
}


/*template<class DATA> const DATA & getArray () {

    return new &DATA;
}*/


#endif
