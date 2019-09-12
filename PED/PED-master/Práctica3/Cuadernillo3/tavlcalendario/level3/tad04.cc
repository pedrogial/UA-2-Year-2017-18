// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad04.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 10;
int main(void)
{
	int valores[kCalendarios] = {70, 30, 90, 20, 50, 80, 10, 40, 60, 35};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Inorden() << endl << a.Preorden() << endl;
	cout << "altura: " << a.Altura() << endl;
	cout << "nodos hoja: " << a.NodosHoja() << endl;
	cout << "nodos: " << a.Nodos() << endl;
  
	return 0;
}
