// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad04.cc
// --------------------------------

// prueba 2 x DD - caso simple (3 nodos) en la raiz y en subarbol
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 5;
int main(void)
{
	int valores[kCalendarios] = {10, 20, 30, 40, 50};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;

	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Inorden() << endl << a.Preorden() << endl;

	return 0;
}
