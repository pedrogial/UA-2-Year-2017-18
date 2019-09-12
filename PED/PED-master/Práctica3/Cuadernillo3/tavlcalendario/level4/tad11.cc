// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba +2 0 DD
#include <iostream>
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 4;
int main(void)
{
	int valores[kCalendarios] = {2, 1, 3, 4};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[1]))
			cout << "Complejo borrado" << calendarios[1] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
