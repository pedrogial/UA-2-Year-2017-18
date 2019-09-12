#ifndef __TCalendario
#define __TCalendario

#include<iostream>
using namespace std;

class TCalendario
{
friend ostream &operator << (ostream &o,const TCalendario &calendario);
	private:
		int anyo;
		int mes;
		int dia;
		char *mensaje;
	public:
		///Constructor por defecto de la clase TCalendario
		TCalendario();
		///Constructor parametrizado de la clase TCalendario
		TCalendario(int dia, int mes, int anyo,char *mens);
		///Destructor de TCalendario
		~TCalendario();
		///Constructor copia de la clase TCalendario
		TCalendario(const TCalendario &calendario);
		///Incrementamos en uno el numero de dias (PREINCREMENTO)
		TCalendario &operator ++();
		///Incrementamos en uno el numero de días (POSTINCREMENTO)
		TCalendario operator ++ (int fecha);
		///Desincremento en uno el numero de dias (PREINCREMENTO)
		TCalendario &operator --();
		///Desincremento en uno el numero de dias (PREINCREMENTO)
		TCalendario operator --(int fecha);
		///Sumas un entero "fecha" de días al calendario actual
		TCalendario operator +(int fecha);
		///Restas un entero "fecha" de días al calendario actual
		TCalendario operator -(int fecha);
		///Modificamos la fecha del TCalendario, con los parametros pasados. 
		bool ModFecha (int dia, int mes, int anyo);
		///Modificamos el mensaje.
		bool ModMensaje (char *mens);
		///Sobrecarga del operador == que compara dos calendarios siguiendo el criterio expuesto en el cuadernillo 1
		bool operator  ==(const TCalendario &calendario)const;
		bool operator!=(const TCalendario &de) const;
		///Sobrecarga del operador >
		bool operator > (const TCalendario &calendario) const;
		///Sobrecarga del operador <
		bool operator < (const TCalendario &calendario) const;
		///Cumprueba si el calendario es el por Defecto (Si EsFecha() y su mensaje esta a NULL)
		bool EsVacio() const;
		///Devuelve el día del calendario actual
		int Dia() const;
		///Devuelve el mes del calendario actual
		int Mes() const;
		///Devuelve el Anyo del calendario actual
		int Anyo() const;
		///Devuelve el mensaje del calendario actual
		char *Mensaje() const;
		///Sobrecarga del operador asignación para poder igualar TCalendarios
		TCalendario &operator=(const TCalendario &c);
		///Comprueba si es una Fecha Valida.
		bool EsFecha() const;
};

#endif
