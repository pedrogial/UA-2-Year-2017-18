// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad06.cc
// --------------------------------

// prueba DD norrrr.... - 2 niveles (6 nodos).
// jus jus...
#include <iostream>
#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 3;
int main(void)
{
	int valores[kCalendarios] = {30, 30, 10};
	int i;
	TCalendario calendarios[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
	{
		if(a.Insertar(calendarios[i]))
			cout << "insertado " << calendarios[i] << endl;
		else
			cout << "no insertado " << calendarios[i] << endl;
	}  
	cout << a.Inorden() << endl << a.Preorden() << endl;
  
  return 0;
}
