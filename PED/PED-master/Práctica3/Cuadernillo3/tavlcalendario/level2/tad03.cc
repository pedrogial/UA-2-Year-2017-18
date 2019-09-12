// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad03.cc
// --------------------------------

// prueba DD - 3 niveles (10 nodos).
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 10;
int main(void)
{
	int valores[kCalendarios] = {30, 20, 60, 10, 50, 90, 40, 80, 100, 70};
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
