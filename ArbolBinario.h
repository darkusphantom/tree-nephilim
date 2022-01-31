#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoA.h"
#include <list>
#include <cmath>

template <class tipo>
class ArbolBinario
{
	protected:

		NodoA<tipo>* raiz;

	public:
		ArbolBinario();
		ArbolBinario( tipo nuevoDato );
		ArbolBinario( tipo nuevoDato, const ArbolBinario<tipo>* nuevoIzquierda, const ArbolBinario<tipo>* nuevoDerecha );
		ArbolBinario( const ArbolBinario<tipo> &arbolOriginal );
		~ArbolBinario();

		//metodos

		bool esNulo();//indica si el arbol es nulo

		tipo obtenerRaiz();//devuelve el dato del nodo raiz

		void copiar( const ArbolBinario<tipo> &arbolOriginal );//copia un arbol existente en la instancia

		void preorden( list<tipo> &listaRecorrido );//crea un recorrido en preorden
		void postorden( list<tipo> &listaRecorrido );//crea un recorrido en postorden
		void inorden( list<tipo> &listaRecorrido );//crea un recorrido en inorden

		void niveles( list<tipo> &listaRecorrido );//crea un recorrido por niveles

		void vaciar();//vacia el arbol

		int altura();//retorna la altura de un arbol

		int diametro();//retorna el diametro de un arbol

		void preordenInorden( list<tipo> preorden, list<tipo> inorden );//construye um arbol con el recorrido en preorden e inorden

		void postordenInorden( list<tipo> postorden, list<tipo> inorden );//construye um arbol con el recorrido en postorden e inorden

		bool esHoja();//indica si la raiz del arbol es una hoja

		void insertarHijoIzquierdo( tipo nuevoDato, tipo padre );//inserta un nuevo dato como hijo izquierdo al nodo padre

		void insertarHijoDerecho( tipo nuevoDato, tipo padre );//inserta un nuevo dato como hijo derecho al nodo padre

		int peso();//devuelve el peso dl arbol

		bool completo();//indica si un arbol es completo

		bool lleno();//indica si el arbol esta lleno

		bool iguales( const ArbolBinario<tipo> &arbol2 );//indica si dos arboles son iguales

		bool isomorfo( const ArbolBinario<tipo> &arbol2 );//indica si dos arboles son isomorfos

		bool semejantes( const ArbolBinario<tipo> &arbol2 );//indica si dos arboles son semejantes

		bool surdo();//indica si un arbol es surdo

	protected:
		void preorden( NodoA<tipo> *nodoActual, list<tipo> &listaRecorrido );//inserta el recorrido en una lista
		void postorden( NodoA<tipo> *nodoActual, list<tipo> &listaRecorrido );//inserta el recorrido en una lista
		void inorden( NodoA<tipo> *nodoActual, list<tipo> &listaRecorrido );//inserta el recorrido en una lista

		void vaciar( NodoA<tipo>* nodoActual );//vacia el arbol
		NodoA<tipo>* copiar( NodoA<tipo>* nodoActual );//copia nodo a nodo los nodos del arbol existente
		void altura( NodoA<tipo>* nodoActual, int alturaActual, int &alturaMayor );//recorre el arbol buscando la mayor altura
		void diametro( NodoA<tipo>* nodoActual, int &diametroMayor );//recorre los nodos buacando los diametros

		NodoA<tipo>* crearPreordenInorden( list<tipo> &preorden, list<tipo> &inorden );//constructor del arbol preorden inorden
		NodoA<tipo>* crearPostordenInorden( list<tipo> &postorden, list<tipo> &inorden );//constructor del arbol postorden inorden

		void insertarIzquierdo( NodoA<tipo>* nodoActual, tipo nuevoDato, tipo padre, bool &insertado );//busca al nodo padre y le inserta un hijo izquierdo
		void insertarDerecho( NodoA<tipo>* nodoActual, tipo nuevoDato, tipo padre, bool &insertado );//busca al nodo padre y le inserta un hijo derecho

		int peso( NodoA<tipo>* nodoActual );//calcula el peso de un arbol

		void completo( NodoA<tipo>* nodoActual, bool &completo );//se corre el arbol y busca los nodos no terminales y los comprueba

