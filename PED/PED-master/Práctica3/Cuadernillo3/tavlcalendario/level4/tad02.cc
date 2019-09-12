// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// level4: tad02.cc
// ------------------------

// Prueba: niveles del avl, todos los posibles nodos.

#include <iostream>
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 10;
int main(void)
{
	int valores[kCalendarios] = {6, 3, 9, 1, 5, 8, 10, 2, 4, 7};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Niveles() << endl;
	return 0;
}
