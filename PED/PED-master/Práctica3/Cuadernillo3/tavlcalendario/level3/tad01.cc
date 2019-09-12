// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad01.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;

// DD a tuti plen
// 100 calenarios de 2000 a 2099.

const int kCalendarios = 100;
int main(void)
{
	TAVLCalendario a;
	int i;
	TCalendario calendarios[kCalendarios];

	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, 2000 + i); 

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Inorden() << endl << endl << endl << a.Preorden() << endl;

	return 0;
}