		void lleno( NodoA<tipo>*nodoActual, int alturaActual, int altura, bool &lleno );//recorre el arbol e indica si el arbol esta lleno

		void iguales( NodoA<tipo>* nodo1, NodoA<tipo>* nodo2, bool &iguales );//recorre el arbo comparando cada uno de los nodos

		void isomorfo( NodoA<tipo>* nodo1, NodoA<tipo>* nodo2, bool &isomorfo );//recorre el arbol comprobando si son isomorfos

		bool compararRecorrido( list<tipo> recorrido1, list<tipo> recorrido2 );//ordena y compara todos los elementos de los arboles

		double resolverArbolSintaxis( NodoA<tipo>* nodoActual );//resuelve un arbol de sintaxis
		
		double operador( double valor1, double valor2, tipo signo );//toma un operador char y realiza la operacion

		void surdo( NodoA<tipo>* nodoActual, bool &esSurdo );//recorre y compara la altura de las ramas para saber si el arbol es surdo
};

template <class tipo>
ArbolBinario<tipo>::ArbolBinario()
{
	this->raiz = NULL;
}

template <class tipo>
ArbolBinario<tipo>::ArbolBinario( tipo nuevoDato )
{
	this->raiz = new NodoA<tipo>( nuevoDato );
}

template <class tipo>
ArbolBinario<tipo>::ArbolBinario( tipo nuevoDato, const ArbolBinario<tipo>* nuevoIzquierda, const ArbolBinario<tipo>* nuevoDerecha )
{
	 this->raiz = new NodoA<tipo>( nuevoDato, this->copiar( nuevoIzquierda->raiz ), this->copiar( nuevoDerecha->raiz ));
}

template <class tipo>
ArbolBinario<tipo>::ArbolBinario( const ArbolBinario<tipo> &arbolOriginal )
{
	this->raiz = this->copiar( arbolOriginal.raiz );
}

template <class tipo>
ArbolBinario<tipo>::~ArbolBinario()
{
	if ( this->raiz != NULL )
	{
		this->vaciar( this->raiz );
	}
}

template <class tipo>
bool ArbolBinario<tipo>::esNulo()
{
	return( this->raiz == NULL );
}

template <class tipo>
tipo ArbolBinario<tipo>::obtenerRaiz()
{
	return( this->raiz->obtenerDato() );
}

template <class tipo>
void ArbolBinario<tipo>::copiar( const ArbolBinario<tipo> &arbolOriginal )
{
	this->raiz = this->copiar( arbolOriginal.raiz );
}

template <class tipo>
void ArbolBinario<tipo>::preorden( list<tipo> &listaRecorrido )
{
	this->preorden( this->raiz, listaRecorrido );
}

template <class tipo>
void ArbolBinario<tipo>::postorden( list<tipo> &listaRecorrido )
{
	this->postorden( this->raiz, listaRecorrido );
}

template <class tipo>
void ArbolBinario<tipo>::inorden( list<tipo> &listaRecorrido )
{
	this->inorden( this->raiz, listaRecorrido );
}

template <class tipo>
void ArbolBinario<tipo>::niveles( list<tipo> &listaRecorrido )
{
	list<NodoA<tipo>*> listaNodos;
	NodoA<tipo>* nodoPadre;

	//insertamos el primer nodo en la lista de nodos
	listaNodos.push_back( this->raiz );

	//insertamos el primer elemento del recorrido
	listaRecorrido.push_back( this->raiz->obtenerDato() );

	//iniciamos el nodo padre para obtener los hijos por niveles
	nodoPadre = this->raiz;

	//ciclo que obtiene los hijos de los nodos padres e inserta el la lista recorrido
	while ( !listaNodos.empty() )
	{
		//obtenemos el hijo izquierdo del nodo padre
		if ( nodoPadre->obtenerHijoIzquierdo() != NULL )
		{
			listaNodos.push_back( nodoPadre->obtenerHijoIzquierdo() );
		}
		
		//obtenemos el hijo derecho del nodo padre
		if ( nodoPadre->obtenerHijoDerecho() != NULL )
		{
			listaNodos.push_back( nodoPadre->obtenerHijoDerecho() );
		}

		//eliminamos el primer nodo de la lista de nodos
		listaNodos.pop_front();

		//obtenemos el siguiente nodo padre y lo insertamos en la lista de recorrido
		if ( !listaNodos.empty() )
		{
			nodoPadre = listaNodos.front();
			listaRecorrido.push_back( nodoPadre->obtenerDato() );
		}
		
	}
}

