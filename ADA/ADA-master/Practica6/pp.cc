// José Soler Mártínez 48796440P
#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <float.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

double ** Matriz;
double centroide(const vector<double> &d, const vector<int> &v, size_t first_city, size_t last_city);
double cmin (const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations);

void mostrarMatriz(size_t ciudades, size_t gasolineras){
    // Mostrar matriz
  for(size_t j=1; j < ciudades; j++){
      for(size_t i=0; i < gasolineras; i++){
        if(i >= j){
          cout << "- \t";
        }else{
          cout << Matriz[j][i] << "\t";
        }
      }
      cout << endl;
    }
}

void inicializarMatriz(size_t ciudades, size_t gasolineras){
    // Inicializarla a -1
    for(size_t i=0; i<gasolineras; i++){
      for(size_t j=0; j<ciudades; j++){
        Matriz[j][i] = -1;
      }
    }
}

void corregirMatriz(size_t ciudades, size_t gasolineras){
    // Inicializarla a -1
    for(size_t i=0; i<gasolineras; i++){
      for(size_t j=0; j<ciudades; j++){
        if(Matriz[j][i]==DBL_MAX)
          Matriz[j][i] = -1;
      }
    }
}

void borrarMatriz(size_t ciudades){
    for(size_t i=0;i<ciudades;i++){
        delete[] Matriz[i];
    }
    delete[] Matriz;
}

void Emplacements(size_t last_city, size_t n_stations, double **tabla){

}

double cmin_iterative2(const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations){
  inicializarMatriz(last_city, n_stations);
  vector<double> vector1;
  vector<double> vector2;
  double minimo = DBL_MAX;
  double aux;
  for(size_t i = 1; i <= n_stations; i++){
    for(size_t j = 1; j <= last_city; j++){
      minimo = DBL_MAX;
      if(i == 1){
        minimo = centroide(d, v, 0, j);
      }else{
        for(size_t a = 0; a < last_city; a++){
            aux = vector1[a-1] + centroide(d, v, a, j);
            if(aux < minimo){
              minimo = aux;
            }
        }
      }
      vector2.push_back(minimo);
    }
    vector1 = vector2;
    
    vector2.clear();
  }
  return minimo;
}

double cmin_iterative(const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations){
  inicializarMatriz(last_city, n_stations);
  double minimo = DBL_MAX;
  double aux;
  for(size_t j = 0; j <= last_city; j++){
    for(size_t i = 1; i <= n_stations; i++){
      if(i == 1){
        minimo = centroide(d, v, 0, j);
      }else{
        for(size_t a = 0; a < j; a++){
            aux = Matriz[a][i-2] + centroide(d, v, a, j);
            if(aux < minimo){
              minimo = aux;
            }
        }
        //Matriz[j][i-1] = Matriz[j-1][i-2] + centroide(d, v, i, j);
      }
      Matriz[j][i-1] = minimo;
    }
  }
  return Matriz[last_city][n_stations-1];
}

double cmin_memorization(const vector<double> &d, const vector<int> &v, size_t last_city, int n_stations){
    double minimo = DBL_MAX;
    double aux;
    if (n_stations == 1) {
        if(Matriz[last_city][0] == -1){
          minimo = centroide(d, v , 0, last_city);
        }else{
          minimo = Matriz[last_city][0];
        }
    }else if (n_stations > 1) {
        for(size_t i = 0; i < last_city; i++){
          if(Matriz[i][n_stations-2] == -1){
            aux = cmin_memorization(d, v, i, n_stations-1) + centroide (d, v, i, last_city);
          }else{
            aux = Matriz[i][n_stations-2] + centroide(d, v, i, last_city);
          }
            if(aux < minimo){
              minimo = aux;
            }
        }
    }
    Matriz[last_city][n_stations-1] = minimo;
    return minimo;
}

double centroide(const vector<double> &d, const vector<int> &v, size_t first_city, size_t last_city){
   double distancia, min;
   min = DBL_MAX;
   for(size_t g=first_city; g < last_city; g++){
      distancia = 0;
      for(size_t j = first_city; j < last_city; j++){
        distancia += abs(d[j] - d[g])* v[j]; 
      }
      if(distancia < min){
        min = distancia;
      }
   }
   return min;
}


double cmin (const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations){
    double minimo = DBL_MAX;
    double aux;
    if (n_stations == 1) {
        minimo = centroide(d, v , 0, last_city);
    }else if (n_stations > 1) {
        for(size_t i = 0; i < last_city; i++){
            aux = cmin(d, v, i, n_stations-1) + centroide (d, v, i, last_city);
            if(aux < minimo){
              minimo = aux;
            }
        }
    }
    return minimo;
}

