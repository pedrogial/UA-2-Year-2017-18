// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad06.cc
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
  TAVLCalendario a;

  cout << "Nodos (0): " << a.Nodos() << endl;
  a.Insertar(c4);
  cout << "Nodos (1): " << a.Nodos() << endl;
  a.Insertar(c5);   
  cout << "Nodos (2): " << a.Nodos() <<  endl;    
  a.Insertar(c2);
  cout << "Nodos (3): " << a.Nodos() << endl;
  a.Insertar(c1);
  cout << "Nodos (4): " << a.Nodos() << endl;
  a.Insertar(c3);
  cout << "Nodos (5): " << a.Nodos() << endl;

  return 0;
}