template <class tipo>
void ArbolBinario<tipo>::vaciar()
{
	if ( this->raiz != NULL )
	{
		this->vaciar( this->raiz );

		this->raiz = NULL;
	}	
}

template <class tipo>
int ArbolBinario<tipo>::altura()
{
	int alturaMayor = -1;

	this->altura( this->raiz, 0, alturaMayor );

	return( alturaMayor );
}

template <class tipo>
int ArbolBinario<tipo>::diametro()
{
	int diametroMayor = -1;

	this->diametro( this->raiz, diametroMayor );

	return( diametroMayor );
}

template <class tipo>
void ArbolBinario<tipo>::preordenInorden( list<tipo> preorden, list<tipo> inorden )
{
	this->raiz = this->crearPreordenInorden( preorden, inorden );
}

template <class tipo>
void ArbolBinario<tipo>::postordenInorden( list<tipo> postorden, list<tipo> inorden )
{
	this->raiz = this->crearPostordenInorden( postorden, inorden );
}

template <class tipo>
bool ArbolBinario<tipo>::esHoja()
{
	//se comprueba si ambos hijos apuntan a null
	return( this->raiz->esHoja() );
}

template <class tipo>
void ArbolBinario<tipo>::insertarHijoIzquierdo( tipo nuevoDato, tipo padre )
{
	bool insertado = false;

	this->insertarIzquierdo( this->raiz, nuevoDato, padre, insertado );
}

template <class tipo>
void ArbolBinario<tipo>::insertarHijoDerecho( tipo nuevoDato, tipo padre )
{
	bool insertado = false;

	this->insertarDerecho( this->raiz, nuevoDato, padre, insertado );
}

template <class tipo>
int ArbolBinario<tipo>::peso()
{
	return( this->peso( this->raiz ) );
}

template <class tipo>
bool ArbolBinario<tipo>::completo()
{
	bool completo = true;

	this->completo( this->raiz, completo );

	return( completo );
}

template <class tipo>
bool ArbolBinario<tipo>::lleno()
{
	int altura;

	bool lleno = true;

	//obtenoms la altur del arbol
	altura = this->altura();

	//verificamos si el arbol esta lleno
	this->lleno( this->raiz, 0, altura, lleno );

	return( lleno );
}

template <class tipo>
bool ArbolBinario<tipo>::iguales( const ArbolBinario<tipo> &arbol2 )
{
	bool iguales = true;

	this->iguales( this->raiz, arbol2.raiz, iguales );

	return( iguales );
}

template <class tipo>
bool ArbolBinario<tipo>::isomorfo( const ArbolBinario<tipo> &arbol2 )
{
	bool isomorfo = true;

	this->isomorfo( this->raiz, arbol2.raiz, isomorfo );

	return( isomorfo );
}

template <class tipo>
bool ArbolBinario<tipo>::semejantes( const ArbolBinario<tipo> &arbol2 )
{
	list<tipo> recorrido1, recorrido2;

	//se obtiene el recorrido del arbol instancia
	this->preorden( this->raiz, recorrido1 );

	//se obtiene el recorrido del arbol parametro
	this->preorden( arbol2.raiz, recorrido2 );

	//se procede a compara ambos recorridos
	return( this->compararRecorrido( recorrido1, recorrido2 ) );
}

template <class tipo>
bool ArbolBinario<tipo>::surdo()
{
	bool esSurdo = true;

	this->surdo( this->raiz, esSurdo );

	return( esSurdo );
}

/*****************************************************************************************************************
***********************************************PROTECTED**********************************************************
*****************************************************************************************************************/

template <class tipo>
void ArbolBinario<tipo>::preorden( NodoA<tipo>* nodoActual, list<tipo> &listaRecorrido )
{
	//colocamos el dato actual en la lista
	listaRecorrido.push_back( nodoActual->obtenerDato() );
	
	//buscamos en el hijo izquierdo
	if ( nodoActual->obtenerHijoIzquierdo() != NULL )
	{
		this->preorden( nodoActual->obtenerHijoIzquierdo(), listaRecorrido );
	}

	//buscamos en el hijo derecho
	if ( nodoActual->obtenerHijoDerecho() != NULL )
	{
		this->preorden( nodoActual->obtenerHijoDerecho(), listaRecorrido );
	}
}

