// José Soler Martínez 48796440P

#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <float.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include<math.h>
using namespace std;
using namespace chrono;

int N=0;
double menor = DBL_MAX;
int llamadas_recursivas = 0;

double **Matriz;

int getGasolineras(string linea){
  return linea[2] - '0';
}

int getCiudades(string linea){
  return linea[0] - '0'; 
}

int posfichero(char * argv[], int argc) {
  int pos = 1;
  for (int i = 0; i<argc; i++) {
		if ((strcmp(argv[i], "-f") == 0)){
      pos = pos + i;
    }
	}
  return pos;
}

double coste(size_t ciudades, vector<int> pos, vector <int> v){
  double resultado = 0;
  int posic = 0;
  bool gasol = false;
  for(unsigned j=0; j < ciudades; j++){
    for(unsigned i=0; i < pos.size(); i++){
      if((int)j == pos[i]){
        gasol = true;
      }
    }
    if(!gasol){
      double menor = DBL_MAX;
      for(size_t i=0; i < pos.size(); i++){
        if(Matriz[pos[i]][j] < menor){
          menor = Matriz[pos[i]][j];
          posic = i;
        }
      }
      resultado = resultado + (v[j]*Matriz[pos[posic]][j]);
    }
    gasol = false;
  }
  return resultado;
}
void fnew(int numero, int indice, int longitud, int gasolineras, vector<int> &pos, vector<int> &mejor, vector<int> &v){



}

int main(int argc, char * argv[]){
  size_t ciudades = 0;
  size_t gasolineras = 0;

  vector <double> d;
  vector <int> v;
  vector <int> pos;

  ifstream fich(argv[posfichero(argv, argc)]);
  string linea;
  unsigned count = 0;
  while(getline(fich, linea)){
    if(count == 0){
      gasolineras = getGasolineras(linea);
      ciudades = getCiudades(linea);
    }else if(count == 1){
      vector<string> cosa;
      istringstream iss(linea);
      for(string linea; iss >> linea; ){
        cosa.push_back(linea);
      }
      for(size_t i = 0; i < cosa.size(); i++){
        v.push_back(atoi(cosa[i].c_str()));
      }
      Matriz = new double *[ciudades];
      for(size_t i=0; i<ciudades; i++){
        Matriz[i] = new double[ciudades];
      }
    }
    if(count > 1 && count != ciudades+2){
      vector<string> cosa;
      istringstream iss(linea);
      for(string linea; iss >> linea; ){
        cosa.push_back(linea);
      }
      for(size_t i = 0; i < cosa.size(); i++){
        Matriz[count-2][i] = atof(cosa[i].c_str());
      }
    }
    count++;
  }
  N = ciudades - 1;
  vector<int> mejor;
  auto begin = high_resolution_clock::now();
  auto t100ms = milliseconds(100);
  bool emp[ciudades];
  for(unsigned i = 0; i < ciudades; i++){
    emp[i] = false;
  }

  fnew(i,i+1, 1, gasolineras, pos, mejor, v);
/*
  for (unsigned i=0; i < ciudades;i++){
    frecursiva(i,i+1, 1, gasolineras, pos, mejor, v);
  }
*/

  auto end = high_resolution_clock::now();
  cout << "Backtracking: " << menor << endl;
  cout << "Emplacements: ";
  for(unsigned i = 0; i < mejor.size(); i++){
  	cout << mejor[i] << " ";
  }
  duration<float> diff = (end-begin)*1000;
  cout << endl << "CPU time (ms): "<< diff.count() << endl;
  cout << "Recursive calls: " << llamadas_recursivas << endl;
}






/*
void frecursiva(int numero, int indice, int longitud, int gasolineras, vector<int> &pos, vector<int> &mejor, vector<int> &v){
  int i;
  if (longitud==gasolineras) {
  	int contar=0;
    *//*
  	while(numero){
      
  		pos.push_back(numero%10);
  		numero = numero/10;
  		contar++;
  	}*//*
    int cifras_rest = 0;
    if((numero %10) == 0){
      cifras_rest ++;
    }
    while(numero > 0){
      numero = numero/10;
      cifras_rest ++;
    }
    int cifras = 1;
    int anterior = -1;
    int aux2;
    while(numero){
      aux2 = numero%(int)((pow(10, cifras_rest)) / pow(10, cifras-1));
      if(aux2 <= anterior){
        anterior = aux2;
        pos.push_back(aux2);
        numero = numero - aux2*(pow(10, cifras_rest)/pow(10, cifras-1));
        cifras_rest=cifras_rest-cifras;
        contar++;
      }else{
        cifras++;
      }
    }
  	if(contar < gasolineras){
  		pos.push_back(0);
  	}
    double aux = coste(N+1, pos, v);
   	if(menor > aux){
   		menor = aux;
   		mejor = pos;
   	}
    while(pos.size() != 0){
    	pos.erase(pos.end()-1);
    }
  }
  else {
    for (i=indice; i<=N; i++){
    	llamadas_recursivas++;
      frecursiva(numero*10+i,i+1,longitud+1, gasolineras, pos, mejor, v);
    }
  }
}
*/