#ifndef _tavlcalendario
#define _tavlcalendario
#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

using namespace std;

class TNodoAVL;

class TAVLCalendario {
	friend ostream & operator<<(ostream &os, const TAVLCalendario &v);

	private: 
		TNodoAVL *raiz;

		void InordenAux(TVectorCalendario &v, int &o) const;
		void PostordenAux(TVectorCalendario &v, int &o) const;
		void PreordenAux(TVectorCalendario &v, int &o) const;
		
		TCalendario Auxiliar() const;

		void II(); 
		void ID(); 
		void DD(); 
		void DI();
		
		bool Insertar(const TCalendario &c, bool &crece);
		bool Borrar(const TCalendario &c, bool &decrece);

	public:
		TAVLCalendario();
		TAVLCalendario(const TAVLCalendario &v);
		~TAVLCalendario();
		void clear();
		TAVLCalendario &operator=(const TAVLCalendario &v);

		bool operator==(const TAVLCalendario &v) const;
		bool operator!=(const TAVLCalendario &v) const;
		bool EsVacio() const;
		bool Insertar(const TCalendario &c);
		bool Buscar(const TCalendario &c)const;
		bool Borrar(const TCalendario &c);
		TCalendario Raiz() const;

		int Altura() const;
		int Nodos() const;
		int NodosHoja() const;

		TVectorCalendario Inorden() const;
		TVectorCalendario Postorden() const;
		TVectorCalendario Preorden() const;
};

class TNodoAVL {
	friend class TAVLCalendario;

	private:
		TCalendario item;
		TAVLCalendario iz, de;
		int fe;

	public:
		TNodoAVL();
		TNodoAVL(const TNodoAVL &v);
		~TNodoAVL();
		TNodoAVL &operator=(const TNodoAVL &v);
};

#endif
