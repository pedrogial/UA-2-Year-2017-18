// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// siempre borra un nodo intermedio

#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 9;
int main(void)
{
	int valores[kCalendarios] = {5, 2, 8, 1, 4, 6, 9, 3, 7};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;

	a.Borrar(calendarios[0]);
	cout << "Resultado Borrar 2005: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[4]);
	cout << "Resultado Borrar 2004: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[7]);
	cout << "Resultado Borrar 2003: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[5]);
	cout << "Resultado Borrar 2006: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[1]);
	cout << "Resultado Borrar 2002: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[2]);
	cout << "Resultado Borrar 2008: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[8]);
	cout << "Resultado Borrar 2007: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[3]);
	cout << "Resultado Borrar 2001: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(calendarios[6]);
	cout << "Resultado Borrar 2009: " << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;

	return 0;
}
