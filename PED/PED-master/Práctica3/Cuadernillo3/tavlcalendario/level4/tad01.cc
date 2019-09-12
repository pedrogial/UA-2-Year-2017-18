// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: los 4 recorridos vacios.

#include <iostream>
#include "tavlcalendario.h"
#include "tcalendario.h"

using namespace std;

int main()
{
	TAVLCalendario a;
	cout << a.Niveles() << a.Preorden() << a.Inorden() << a.Postorden() << endl;
	return 0;
}
