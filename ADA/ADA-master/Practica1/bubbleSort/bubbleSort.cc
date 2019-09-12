/*

Análisis y Diseño de Algoritmos 
PRÁCTICA 1 de laboratorio: Análisis empírico de la complejidad temporal de los algoritmos.

Objetivo de la práctica:

- Refrescar el lenguaje de programación y el uso de las herramientas: compilador, make, editor,  etc... 
- Saber obtener de manera empírica la complejidad temporal de un algoritmo, generando instancias aleatorias y cronometrando el tiempo que tarda en resolverlas.
- Saber medir tiempos de proceso utilizando la librería chrono del estándar C++11.
- Conocer el tipo de datos "size_t" para representar el tamaño de los objetos, útil para evitar desbordamientos de los tipos básicos; size_t puede almacenar el máximo tamaño de cualquier objeto.
- Conocer la herramienta Gnuplot para dibujar funciones matemáticas y su comando fit para encontrar la función que mejor se ajusta a una serie de datos.
*/

#include <unistd.h>
#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;
using namespace chrono;

//--------------------------------------------------------------
// Bubble sort basic algorithm
void bubbleSort(int * v, size_t size){
int aux;

for (size_t i = 1; i < size; i++)
        for (size_t j = 0; j < size - i; j++)
                if (v[j]>v[j+1]){ /*swap*/
                        aux = v[j]; 
						v[j] = v[j+1]; 
						v[j+1] = aux;
                }
}  
//--------------------------------------------------------------                


int main(void){

	int * v;
  
	size_t size;

	srand(getpid());

	cout << "BubbleSort CPU times in milliseconds:"
		<< endl
		<< "Size \t CPU time (ms.)"
		<< endl
		<< "----------------------------"
		<< endl;

	for (int exp = 10; exp <= 17; exp++){
		size = (size_t) powl(2,exp);
		v = new int [size];
		if (v){
			cout << size << "\t\t" << std::flush;

			for (size_t j = 0; j < size; j++) 
				v[j] = rand(); 

			auto begin = high_resolution_clock::now();
			bubbleSort(v,size);
			auto end = high_resolution_clock::now();
			cout << duration_cast<milliseconds>(end-begin).count() << endl;

			for (size_t i = 1; i < size; i++)
				if (v[i] < v[i-1]){ 
					cerr << "Panic, array not sorted! " << i << endl; 
					exit(1);			
				}

			delete v; 
		}
		else {
			cerr << "Error, not enough memory!" << endl;
			exit (1);  
		}
	}
}


