// ANÁLISIS Y DISEÑO DE ALGORITMOS. 2017/18
// Práctica 2 de Laboratorio: Comparación empírica de la complejidad temporal de los algoritmos de ordenación de vectores Quicksort y Heapsort.
// Se deben comparar en tres supuestos distintos: (1) vectores con contenido aleatorio y sin orden pre-establecido; (2) vectores ordenados; (3) vectores ordenados al contrario.
// La comparación debe hacerse mediante la "cuenta de pasos de programa"
// Consulta en el enunciado los detalles para realizar esta práctica.


#include <unistd.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;
double _STEPS_ = 0; 

//--------------------------------------------------------------
// Middle Quick Sort
void 
middle_QuickSort(int * v, long left, long right){

long i,j;
int pivot; 
    _STEPS_++; //a
	if (left<right){ //a
		i=left; j=right; //a
		pivot=v[(i+j)/2]; //a
        do{
            _STEPS_++; //b
			while (v[i]<pivot) {i++; _STEPS_++;} //c
			while (v[j]>pivot) {j--; _STEPS_++; }//d
			if (i<=j){  //b
				swap(v[i], v[j]); //b
				i++; j--; //b
			}
		}while (i<=j); //b
		if (left < j)  middle_QuickSort(v,left,j); //a
		if (i < right) middle_QuickSort(v,i,right); //a
	}
}

//--------------------------------------------------------------                
//HEAPSORT
// Procedure sink used by Heapsort algorith
// Sink an element (indexed by i) in a tree to keep the heap property. n is the size of the heap. 

void sink(int *v, size_t n, size_t i)
{
	
	size_t largest;
	size_t l, r;
	do{
		_STEPS_++; //b
		largest = i;  
		l = 2*i + 1;  
		r = 2*i + 2;  
	
		if (l < n && v[l] > v[largest]) //b
			largest = l;

		if (r < n && v[r] > v[largest]) //b
			largest = r;
	
		if (largest == i) break; //b
		
		swap(v[i], v[largest]); //b
		i=largest;  
   	}while (true); //b
}
 
//--------------------------------------------------------------                
// Heapsort algorithm 
void heapSort(int *v, size_t n)
{

    for (size_t i = n / 2 - 1; i >= 0; i--){
         _STEPS_++; //b
        sink(v, n, i);
		if (i==0) break;
	}	

    for (size_t i=n-1; i>0; i--)
    {
         _STEPS_++; //c
        swap(v[0], v[i]);
        sink(v, i, 0);
    }
}
int main(void){

	int * v;
    int * v2;
	size_t size;
    size_t size2;

	srand(getpid());
    cout << std::fixed << setprecision(3);

	cout << "              RANDOM ARRAYS       SORTED ARRAYS    REVERSE SORTED ARRAYS"
		<< endl;
	cout << "           ------------------- ------------------- ---------------------"
		<< endl
		<< "Size       QuickSort HeapSort  QuickSort  HeapSort  QuickSort HeapSort"
		<< endl
		<< "========================================================================="
		<< endl;

	for (int exp = 15; exp <= 22; exp++){
		size = (size_t) powl(2,exp);
		size2 = (size_t) powl(2,exp);
		v = new int [size];
		v2 = new int [size2];

		double suma = 0;
		double suma2 = 0;
		double sumaA = 0;
		double sumaA2 = 0;
		double sumaD = 0;
		double sumaD2 = 0;
		double media = 0; 
		
		if (v){
			cout << size << "\t" << std::flush;

			for(int i = 0; i < 30; i++){
				for (size_t j = 0; j < size; j++){
					
					v2[j]= v[j] = rand();
					
				}
				//////////////////////////////////

		        middle_QuickSort(v, 0, size-1);
				suma = suma + _STEPS_;
				_STEPS_ = 0;
				heapSort(v2, size2-1);
                suma2 = suma2 + _STEPS_;
				_STEPS_ = 0;

				//////////////////////////////////

				middle_QuickSort(v, 0, size-1);
				sumaA = sumaA + _STEPS_;
				_STEPS_ = 0;
				heapSort(v2, size2-1);
                sumaA2 = sumaA2 + _STEPS_;
				_STEPS_ = 0;

				//////////////////////////////////

				int aux = 0;
				for(size_t i = 0; i < size/2 ; i++){
 					aux = v[i];
  					v[i] = v[size - i];
  					v[size - i] = aux;
				}
				for (size_t j = 0; j < size; j++){
					v2[j]= v[j];
				}
				middle_QuickSort(v, 0, size-1);
				sumaD = sumaD + _STEPS_;
				_STEPS_ = 0;
				heapSort(v2, size2-1);
                sumaD2 = sumaD2 + _STEPS_;
				_STEPS_ = 0;
				
				//////////////////////////////////	

				for (size_t i = 1; i < size; i++){
					if (v[i] < v[i-1]){ 
						cerr << "Panic, array not sorted! " << i << endl; 
						exit(1);
					}
				}
			}
			 
			
            media = suma/30/1000000;
			cout << setw(10) << media << std::flush;

            media = suma2/30/1000000;
			cout << setw(10) << media << std::flush;
			
			media = sumaA/30/1000000;
			cout << setw(10) << media << std::flush;

            media = sumaA2/30/1000000;
			cout << setw(10) << media << std::flush;

			media = sumaD/30/1000000;
			cout << setw(10) << media << std::flush;

            media = sumaD2/30/1000000;
			cout << setw(10) << media << std::flush;
			cout << endl;

			
			delete[] v;
			delete[] v2;  
		}
		else {
			cerr << "Error, not enough memory!" << endl;
			exit (1);  
		}
	}
}
