#ifndef NODOA_H
#define NODOA_H

#include <iostream>

using namespace std;

template <class tipo>
class NodoA
{
	private:

		tipo dato;

		NodoA<tipo>* hijoIzquierdo;

		NodoA<tipo>* hijoDerecho;

	public:

		NodoA();

		NodoA( tipo nuevoDato );
		
		NodoA( tipo nuevoDato, NodoA<tipo>* nuevoHijoIzquierdo, NodoA<tipo>* nuevoHijoDerecho );

		~NodoA();

		//metodos

		tipo obtenerDato();

		void modificarDato( tipo nuevoDato );

		NodoA<tipo>* obtenerHijoIzquierdo();

		NodoA<tipo>* obtenerHijoDerecho();

		void modificarHijoIzquierdo( NodoA<tipo>* nuevoHijoIzquierdo );

		void modificarHijoDerecho( NodoA<tipo>* nuevoHijoDerecho );

		bool esHoja();//indica si el nodo es una hoja
};

template <class tipo>
NodoA<tipo>::NodoA()
{
	this->hijoIzquierdo = NULL;

	this->hijoDerecho = NULL;
}

template <class tipo>
NodoA<tipo>::NodoA( tipo nuevoDato )
{
	this->dato = nuevoDato;

	this->hijoIzquierdo = NULL;

	this->hijoDerecho = NULL;
}

template <class tipo>
NodoA<tipo>::NodoA( tipo nuevoDato, NodoA<tipo>* nuevoHijoIzquierdo, NodoA<tipo>* nuevoHijoDerecho )
{
	this->dato = nuevoDato;

	this->hijoIzquierdo = nuevoHijoIzquierdo;

	this->hijoDerecho = nuevoHijoDerecho;
}

template <class tipo>
NodoA<tipo>::~NodoA()
{
	this->hijoDerecho = NULL;

	this->hijoIzquierdo = NULL;
}

template <class tipo>
tipo NodoA<tipo>::obtenerDato()
{
	return( this->dato );
}

template <class tipo>
void NodoA<tipo>::modificarDato( tipo nuevoDato )
{
	this->dato = nuevoDato;
}

template <class tipo>
NodoA<tipo>* NodoA<tipo>::obtenerHijoIzquierdo()
{
	return( this->hijoIzquierdo );
}

template <class tipo>
NodoA<tipo>* NodoA<tipo>::obtenerHijoDerecho()
{
	return( this->hijoDerecho );
}

template <class tipo>
void NodoA<tipo>::modificarHijoIzquierdo( NodoA<tipo>* nuevoHijoIzquierdo )
{
	this->hijoIzquierdo = nuevoHijoIzquierdo;
}

template <class tipo>
void NodoA<tipo>::modificarHijoDerecho( NodoA<tipo>* nuevoHijoDerecho )
{
	this->hijoDerecho = nuevoHijoDerecho;
}

template <class tipo>
bool NodoA<tipo>::esHoja()
{
	return( this->hijoIzquierdo == NULL && this->hijoDerecho == NULL );
}

#endif