template <class tipo>
void ArbolBinario<tipo>::postorden( NodoA<tipo>* nodoActual, list<tipo> &listaRecorrido )
{
	//buscamos en el hijo izquierdo
	if ( nodoActual->obtenerHijoIzquierdo() != NULL )
	{
		this->postorden( nodoActual->obtenerHijoIzquierdo(), listaRecorrido );
	}

	//buscamos en el hijo derecho
	if ( nodoActual->obtenerHijoDerecho() != NULL )
	{
		this->postorden( nodoActual->obtenerHijoDerecho(), listaRecorrido );
	}
	
	//colocamos el dato actual en la lista
	listaRecorrido.push_back( nodoActual->obtenerDato() );
}

template <class tipo>
void ArbolBinario<tipo>::inorden( NodoA<tipo>* nodoActual, list<tipo> &listaRecorrido )
{
	//buscamos en el hijo izquierdo
	if ( nodoActual->obtenerHijoIzquierdo() != NULL )
	{
		this->inorden( nodoActual->obtenerHijoIzquierdo(), listaRecorrido );
	}

	//colocamos el dato actual en la lista
	listaRecorrido.push_back( nodoActual->obtenerDato() );

	//buscamos en el hijo derecho
	if ( nodoActual->obtenerHijoDerecho() != NULL )
	{
		this->inorden( nodoActual->obtenerHijoDerecho(), listaRecorrido );
	}
}

template <class tipo>
void ArbolBinario<tipo>::vaciar( NodoA<tipo>* nodoActual )
{
	//se eliminan los nodos izquierdos
	if ( nodoActual->obtenerHijoIzquierdo() != NULL )
	{
		this->vaciar( nodoActual->obtenerHijoIzquierdo() );
	}

	//se eliminan los nodos derechos
	if ( nodoActual->obtenerHijoDerecho() != NULL )
	{
		this->vaciar( nodoActual->obtenerHijoDerecho() );
	}

	//se elimina el nodo actual
	delete nodoActual;
}

template <class tipo>
NodoA<tipo>* ArbolBinario<tipo>::copiar( NodoA<tipo>* nodoActual )
{
	NodoA<tipo>* instanciaRaiz;

	//inicializamos el nodo en nulo
	instanciaRaiz = NULL;

	//si el nodo no es nulo lo copiamos
	if ( nodoActual != NULL )
	{
		//se reserva memoria y se copian los nodos hijos
		instanciaRaiz = new NodoA<tipo>( nodoActual->obtenerDato(), this->copiar( nodoActual->obtenerHijoIzquierdo()), this->copiar( nodoActual->obtenerHijoDerecho() ) );
	}
	
	//se retorna el resultados de la copia
	return( instanciaRaiz );
}

template <class tipo>
void ArbolBinario<tipo>::altura( NodoA<tipo>* nodoActual, int alturaActual, int &alturaMayor )
{
	if ( nodoActual != NULL )
	{
		//comprobamos si la altura actual es mayor a la mayor altura
		if ( alturaActual > alturaMayor )
		{
			alturaMayor = alturaActual;
		}
		
		//buscamos la altura del hijo izquierdo
		this->altura( nodoActual->obtenerHijoIzquierdo(), alturaActual+1, alturaMayor );

		//buscamos la altura del hijo derecho
		this->altura( nodoActual->obtenerHijoDerecho(), alturaActual+1, alturaMayor );
	}
} 

template <class tipo>
void ArbolBinario<tipo>::diametro( NodoA<tipo>* nodoActual, int &diametroMayor )
{
	if ( nodoActual != NULL )
	{
		int alturaIzquierda = -1;
		int alturaDerecha = -1;

		//buscamos la altura del lado izquierdo
		this->altura( nodoActual->obtenerHijoIzquierdo(), 0, alturaIzquierda );

		//buscamos la altura del lado derecho
		this->altura( nodoActual->obtenerHijoDerecho(), 0, alturaDerecha );

		//comprobamos si el diametro actual es el mayor de los diametros
		alturaIzquierda += alturaDerecha + 2;
		if ( alturaIzquierda > diametroMayor )
		{
			diametroMayor = alturaIzquierda;
		}

		//buscamos si no hay mayores diamtros en el hijo izquierdo
		this->diametro( nodoActual->obtenerHijoIzquierdo(), diametroMayor );

		//buscamos si no hay mayores diamtros en el hijo derecho
		this->diametro( nodoActual->obtenerHijoDerecho(), diametroMayor );
	}
	
}

