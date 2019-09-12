// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad17.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 6;
int main(void)
{
	int valores[kCalendarios] = {2, 1, 5, 4, 6, 3};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
  //double valores[kComplejos][2] = {{2, 2}, {1, 1}, {5, 5}, {4, 4}, {6, 6}, {3, 3}};
  
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);
	cout << a.Inorden() << endl << a.Preorden() << endl;
  
  return 0;
}
