// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------
 
// prueba: prueba ID + II (solo un borrado -> dos rotaciones)
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 12;
int main(void)
{
	int valores[kCalendarios] = {8, 5, 11, 2, 7, 9, 12, 1, 4, 6, 10, 3};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[6]))
			cout << "Complejo borrado" << calendarios[6] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
