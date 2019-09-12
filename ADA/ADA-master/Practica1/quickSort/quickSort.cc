/*
Análsis y diseño de algoritmos.
Práctica 1: Análisis empírico de la complejidad temporal promedio del algoritmo de ordenación Quicksort central
*/

//--------------------------------------------------------------
// Middle QuickSort
#include <unistd.h>
#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;
using namespace chrono;

void middle_QuickSort(int * v, long left, long right){
long i,j;
int pivot,aux; 
  if (left<right){
	i=left; j=right;
	pivot=v[(i+j)/2];
	do{
		while (v[i]<pivot) i++;
		while (v[j]>pivot) j--;
		if (i<=j) {
		  aux=v[i]; v[i]=v[j]; v[j]=aux;
		  i++; j--;
		}
	}while (i<=j);
	if (left<j)  middle_QuickSort(v,left,j);
	if (i<right) middle_QuickSort(v,i,right);
  }
}


int main(void){

	int * v;
  
	size_t size;

	srand(getpid());

	cout << "QuickSort CPU times in milliseconds:"
		<< endl
		<< "Size \t CPU time (ms.)"
		<< endl
		<< "----------------------------"
		<< endl;

	for (int exp = 15; exp <= 23; exp++){
		size = (size_t) powl(2,exp);
		v = new int [size];

		float suma = 0;
		float media = 0;
		
		if (v){
			cout << size << "\t\t" << std::flush;

			for(int i = 0; i < 30; i++){
				for (size_t j = 0; j < size; j++){
					
					v[j] = rand();
					
				}

				auto begin = high_resolution_clock::now();
				middle_QuickSort(v, 0, size-1);
				auto end = high_resolution_clock::now();
				suma = suma + duration_cast<milliseconds>(end-begin).count();

				for (size_t i = 1; i < size; i++){
					if (v[i] < v[i-1]){ 
						cerr << "Panic, array not sorted! " << i << endl; 
						exit(1);			
					}
				}
			}
			media = suma/30;
			cout << media << endl;
			delete[] v; 
		}
		else {
			cerr << "Error, not enough memory!" << endl;
			exit (1);  
		}
	}
}


