// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad12.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 15;
int main(void)
{
	int valores[kCalendarios] = {70, 30, 90 ,20, 50, 80, 10, 40, 60, 65, 100, 85, 95, 110, 115};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
//  double valores[kComplejos][2] = {{70, 70}, {30, 30}, {90, 90}, {20, 20}, {50, 50}, {80, 80}
//  					, {10, 10}, {40, 40}, {60, 60}, {65, 65}, {100, 100}, {85, 85}, {95, 95}, 
//					{110, 110}, {115, 115}};
	
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);
	cout << a.Inorden() << endl << a.Preorden() << endl;
  
	return 0;
}
