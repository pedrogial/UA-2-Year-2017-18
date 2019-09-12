//Pedro Giménez Aldeguer 15419933C

#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Matriz */
double **Matrix;

void iniciar(size_t ciudades){
  for(size_t i=0; i< ciudades; i++){
    for(size_t j=0; j< ciudades; j++){
        Matrix[j][i] = -1;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Metodos */
double coste(size_t ciudades, vector<int> e, vector <int> v){
  double resultado = 0;
  int pos = 0;
  bool es = false;

  for(size_t j=0; j < ciudades; j++){
    for(size_t i=0; i < e.size(); i++){
      if(j == (size_t)e[i]){
        es = true;
      }
    }
    if(es == false){
      int menor = -1;

      for(size_t i=0; i < e.size(); i++){
        if(menor == -1){
          menor = Matrix [e[i]][j];
          pos = i;
        }
        else{
          if(Matrix[e[i]][j] < menor){
            menor = Matrix [e[i]][j];
            pos = i;
          }
        }
        
      }
      resultado = resultado + (v[j]*Matrix[e[pos]][j]);
    }
    es = false;
  }
  return resultado;
}

void Emplacements (vector<int>& e, size_t g, vector<int>& v){
  while(e.size() < g){
    int mayor = 0;
    bool esta = false;
    int pos = 0;

    for(size_t i=0; i < v.size(); i++){
      esta = false;
      for(size_t j=0; j < e.size(); j++){
        if(i == (size_t)e[j]){
          esta = true;
        }
      }
      if(esta == false){
        if(v[i] > mayor){
          mayor = v[i];
          pos = i;
        }
      }
    }
    e.push_back(pos);
  }
}

void middle_QuickSort(vector<int> &v, long left, long right){
long i,j;
int pivot; 
  if (left<right){
  i=left; j=right;
  pivot=v[(i+j)/2];
  do{
    while (v[i]<pivot) i++;
    while (v[j]>pivot) j--;
    if (i<=j) {
      swap(v[i], v[j]);
      i++; j--;
    }
  }while (i<=j);
  if (left<j)  middle_QuickSort(v,left,j);
  if (i<right) middle_QuickSort(v,i,right);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Argumentos */
bool Distinto(char * argv[], int argc) {
  bool es = true;
	for (int i = 0; i<argc; i++) {
      if((strcmp(argv[i], "-f") == 0)){
        es = true;
        i++;
      }
      else{
        es = false;
      }
    
	}
	return es;
}

int Raro(char * argv[], int argc) {
  int es = 0;
	for (int i = 0; i<argc; i++) {
		if ((strcmp(argv[i], "-t") == 0) || (strcmp(argv[i], "--ignore_recursive") == 0)){
    }
    else{
      if((strcmp(argv[i], "-f") == 0)){
        i++;
      }
      else{
        es = i;
      }
    }
	}
	return es;
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

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Ficheros */
int main(int argc, char * argv[]){
  size_t c = 0;
  size_t g = 0;


  vector <int> v;
  vector <int> repostages;
  vector <int> costes;

  if(Distinto(argv, argc)){
    
    ifstream fich(argv[posfichero(argv, argc)]);
    
    if(fich.is_open()){
      string linea;
      
      int contar=0;
      unsigned int Inicio;
      unsigned int Final;
      int cm = 0;

      
      while (getline (fich, linea)) {
        if (contar == 0) {
          Inicio = 0;
          Final = 0;
          Final = linea.find (" ", Inicio);
          c = (size_t) atoi (linea.substr(Inicio, Final).c_str());
          g = (size_t) atoi (linea.substr(Final+1, linea.length()).c_str());
          contar++;
        }
        else if (contar == 1) {
          Inicio = 0;
          Final = 0;
            
          for(size_t i=0; i < c; i++) {
            Final = linea.find (" ", Inicio);
            v.push_back (atoi (linea.substr(Inicio, Final).c_str()));
            Inicio = Final+1;
          }
          contar++;
        }
        else if (contar >= 2) {
          if(contar == 2){

            Matrix = new double *[c];
            for(size_t i=0; i<c; i++){
              Matrix[i] = new double[c];
            }       
            iniciar(c);

          }
          Inicio = 0;
          Final = 0;
          double aux1;
          
          for(size_t i=0; i < c; i++){
            Final = linea.find (" ", Inicio);
            aux1 = atof(linea.substr(Inicio, Final).c_str());
            Matrix[i][cm] = aux1;
            Inicio = Final+1;
          }
          cm++;
          contar++;
        }
      }
      fich.close();
////////////////////////////////////////////////////////////////////////////////////////////////////      
      /* Salidas */
      vector <int> emplacement;

      Emplacements(emplacement, g, v);
      middle_QuickSort(emplacement, 0, emplacement.size()-1);

      cout << "Greedy: " << coste(c, emplacement, v) << endl;  
      cout << "Emplacements: ";
      for(size_t i = 0; i < emplacement.size(); i++){
        cout << emplacement[i] << " ";
      }
      cout << endl;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////       
    /* Errores */
    else{
      cerr << "ERROR: can’t open file: " << argv[posfichero(argv, argc)] << "." << endl << "Usage:" 
      << endl <<"mca_greedy -f file";
    }
  }
  else{
    cerr << "ERROR: unknown option " << argv[Raro(argv, argc)] << "." << endl << "Usage:" 
      << endl << "mca_greedy -f file";
  }
}
