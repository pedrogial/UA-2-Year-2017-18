// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad03.cc
// --------------------------------

#include "tcalendario.h"
#include "tavlcalendario.h"

using namespace std;
// insertar sin rotaciones
int main()
{
	TCalendario c1(1, 1 , 1977,NULL), c2(2, 2, 1977, NULL), c3(3, 3, 1977, NULL);
	TAVLCalendario a;
	if(a.Insertar(c2) && a.Insertar(c1) &&  a.Insertar(c3))
	{
		cout << "Inorden: " << a.Inorden() << endl;
		cout << "Preorden: " << a.Preorden() << endl;
	}
	else
		cout << "MAL" << endl;

  return 0;
}