template <class tipo>
NodoA<tipo>* ArbolBinario<tipo>::crearPreordenInorden( list<tipo> &preorden, list<tipo> &inorden )
{
	//inicializamos el nodo en nulo
	NodoA<tipo>* nodoRaiz = NULL;

	//lista que almacena el lado izquierdo del recorrido inorden
	list<tipo> inordenIzquierda;

	//se comprueba que las listas no esten vacias 
	if ( !preorden.empty() && !inorden.empty() )
	{
		//separamos el recorrido inorden a partir del recorrido preorden
		while ( preorden.front() != inorden.front() )
		{
			//insertamos el frente del recorrido inorden al recorrido izquierdo
			inordenIzquierda.push_back( inorden.front() );

			//eliminamos el elemento del recorrido de la derecha
			inorden.pop_front();
		}

		//creamos la raiz con el primer elemento deñ recorrido preorden
		nodoRaiz = new NodoA<tipo>( preorden.front() );

		//eliminamos el elemento recien creado de los recorridos
		preorden.pop_front();

		inorden.pop_front();

		//contruimos el lado izquierdo del arbol
		nodoRaiz->modificarHijoIzquierdo( this->crearPreordenInorden( preorden, inordenIzquierda ) );

		//construimos el lado derecho del arbol
		nodoRaiz->modificarHijoDerecho( this->crearPreordenInorden( preorden, inorden ) );
	}
	
	return( nodoRaiz );
}

template <class tipo>
NodoA<tipo>* ArbolBinario<tipo>::crearPostordenInorden( list<tipo> &postorden, list<tipo> &inorden )
{
	//inicializamos el nodo en nulo
	NodoA<tipo>* nodoRaiz = NULL;

	//lista que almacena el lado izquierdo del recorrido inorden
	list<tipo> inordenIzquierda;

	//se comprueba que las listas no esten vacias 
	if ( !postorden.empty() && !inorden.empty() )
	{
		//separamos el recorrido inorden a partir del recorrido postorden
		while ( postorden.back() != inorden.front() )
		{
			//insertamos el frente del recorrido inorden al recorrido izquierdo
			inordenIzquierda.push_back( inorden.front() );

			//eliminamos el elemento del recorrido de la derecha
			inorden.pop_front();
		}

		//creamos la raiz con el ultimo elemento del recorrido postorden
		nodoRaiz = new NodoA<tipo>( postorden.back() );

		//eliminamos el elemento recien creado de los recorridos
		postorden.pop_back();

		inorden.pop_front();

		//contruimos el lado derecho del arbol
		nodoRaiz->modificarHijoDerecho( this->crearPostordenInorden( postorden, inorden ) );
		
		//construimos el lado izquierdo del arbol
		nodoRaiz->modificarHijoIzquierdo( this->crearPostordenInorden( postorden, inordenIzquierda ) );
	}
	
	return( nodoRaiz );
}

template <class tipo>
void ArbolBinario<tipo>::insertarIzquierdo( NodoA<tipo>* nodoActual, tipo nuevoDato, tipo padre, bool &insertado )
{
	//verificamos si el dato no ha sido insertado
	if ( !insertado && nodoActual != NULL )
	{
		//verificamos si el nodo actual es el padre buscado
		if ( nodoActual->obtenerDato() == padre )
		{
			//insertamos el nuevo elemento en su hijo izquierdo
			nodoActual->modificarHijoIzquierdo( new NodoA<tipo>( nuevoDato ) );

			//colocamos la bandera insertado en true
			insertado = true;
		}
		else
		{
			//buscamos el padre en el hijo izquierdo
			this->insertarIzquierdo( nodoActual->obtenerHijoIzquierdo(), nuevoDato, padre, insertado );

			//buscamos el padre en el hijo derecho
			this->insertarIzquierdo( nodoActual->obtenerHijoDerecho(), nuevoDato, padre, insertado );
		}
	}
}

