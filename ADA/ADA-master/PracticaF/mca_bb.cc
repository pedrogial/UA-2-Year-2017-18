//Pedro Giménez Aldeguer 15419933C

#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <queue>
using namespace std;
using namespace chrono;

/* Matriz */
double **Matrix;
int llamadas_recursivas = 0;
int mejorcoste = 0;

void iniciar(size_t ciudades){
  for(size_t i=0; i< ciudades; i++){
    for(size_t j=0; j< ciudades; j++){
        Matrix[j][i] = -1;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Metodos */

double coste (size_t ciudades, vector<int> e, vector <int> v){
  double resultado = 0;
  int pos = 0;
  for(size_t j=0; j < ciudades; j++){
      double menor = DBL_MAX;
      for(size_t i=0; i < e.size(); i++){
        if(Matrix[e[i]][j] < menor){
          menor = Matrix[e[i]][j];
          pos = e[i];
        }
      }
      resultado = resultado + (v[j]*Matrix[pos][j]);
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

void middle_QuickSort (vector<int> &v, long left, long right){
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
vector <int> Bool_Int (vector<bool> inicial) {
  vector <int> vec;
  for (size_t i=0; i<inicial.size(); i++) {
    if (inicial[i]){
      vec.push_back (i);
    }
  }  
  return vec;
}

size_t cantTrue (vector <bool> vec) {
  size_t respuesta = 0;

  for (size_t i=0; i<vec.size(); i++){
    if (vec[i]){
      respuesta++;
    }
  } 
  return respuesta;
}

vector<bool> vec_pesimista (vector<bool> inicial, size_t cantGasolineras, size_t cantCiudades) { 
  size_t g = cantGasolineras;
  vector <bool> vec = inicial;
  size_t posInicial = 0;
  size_t auxG;

  if (inicial.size()-1 >= 0){
    posInicial = inicial.size()-1;
  }
  
  for (size_t i=0; i<inicial.size(); i++){
    if (inicial[i]){
      g--;
    }
  }
  
  auxG = g;

  for (size_t i=posInicial; auxG>0; i++){
    vec.push_back (true);
    auxG--;
  }

  posInicial += g;

  for (size_t i=posInicial; i<cantCiudades-1; i++){
    vec.push_back (false);
  }
  return vec;
}

vector<size_t> vec_posicionesG (size_t g, vector<int> &v, vector<bool> inicial) {
  vector <size_t> vecPos, respuesta;

  while(vecPos.size() < v.size()){
    size_t mayor = 0;
    bool esta = false;
    size_t pos = 0;

    for(size_t i=0; i < v.size(); i++){
      esta = false;

      for(size_t j=0; j < vecPos.size(); j++){
        if(i == vecPos[j]){
          esta = true;
        }
      }

      if(esta == false){
        if(v[i] > (int)mayor){
          mayor = v[i];
          pos = i;
        }
      }
    }

    vecPos.push_back(pos);
  }

  for (size_t i=0; i<vecPos.size() && g>0; i++) {
    if (vecPos[i]>=inicial.size()) {
      respuesta.push_back(vecPos[i]);
    }
  }
  return respuesta;
}

vector<bool> vec_optimista (vector<bool> inicial, size_t g, size_t cantCiudades, vector<int> &veh ) {
  vector <bool> vec = inicial;
  vector <size_t> pos;

  size_t posInicial = 0;
  
  if (inicial.size()>0){
    posInicial = inicial.size();
  }

  for (size_t i=0; i<inicial.size(); i++) {
    if (inicial[i]){
      g--;
    }
  }
          
  for (size_t i=posInicial; i<cantCiudades; i++){
    vec.push_back (false); 
  }

  pos = vec_posicionesG(g, veh, inicial);

  for (size_t i=0 ; i<pos.size(); i++){
    vec[pos[i]] = true;
  }
  return vec;
}

double branch_and_bound( size_t g, size_t c, vector<int> &v, vector<int> &emp) {
  vector <bool> inicial, vectorOptimista, vectorPesimista;
  vectorPesimista = vec_pesimista (inicial, g, c);
  emp = Bool_Int(vectorPesimista);
  
  double pesimista = coste(c, emp, v);
  double current_best = pesimista;
  double optimista;

  priority_queue<vector<bool>> q;
  q.push(inicial);

  while(!q.empty()) {
    vector <bool> vecCola = q.top();
    q.pop();


    // Expandir
    if(llamadas_recursivas > 0){
      inicial = vecCola;
      inicial.push_back (false);
    }
    if(cantTrue(inicial) < g){
      vectorPesimista = vec_pesimista (inicial, g, c);
      pesimista = coste (c, Bool_Int(vectorPesimista), v);
      if(pesimista < current_best){
        emp = Bool_Int(vectorPesimista);
        current_best = pesimista;
      }

      vectorOptimista = vec_optimista (inicial, g, c, v);
      optimista = coste (c, Bool_Int(vectorOptimista), v);
      if(optimista < current_best){
        q.push(inicial);
      }
    }

    if(llamadas_recursivas > 0){
      inicial = vecCola;
      inicial.push_back (true);
    }
    if(cantTrue(inicial) < g) {
      vectorPesimista = vec_pesimista (inicial, g, c);
      pesimista = coste (c, Bool_Int(vectorPesimista), v);
      
      if(pesimista < current_best){
        emp = Bool_Int(vectorPesimista);
        current_best = pesimista;
      }

      vectorOptimista = vec_optimista (inicial, g, c, v);
      optimista = coste (c, Bool_Int(vectorOptimista), v);
      if(optimista < current_best){
        q.push(inicial);
      }
    }
    llamadas_recursivas++;
  }
  return current_best;
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

      vector<int>emp;

      auto begin = high_resolution_clock::now();
      auto t100ms = milliseconds(100);
      double costes = branch_and_bound(g, c, v, emplacement);
      cout << "Bb: " << costes << endl;
      auto end = high_resolution_clock::now();
      cout << "Emplacements: ";
      for(unsigned i = 0; i < emplacement.size(); i++){
          cout << emplacement[i] << " ";
      }

      duration<float> diff = (end-begin)*1000;
      cout << endl << "CPU time (ms): "<< diff.count() << endl;
      cout << "Iterations of loop while: " << llamadas_recursivas << endl;
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
