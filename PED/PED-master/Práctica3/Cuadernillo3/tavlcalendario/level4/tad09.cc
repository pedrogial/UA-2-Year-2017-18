// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------


#include <iostream>
#include "tavlcalendario.h"
using namespace std;

const int kCalendarios = 5;
int main(void)
{
	int valores[kCalendarios] = {4, 1, 6, 2, 5};
	int vb[kCalendarios] = {1, 6, 2, 5, 4};
	TCalendario noEsta(1, 1, 2003, NULL);
	int i;
	TCalendario calendarios[kCalendarios];
	TCalendario calendariosBorrar[kCalendarios];
	TAVLCalendario a;
 
	for(i = 0; i < kCalendarios; i++)
		calendarios[i].ModFecha(1, 1, valores[i] + 2000);

	for(i = 0; i < kCalendarios; i++)
		calendariosBorrar[i].ModFecha(1, 1, vb[i] + 2000);


	for(i = 0; i < kCalendarios; i++)
		a.Insertar(calendarios[i]);


	if(a.Borrar(noEsta))
		cout << "que lastimica que borres cosas que no estan!!" <<  endl;
	
	for(int i = 0; i < 5; i++)
	{
		if(a.Borrar(calendariosBorrar[i]))
			cout << "Complejo borrado" << calendariosBorrar[i] << endl;
		cout << "niveles: " << a.Niveles() << endl;
		cout << "inorden: " << a.Inorden() << endl;
	}
	return 0;
}
