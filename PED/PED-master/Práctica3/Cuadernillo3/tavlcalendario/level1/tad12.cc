// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad11.cc
// --------------------------------

#include <iostream>
#include "tcalendario.h"
#include "tavlcalendario.h"
using namespace std;

int main()
{
	TCalendario 	c1(1, 1, 2010, NULL), 
			c2(1, 1, 2020, NULL), 
			c3(1, 1, 2030, NULL), 
			c4(1, 1, 2040, NULL), 
			c5(1, 1, 2050, NULL);
	TCalendario cx(1, 1, 2012, NULL);

	TAVLCalendario a;
	a.Insertar(c4);
	a.Insertar(c5);   
	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
  
	TAVLCalendario b;
	b.Insertar(c4);
	b.Insertar(c5); 
	b.Insertar(c2);
	b.Insertar(c1);
	b.Insertar(c3);
  
	TAVLCalendario c(a);
	TAVLCalendario d;
	d = b;
	a.~TAVLCalendario();
	b.~TAVLCalendario();
	if(c == d)
		cout << "PUNTEROS OK EN COPIA Y ==" << endl;
	else
		cout << "PROBLEMAS CON PUNTEROS" << endl;
	
  return 0;
}
