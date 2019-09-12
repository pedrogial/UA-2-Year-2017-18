// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad18.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 10;
int main(void)
{
	int valores[kCalendarios] = {3, 2, 8, 1, 5, 10, 4, 7, 9, 6};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
//  double valores[kComplejos][2] = {{3, 3}, {2, 2}, {8, 8}, {1, 1}, {5, 5}, {10, 10}, {4, 4}, {7, 7}, {9, 9}, {6, 6}};

	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);
  
	return 0;
}