template <class tipo>
void ArbolBinario<tipo>::insertarDerecho( NodoA<tipo>* nodoActual, tipo nuevoDato, tipo padre, bool &insertado )
{
	//verificamos si el dato no ha sido insertado
	if ( !insertado && nodoActual != NULL )
	{
		//verificamos si el nodo actual es el padre buscado
		if ( nodoActual->obtenerDato() == padre )
		{
			//insertamos el nuevo elemento en su hijo derecho
			nodoActual->modificarHijoDerecho( new NodoA<tipo>( nuevoDato ) );

			//colocamos la bandera insertado en true
			insertado = true;
		}
		else
		{
			//buscamos el padre en el hijo izquierdo
			this->insertarDerecho( nodoActual->obtenerHijoIzquierdo(), nuevoDato, padre, insertado );

			//buscamos el padre en el hijo derecho
			this->insertarDerecho( nodoActual->obtenerHijoDerecho(), nuevoDato, padre, insertado );
		}
	}
}

template <class tipo>
int ArbolBinario<tipo>::peso( NodoA<tipo>* nodoActual )
{
	int resultado = 0;

	if ( nodoActual != NULL )
	{
		//si el nodo no es nulo colocamos el contador en 1
		resultado = 1;

		//contamos los nodos del lado izquierdo
		resultado += this->peso( nodoActual->obtenerHijoIzquierdo() );

		//contamos los nodos del lado derecho
		resultado += this->peso( nodoActual->obtenerHijoDerecho() );
	}

	return( resultado );
}

template <class tipo>
void ArbolBinario<tipo>::completo( NodoA<tipo>* nodoActual, bool &completo )
{
	if ( completo && !nodoActual->esHoja() )
	{
		//se comprueba que nodo sea competo
		if ( nodoActual->obtenerHijoIzquierdo() != NULL && nodoActual->obtenerHijoDerecho() != NULL )
		{
			//se compreuba el hijo izquierdo
			this->completo( nodoActual->obtenerHijoIzquierdo(), completo );

			//se comprueba el hijo derecho
			this->completo( nodoActual->obtenerHijoDerecho(), completo );
		}
		else
		{
			//si el nodo no es completo se coloca la bandera en falso
			completo = false;
		}
	}
}

template <class tipo>
void ArbolBinario<tipo>::lleno( NodoA<tipo>* nodoActual, int alturaActual, int altura, bool &lleno )
{
	if ( lleno )
	{
		if ( !nodoActual->esHoja() )
		{
			//se comprueba que nodo sea competo
			if ( nodoActual->obtenerHijoIzquierdo() != NULL && nodoActual->obtenerHijoDerecho() != NULL )
			{
				//se compreuba el hijo izquierdo
				this->lleno( nodoActual->obtenerHijoIzquierdo(), alturaActual+1, altura, lleno );

				//se comprueba el hijo derecho
				this->lleno( nodoActual->obtenerHijoDerecho(), alturaActual+1, altura, lleno );
			}
			else
			{
				//si el nodo no es completo se coloca la bandera en falso
				lleno = false;
			}
		}
		else
		{
			//si la altura es diferente se coloca la bandera en falso
			if ( alturaActual != altura )
			{
				lleno = false;
			}
		}
	}
}

template <class tipo>
void ArbolBinario<tipo>::iguales( NodoA<tipo>* nodo1, NodoA<tipo>* nodo2, bool &iguales )
{
	if ( iguales )
	{
		if ( nodo1 != NULL && nodo2 != NULL )
		{
			//se compra la raiz
			iguales = nodo1->obtenerDato() == nodo2->obtenerDato();

			//se verifica el hijo izquierdo
			this->iguales( nodo1->obtenerHijoIzquierdo(), nodo2->obtenerHijoIzquierdo(), iguales );

			//se varifica el hijo derecho
			this->iguales( nodo1->obtenerHijoDerecho(), nodo2->obtenerHijoDerecho(), iguales );
		}
		else
		{
			//se verifica si los dos nodos son nulos
			if ( nodo1 != NULL || nodo2 != NULL )
			{
				//si algunos de los dos nodos no son nulos se coloca la bandera en falso
				iguales = false;
			}
		}
	}
}

