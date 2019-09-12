// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad02.cc
// --------------------------------

#include <iostream>
#include "tavlcalendario.h"

using namespace std;

int main(void)
{
  TAVLCalendario a;
  TCalendario c(27, 4, 1976, NULL);

  a.Insertar(c);

  cout << "Altura: " << a.Altura() << endl;

  return 0;
}
