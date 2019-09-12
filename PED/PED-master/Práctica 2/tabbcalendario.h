#ifndef _tabbcalendario
#define _tabbcalendario
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

class TNodoABB;
class TABBCalendario
{
	private:
		TNodoABB *raiz;
		void InordenAux(TVectorCalendario &, int &) const;
		void PreordenAux(TVectorCalendario &, int &) const;
		void PostordenAux(TVectorCalendario &, int &) const;
		TCalendario BuscarMayor( ) const;
	public:
		TABBCalendario();
		TABBCalendario(const TABBCalendario &);
		~TABBCalendario();
		TABBCalendario &operator=(const TABBCalendario &);
		TVectorCalendario Inorden() const;
		TVectorCalendario Preorden() const;
		TVectorCalendario Postorden() const;
		int Nodos() const;
		int NodosHoja() const;
		int Altura() const;
		bool EsVacio() const;
		bool Buscar(const TCalendario &) const;
		bool Insertar(const TCalendario &);
		bool Borrar(const TCalendario &);
		TVectorCalendario Niveles() const;
		TABBCalendario operator+(const TABBCalendario &) const;
		TABBCalendario operator-(const TABBCalendario &) const;
		bool operator==(const TABBCalendario &de) const;

		int *BuscarLista(const TListaCalendario &de) const;
		int BuscarEnInorden(const TVectorCalendario &vc, const TCalendario &c) const;




/////////////////aqui
		TListaCalendario examen(const TListaCalendario &l) const;
		bool esCamino(const TListaCalendario &l) const;
		TListaCalendario listarNodos() const;

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
