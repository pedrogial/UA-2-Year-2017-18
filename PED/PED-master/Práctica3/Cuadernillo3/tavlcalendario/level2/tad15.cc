// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad15.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 8;
int main(void)
{
	int valores[kCalendarios] = {40, 35, 47, 31, 45, 50, 43, 44};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 // double valores[kComplejos][2] = {{40, 40}, {35, 35}, {47, 47}, {31, 31}, {45, 45}, {50, 50}, {43, 43}, {44, 44}};

	
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);
	cout << a.Inorden() << endl << a.Preorden() << endl;
  
  return 0;
}
