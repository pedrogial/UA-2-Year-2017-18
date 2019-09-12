// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba 2 borrados de un nodo con dos hijos,
// el ultimo borrado provoca un DD. 2 1 basico.
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 5;
int main(void)
{
	int valores[kCalendarios] = {3, 2, 4, 1, 5};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	if(a.Borrar(calendarios[0]))
			cout << "Complejo borrado" << calendarios[0] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	if(a.Borrar(calendarios[1]))
			cout << "Complejo borrado" << calendarios[1] << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
