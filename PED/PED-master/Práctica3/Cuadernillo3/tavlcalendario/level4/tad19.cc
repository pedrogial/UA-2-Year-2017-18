// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 20;
int main(void)
{
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, i + 1 + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);


	for(int i = 19; i >= 0; i--)
	{
		a.Borrar(calendarios[i]);
		cout << "Complejo borrado: " << calendarios[i] << endl;
		cout << "niveles: " << a.Niveles() << endl;
		cout << "inorden: " << a.Inorden() << endl;
	}
	
	return 0;
}
