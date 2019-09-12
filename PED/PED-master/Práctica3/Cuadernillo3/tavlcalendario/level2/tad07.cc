// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad07.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;


const int kCalendarios = 6;
int main(void)
{
	int valores[kCalendarios] = {50, 30, 60, 10, 40, 20};
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