bool argumentoscorrectos (char * argv[], int argc) {
  for (int i = 1; i<argc; i++) {
    if ((strcmp(argv[i], "--ignore_recursive") != 0) && (strcmp(argv[i], "-t") != 0) && 
      (((strcmp(argv[i], "-f") == 0) && (i+1 < argc)) && ((strcmp(argv[i+1], "--ignore_recursive") == 0) 
      && (strcmp(argv[i+1], "-f") == 0) && (strcmp(argv[i+1], "-t") == 0)))) {
      return false;
    }
  }
  return true;
}

bool iterativo (char * argv[], int argc) {
  bool respuesta = false;
  for (int i = 1; i<argc; i++) {
    if (strcmp(argv[i], "-t") == 0) {
      respuesta =  true;
    }
  }
  return respuesta;
}

bool ignore (char * argv[], int argc) {
  bool respuesta = false;
  for (int i = 1; i<argc; i++) {
    if (strcmp(argv[i], "--ignore_recursive") == 0) {
      respuesta = true;
    }
  }
  return respuesta;
}

int main(int argc, char * argv[]){
    size_t ciudades = 0;
    size_t gasolineras = 0;
    vector <double> distancia;
    vector <int> vehiculos;
    if(argumentoscorrectos(argv, argc)){
      int pos_f = 0;
      for(int i=0; i < argc-1; i++){
        if(strcmp(argv[i], "-f") == 0){
          if(i < argc-1){
            pos_f = i;
          }
        }
      }

      ifstream fich(argv[pos_f+1]);
      if(fich.is_open()){
        string linea;
        int i=0;
        unsigned int inicio_palabra;
        unsigned int final_palabra;
        while (getline (fich, linea)) {
          if (i == 0) {
            inicio_palabra = 0;
            final_palabra = 0;
            final_palabra = linea.find (" ", inicio_palabra);
            ciudades = (size_t) atoi (linea.substr(inicio_palabra, final_palabra).c_str());
            gasolineras = (size_t) atoi (linea.substr(final_palabra+1, linea.length()).c_str());
          }
          else if (i == 1) {
            inicio_palabra = 0;
            final_palabra = 0;
            for(size_t i=0; i < ciudades; i++) {
              final_palabra = linea.find (" ", inicio_palabra);
              vehiculos.push_back (atoi (linea.substr(inicio_palabra, final_palabra).c_str()));
              inicio_palabra = final_palabra+1;
            }
          }
          else if (i == 2) {
            inicio_palabra = 0;
            final_palabra = 0;
            double aux1;
            for(size_t i=0; i < ciudades; i++){
              final_palabra = linea.find (" ", inicio_palabra);
              aux1 = atof(linea.substr(inicio_palabra, final_palabra).c_str());
              distancia.push_back(aux1);
              inicio_palabra = final_palabra+1;
            }
          }
          i++;
        }
        fich.close();
        // Añadir columnas a la matriz
        Matriz = new double *[ciudades+1];
        for(size_t i=0; i<ciudades+1; i++){
          Matriz[i] = new double[gasolineras];
        }
        inicializarMatriz(ciudades+1, gasolineras);
        //Matriz[1][2] = -7;
        //mostrarMatriz(ciudades, gasolineras);
        if(!ignore(argv, argc)){
          cout << "Recursive: " << cmin(distancia, vehiculos, ciudades, gasolineras) << endl;
        }
        cout << "Memoization: " << cmin_memorization(distancia, vehiculos, ciudades, gasolineras)  << endl 
             << "Iterative (table): " << cmin_iterative(distancia, vehiculos, ciudades, gasolineras) << endl 
             << "Iterative (vector): " << cmin_iterative2(distancia, vehiculos, ciudades, gasolineras) << endl
             << "Emplacements: ¿?" << endl 
             << "Assignments: ¿?" << endl << "Assignment cost: ¿?" << endl;
        if(iterativo(argv, argc)){
            cout << "Iterative table: " << endl << "¿?" << endl;
        }
        cmin_iterative(distancia, vehiculos, ciudades, gasolineras);
        //corregirMatriz(ciudades+1, gasolineras);
        mostrarMatriz(ciudades+1, gasolineras);
        borrarMatriz(ciudades);
      }

    }else{
      cerr << "mca -f fichero_entrada" << endl;
    }
}
