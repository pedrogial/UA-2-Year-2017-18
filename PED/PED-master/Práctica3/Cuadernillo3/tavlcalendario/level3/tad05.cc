// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad05.cc
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
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);

	cout << a.Inorden() << endl << a.Preorden() << endl;
  	
	TAVLCalendario b(a), c;
	
	c = b;
	if(b == c)
		cout << "una copia y una asignacion del mismo arbol son iguales" << endl;
	else
		cout << "casi...!!!" << endl;

	if(b.Buscar(calendarios[3]))
		cout << "encontrado con un par" << endl;
	else
		cout << "ay ay ayyyyyy" << endl;

	if(b.Buscar(calendarios[9] + 10))
		cout << "ya me diras como lo has encontrao si no esta" << endl;
	else
		cout << "no encontrado " << calendarios[9] + 10 << endl;


	return 0;
}
