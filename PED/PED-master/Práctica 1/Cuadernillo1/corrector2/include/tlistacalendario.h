#ifndef tlistacalendario_h_
#define tlistacalendario_h_

#include <iostream>
#include "tcalendario.h"


using namespace std;


class TListaPos;
class TNodoCalendario;
/** 
 * \brief Clase TListaCalendario
 *
 * Clase que contiene la variables privadas de tlistacalendario
 * y métodos publicos para poder trabajar con la lista de calendarios
 */
class TListaCalendario{
	
	
	friend ostream & operator<<(ostream &o, const TListaCalendario &l);

	private:
		/** \brief variable *primero
		*
		* Variable private de tipo TNodoCalendario
		*/
		TNodoCalendario *primero;

	public:	
		TListaCalendario();
		TListaCalendario(const TListaCalendario &);	
		~TListaCalendario();
		TListaCalendario & operator=(const TListaCalendario &);	
		TListaCalendario operator +(const TListaCalendario &) const;
		TListaCalendario operator -(const TListaCalendario &) const;
		bool  operator==(const TListaCalendario &de) const;
		bool Insertar(const TCalendario &);
		bool Borrar( const TCalendario &);
		bool Borrar(const TListaPos &);
		bool Borrar(int dia, int mes , int anyo);	
		bool EsVacia() const;
		TCalendario Obtener(const TListaPos &) const;
		bool Buscar(const TCalendario &) const;
		int Longitud() const;
		TListaPos Primera() const;
		TListaPos Ultima() const;
		TListaCalendario ExtraerRango(int , int );
		TListaCalendario SumarSubl(int I_L1, int F_L1, const TListaCalendario &l2, int I_L2, int F_L2) const;

};


/** \brief Clase TNodoCalendario
 * Clase que contiene la variables privadas de tpilacalendario
 * y métodos publicos para poder trabajar con la pila de tcalendario
 */
class TNodoCalendario{

	friend ostream & operator<<(ostream &o, const TListaCalendario &cal); 
	friend class TListaPos;
	friend class TListaCalendario;
	

	private:
		/** \brief variable c
		*
		* Variable del tipo calendario
		*/
		TCalendario c;
		/** \brief variable siguiente
		*
		* Variable del tipo tnodocalendario
		*/
		TNodoCalendario *siguiente;

	public:
		
		TNodoCalendario();
		TNodoCalendario(const TNodoCalendario &cal);
		~TNodoCalendario();
		TNodoCalendario &operator=(const TNodoCalendario &cal);
};



/** \brief Clase TListaPos
 * Clase que contiene la variables privadas de tlistapos
 * y métodos publicos para poder trabajar con la lista de calendarios
 */
class TListaPos{
	
	friend class TListaCalendario; 
	friend class TNodoCalendario;

	private:
		/** \brief variable pos
		*
		* Variable private de tipo TNodoCalendario
		*/
		TNodoCalendario *pos;

	public:
	
		
		TListaPos();
		TListaPos(const TListaPos &p);
		~TListaPos();
		TListaPos &operator= (const TListaPos &p);
		TListaPos Siguiente() const;
		bool EsVacia() const;
		bool operator== (const TListaPos &p) const;
};


#endif

