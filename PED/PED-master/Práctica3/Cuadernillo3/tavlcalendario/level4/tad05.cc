// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: borrado solo hijo izquierdo

#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 7;
int main(void)
{
	int valores[kCalendarios] = {3, 2, 6, 1, 5, 7, 4};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[4]))
		cout << "Complejo borrado" << calendarios[4] <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	return 0;
}
