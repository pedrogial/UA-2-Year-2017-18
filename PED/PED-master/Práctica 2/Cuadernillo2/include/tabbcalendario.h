#ifndef _tabbcalendario
#define _tabbcalendario
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

class TNodoABB;

class TABBCalendario
{
	friend ostream & operator<<(ostream &os, TABBCalendario &abb);
	private:
		TNodoABB *raiz;
		void InordenAux(TVectorCalendario &, int &) const;
		void PreordenAux(TVectorCalendario &, int &) const;
		void PostordenAux(TVectorCalendario &, int &) const;
		TCalendario BuscarMayor() const;

	public:
		TABBCalendario();
		TABBCalendario(const TABBCalendario &);
		~TABBCalendario();
		void clear();
		TABBCalendario &operator=(const TABBCalendario &);

		bool operator==(const TABBCalendario &de) const;
		bool EsVacio() const;
		bool Insertar(const TCalendario &);
		bool Borrar(const TCalendario &);

		bool Buscar(const TCalendario &) const;
		TCalendario Raiz() const;
		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;

		TVectorCalendario Inorden() const;
		TVectorCalendario Preorden() const;
		TVectorCalendario Postorden() const;
		
		TVectorCalendario Niveles() const;
		TABBCalendario operator+(const TABBCalendario &) const;
		TABBCalendario operator-(const TABBCalendario &) const;

};

class TNodoABB
{
	friend class TABBCalendario;
	private:
		TABBCalendario iz, de;
		TCalendario item;
	public:
		TNodoABB();
		TNodoABB(const TNodoABB &);
		~TNodoABB();
		TNodoABB &operator=(const TNodoABB &);
};

#endif
