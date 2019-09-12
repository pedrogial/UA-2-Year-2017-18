// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 3;
int main(void)
{
	int valores[kCalendarios] = {2, 1, 3};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[1]))
		cout << "Complejo borrado" << calendarios[1] <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;

	if(a.Borrar(calendarios[0]))
		cout << "Complejo borrado" << calendarios[0] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;

	if(a.Borrar(calendarios[2]))
		cout << "Complejo borrado" << calendarios[2] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
		

	return 0;
}