template <class tipo>
void ArbolBinario<tipo>::isomorfo( NodoA<tipo>* nodo1, NodoA<tipo>* nodo2, bool &isomorfo )
{
	if ( isomorfo )
	{
		if ( nodo1 != NULL && nodo2 != NULL )
		{
			//se verifica el hijo izquierdo
			this->isomorfo( nodo1->obtenerHijoIzquierdo(), nodo2->obtenerHijoIzquierdo(), isomorfo );

			//se varifica el hijo derecho
			this->isomorfo( nodo1->obtenerHijoDerecho(), nodo2->obtenerHijoDerecho(), isomorfo );
		}
		else
		{
			//se verifica si los dos nodos son nulos
			if ( nodo1 != NULL || nodo2 != NULL )
			{
				//si algunos de los dos nodos no son nulos se coloca la bandera en falso
				isomorfo = false;
			}
		}
	}
}

template <class tipo>
bool ArbolBinario<tipo>::compararRecorrido( list<tipo> recorrido1, list<tipo> recorrido2 )
{
	bool respuesta = true;

	//se ordenan los recorridos
	recorrido1.sort();
	recorrido2.sort();

	//se verifica que tengan el mismo tamaño
	if ( recorrido1.size() == recorrido2.size() )
	{
		//se comprueba que tengan sus elemento iguales
		while( respuesta && !recorrido1.empty() && !recorrido2.empty() )
		{
			if ( recorrido1.front() != recorrido2.front() )
			{
				//si hay un elemento diferente se coloca la bandera en falso
				respuesta = false;
			}

			//nos movemos al siguiente elemento
			recorrido1.pop_front();
			recorrido2.pop_front();
		}
	}
	else
	{
		//si no tienen la misma longitud se coloca la bandera en falso
		respuesta = false;
	}
	

	return( respuesta );
}

template <class tipo>
double ArbolBinario<tipo>::resolverArbolSintaxis( NodoA<tipo> *nodoActual )
{
	double resultado;
	if( !nodoActual->esHoja() )
	{
		double valorIzquierdo, valorDerecho;
		//cout << nodoActual->obtenerDato()<<endl;
		valorIzquierdo = this->resolverArbolSintaxis( nodoActual->obtenerHijoIzquierdo() );
		
		valorDerecho = this->resolverArbolSintaxis( nodoActual->obtenerHijoDerecho() );
		//cout<<"-> "<<valorDerecho<<" -> "<<valorIzquierdo<<endl;
		resultado = operador( valorIzquierdo, valorDerecho, nodoActual->obtenerDato() );
		//cout<<"resultado "<<resultado<<endl;
	}
	else
	{
		char dato = nodoActual->obtenerDato();
		resultado = (int)dato - 48;
	}
	return( resultado );
}

template <class tipo>
double ArbolBinario<tipo>::operador( double valor1, double valor2, tipo signo )
{
	double resultado;
	switch( signo )
	{
		case '+':
			resultado = valor1 + valor2;
			break;
		case '-':
			resultado = valor1 - valor2;
			break;
		case '*':
			resultado = valor1 * valor2;
			break;
		case '/':
			resultado = valor1 / valor2;
			break;
	}
	return( resultado );
}

template <class tipo>
void ArbolBinario<tipo>::surdo( NodoA<tipo>* nodoActual, bool &esSurdo )
{
	if ( esSurdo && nodoActual != NULL )
	{
		int alturaIzquierda = -1;
		int alturaDerecha = -1;

		//nos desplamos hata el ultimo hijo izquierdo
		this->surdo( nodoActual->obtenerHijoIzquierdo(), esSurdo );

		//nos desplazamos hasta el ultimo hijo derecho
		this->surdo( nodoActual->obtenerHijoDerecho(), esSurdo );

		//obtenos la altura izquierda
		this->altura( nodoActual->obtenerHijoIzquierdo(), 0, alturaIzquierda );

		//obtenemos la altura derecha
		this->altura( nodoActual->obtenerHijoDerecho(), 0, alturaDerecha );

		//si la altura derecha es mayor a la izquierda se coloca la bandera en falso
		if ( alturaIzquierda < alturaDerecha )
		{
			esSurdo = false; 
		}
	}
}

#endif
