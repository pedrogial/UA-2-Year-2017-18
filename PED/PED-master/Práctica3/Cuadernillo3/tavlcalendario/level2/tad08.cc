// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad08.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 10;
int main(void)
{
	int valores[kCalendarios] = {70, 40, 90, 20, 50, 80, 10, 30, 60, 4};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
  //double valores[kComplejos][2] = {{70, 70}, {40, 40}, {90, 90}, {20, 20}, {50, 50}, {80, 80}
  //					, {10, 10}, {30, 30}, {60, 60}, {4, 4}};

	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Inorden() << endl << a.Preorden() << endl;

	return 0;
}
