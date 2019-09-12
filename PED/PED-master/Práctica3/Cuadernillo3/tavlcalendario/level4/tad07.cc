// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: borrado hoja no decrece altura del subarbol 3

#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 8;
int main(void)
{
	int valores[kCalendarios] = {6, 3, 8, 2, 5, 9, 1, 4};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);


	if(a.Borrar(calendarios[6]))
		cout << "Complejo borrado: " << (calendarios[6]) <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	a.Insertar(calendarios[6]);
	cout << "Complejo insertado: " << calendarios[6] << endl;
	if(a.Borrar(calendarios[7]))
		cout << "Complejo borrado: " << calendarios[7] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
