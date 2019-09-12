// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad01.cc
// --------------------------------

// prueba DD basico (3 nodos).
#include <iostream>
#include "tavlcalendario.h"

using namespace std;

int main(void)
{
  TCalendario c1(1, 1, 2001, NULL), c2(1, 1, 2002, NULL), c3(1, 1, 2003, NULL);
  TAVLCalendario a;
  
  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  
  cout << a.Inorden() << endl << a.Preorden() << endl;
  
  return 0;
}
