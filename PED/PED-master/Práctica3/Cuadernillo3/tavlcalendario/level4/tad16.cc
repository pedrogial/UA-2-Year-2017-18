// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba DI + DI (solo un borrado -> dos rotaciones)
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 12;
int main(void)
{
	int valores[kCalendarios] = {5, 2, 10, 1, 4, 7, 12, 3, 6, 9, 11, 8};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[3]))
			cout << "Complejo borrado" << calendarios[3] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
