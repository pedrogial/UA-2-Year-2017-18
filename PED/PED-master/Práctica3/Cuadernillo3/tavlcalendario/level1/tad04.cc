// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad04.cc
// --------------------------------

#include <iostream>
#include "tcalendario.h"
#include "tavlcalendario.h"
using namespace std;

int main()
{
  TCalendario c1(1, 1, 2001, NULL), c2(1, 1, 2002, NULL), c3(1, 1, 2003, NULL);
  TAVLCalendario a;

  cout << "Altura de un arbol vacio: " << a.Altura() << endl;  
  if(a.Insertar(c2) && a.Insertar(c3) && a.Insertar(c1))
    cout << "Esta altura debe ser 2: " << a.Altura() << endl;
  else
    cout << "no devuelve bien si ha insertado o no" << endl;    
  return 0;
}
