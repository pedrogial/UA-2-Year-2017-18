// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba -2 0 II (mas grande)
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 8;
int main(void)
{
	int valores[kCalendarios] = {6, 3, 7, 1, 5, 8, 2, 4};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[2]))
			cout << "Complejo borrado" << calendarios[2] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
