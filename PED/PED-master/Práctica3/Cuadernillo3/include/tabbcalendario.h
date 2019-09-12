#ifndef _tabbcalendario
#define _tabbcalendario
#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

using namespace std;

class TNodoABB;

class TABBCalendario {
	friend ostream & operator<<(ostream &os, TABBCalendario &abb);

	private:
		TNodoABB *raiz;

		TCalendario Auxiliar() const;

		void InordenAux(TVectorCalendario &v, int &p) const;
		void PreordenAux(TVectorCalendario &v, int &p) const;
		void PostordenAux(TVectorCalendario &v, int &p) const;

	public:
		TABBCalendario();
		TABBCalendario(const TABBCalendario &o);
		~TABBCalendario();
		void clear();
		TABBCalendario &operator=(const TABBCalendario &o);

		bool operator==(const TABBCalendario &de) const;
		bool EsVacio() const;
		bool Insertar(const TCalendario &o);
		bool Borrar(const TCalendario &o);

		bool Buscar(const TCalendario &o) const;
		TCalendario Raiz() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;

		TVectorCalendario Inorden() const;
		TVectorCalendario Preorden() const;
		TVectorCalendario Postorden() const;
		
		TVectorCalendario Niveles() const;
		TABBCalendario operator+(const TABBCalendario &o) const;
		TABBCalendario operator-(const TABBCalendario &o) const;

};

class TNodoABB {
	friend class TABBCalendario;

	private:
		TABBCalendario iz, de;
		TCalendario item;
	public:
		TNodoABB();
		TNodoABB(const TNodoABB &o);
		~TNodoABB();
		TNodoABB &operator=(const TNodoABB &o);
};

#endif
