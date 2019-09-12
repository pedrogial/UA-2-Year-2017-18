// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba 2 -1 DI (mas grande)
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 13;
int main(void)
{
	int valores[kCalendarios] = {6, 3, 9, 2, 5, 8, 12, 1, 4, 7, 10, 13, 11};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[5]))
			cout << "Complejo borrado" << calendarios[5] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
