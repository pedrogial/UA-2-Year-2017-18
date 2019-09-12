// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad05.cc
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

  a.Insertar(c4);
  cout << "Esta altura debe ser 1: " << a.Altura() << endl;
  a.Insertar(c5);   
  cout << "Esta altura debe ser 2: " << a.Altura() <<  endl;    
  a.Insertar(c2);
  cout << "Esta altura debe ser 2: " << a.Altura() << endl;
  a.Insertar(c1);
  cout << "Esta altura debe ser 3: " << a.Altura() << endl;
  a.Insertar(c3);
  cout << "Esta altura debe ser 3: " << a.Altura() << endl;
  return 0;
}
