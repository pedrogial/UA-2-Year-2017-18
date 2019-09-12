// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad03.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 30;
int main(void)
{
	TAVLCalendario a;
	int i, j;
	TCalendario calendarios[kCalendarios];
	
	i = 0;
	j = kCalendarios  - 1;

	while(i < j)
	{
		calendarios[i].ModFecha(1, 1, i + 2000);
		calendarios[j].ModFecha(1, 1, j + 2000);
		a.Insertar(calendarios[i]);
		a.Insertar(calendarios[j]);
		i++;
		j--;
	}
	
	cout << a.Inorden() << endl << a.Preorden() << endl;
 
  return 0;
}
