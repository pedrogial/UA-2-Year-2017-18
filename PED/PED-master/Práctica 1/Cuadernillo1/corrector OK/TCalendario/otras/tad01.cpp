#include <iostream>
#include "tcalendario.h"				
using namespace std;
int main(){
	TCalendario f(3, 2, 2000, NULL);
	int i;

	for(i = 1; i <= 5; i++){
		f--;
		cout << f << endl;
	}
	
	return 0;
}
