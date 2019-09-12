// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad19.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 8;
int main(void)
{
	int valores[kCalendarios] = {3, 2, 7, 1, 4, 8, 6, 5};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
//  double valores[kComplejos][2] = {{3, 3}, {2, 2}, {7, 7}, {1, 1}, {4, 4}, {8, 8}, {6, 6}, {5, 5}};

	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);
	
	cout << a.Inorden() << endl << a.Preorden() << endl;

	return 0;
}
