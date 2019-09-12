// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad09.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 9;
int main(void)
{
	int valores[kCalendarios] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
  //double valores[kComplejos][2] = {{90, 90}, {80, 80}, {70, 70}, {60, 60}, {50, 50}, {40, 40}
  //					, {30, 30}, {20, 20}, {10, 10}};

	
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Inorden() << endl << a.Preorden() << endl;


	return 0;
}
