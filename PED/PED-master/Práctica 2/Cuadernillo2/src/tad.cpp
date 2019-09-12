#include <iostream>
#include "tcalendario.h"
using namespace std;

int main(){
	TCalendario cal(1, 1, 2000, NULL);

	cout << cal.ModFecha(1, 3, 2000) << endl;
	cout << cal << endl;

	for(int i = 1; i <= 7; i++){
		cout << --cal << endl;;	
			
	}
	cout << cal.ModFecha(31, 4, 1900) << endl;
	
	return 0;
}
