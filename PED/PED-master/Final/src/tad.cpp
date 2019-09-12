#include <iostream>
#include "tabbcalendario.h"


/*
					7
				 /     \
				2       9    
				 \     / \
				  5   8   10
				 /          \
                4           11
*/
using namespace std;

int
main(void)
{
	/*
  //Comprobar borrar hoja
  
  TABBCalendario a, b, c, d;
    TCalendario c7(7, 7,2000,(char *)"fecha"),c4(4,4,2000,(char *)"fecha"),c10(10,10,2000,(char *)"fecha");
  TCalendario c2(2,2,2000,(char *)"fecha"),c5(5,5,2000,(char *)"fecha"),c8(8,8,2000,(char *)"fecha"),c9(9,9,2000,(char *)"fecha"),c11(11,11,2000,(char *)"fecha");
  
   TCalendario c12(12, 12, 2000, (char *) "fecha");
  
	a.Insertar(c7);
	a.Insertar(c2);
	a.Insertar(c5);
	a.Insertar(c4);
	a.Insertar(c9);
	a.Insertar(c8);
	a.Insertar(c10);
	a.Insertar(c11);

	b.Insertar(c7);
	b.Insertar(c2);
	b.Insertar(c5);
	b.Insertar(c4);
	b.Insertar(c9);
	b.Insertar(c8);
	b.Insertar(c10);
	b.Insertar(c11);

	c.Insertar(c7);
	c.Insertar(c2);
	c.Insertar(c5);
	c.Insertar(c4);
	c.Insertar(c9);
	c.Insertar(c8);
	c.Insertar(c10);
	c.Insertar(c12);
  

	d.Insertar(c7);
	d.Insertar(c2);
	d.Insertar(c5);
	d.Insertar(c4);
	d.Insertar(c8);
	d.Insertar(c10);
	d.Insertar(c12);

	cout << a.examen2017(b) << endl;
	cout << a.examen2017(c) << endl;
	cout << a.examen2017(d) << endl;
	cout << d.examen2017(a) << endl;
	
	cout << "Preorden = " << a.Preorden() << endl;
	cout << "Inorden = " << a.Inorden() << endl;


	TListaCalendario lista;
	lista.Insertar(TCalendario(3, 3, 2000, NULL));
	lista.Insertar(TCalendario(12, 12, 2000, NULL));
	lista.Insertar(TCalendario(11, 11, 2000, (char *)"fecha"));
	cout << "lista: " << lista << endl;	
	
	cout << " Insertados: " << a.lista2arbol(lista) << endl;
*/
/*	
	a.EliminarUltimoNivel();
*//*
	cout << "Preorden = " << a.Preorden() << endl;
	cout << "Inorden = " << a.Inorden() << endl;

	*/

  return 0;
}
