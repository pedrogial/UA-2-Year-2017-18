// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad09.cc
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
			c5(1, 1, 2050, NULL), 
			cx(1, 1, 2012, NULL);
  TAVLCalendario a;

  if(a.Buscar(c1))
    cout << "Pues a a ser que no!!" << endl;
  else
    cout << "Pudiendo estar y no." << endl;

  a.Insertar(c4);
  a.Insertar(c5);   
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  
  if(a.Buscar(c4))
    cout << "esta si" << endl;
  if(!a.Buscar(cx))
    cout << "esta no" << endl;
  if(a.Buscar(c1))
    cout << "esta me gusta me la como yo" << endl;

  return 0;
}
