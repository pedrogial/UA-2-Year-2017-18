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


double **Matrix;

double minimo(double n1, double n2){
    if(n1 < n2){
        return n1;
    }
    else{
        return n2;
    }
}

double absoluto (double n){
  if(n < 0){
    return -n;
  }
  else{
    return n;
  }
}

void mostrarMatrix(size_t ciudades, size_t gasolineras){
  for(size_t j=1; j <= ciudades; j++){
    for(size_t i=0; i < gasolineras; i++){
      if(i >= j){
        cout << "- \t";
      }
      else{
        cout << Matrix[j][i] << "\t";
      }
    }
    cout << endl;
  }
}

void borrar(size_t ciudades){
  for(size_t i = 0 ; i < ciudades; i++){
    delete[] Matrix[i];
  }
  delete[] Matrix;
}

void iniciar(size_t ciudades, size_t gasolineras){
  for(size_t i=0; i<gasolineras; i++){
    for(size_t j=0; j<ciudades; j++){

      if(Matrix[j][i]== DBL_MAX || Matrix[j][i] == '\0'){
        Matrix[j][i] = -1;
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////



double centroide(const vector<double> &d, const vector<int> &v, size_t first_city, size_t last_city){
   double distancia, min;
    min = -1;
    for(size_t i=first_city; i < last_city; i++){  
      distancia = 0;
      
      for(size_t j = first_city; j < last_city; j++){       
        distancia += absoluto(d[j] - d[i]) * v[j];
      }
      if(min == -1){
        min = distancia;
      }
      else{
        min = minimo(min, distancia);
      }
   }
   return min;
}

double cmin (const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations){
    double min = -1;
    double aux, aux1, aux2;
    
    if (n_stations == 1) {
      min = centroide(d, v , 0, last_city);      
    }
    else{ 
      if (n_stations > 1) {

        for(size_t i = 0; i < last_city; i++){ 
          
          aux1 = cmin(d, v, i, n_stations-1);
          aux2 = centroide (d, v, i, last_city);
          aux = aux1 + aux2; 

          if(min == -1){
            min = aux;
          }
          else{
            min = minimo(aux, min);
          }
        }
      }
    }
  return min;
}

double cmin_memorization(const vector<double> &d, const vector<int> &v, size_t last_city, int n_stations){
    double min = -1;
    double aux, aux1, aux2;

    if (n_stations == 1) {
      if(Matrix[last_city][0] == -1){
        min = centroide(d, v , 0, last_city);
      }
      else{
        min = Matrix[last_city][0];
      }
    }
    else{
      if (n_stations > 1) {

        for(size_t i = 0; i < last_city; i++){
          if(Matrix[i][n_stations-2] == -1){
            aux1 = cmin_memorization(d, v, i, n_stations-1);
            aux2 = centroide (d, v, i, last_city);
            aux = aux1 = aux2;
          }
          else{
            aux = Matrix[i][n_stations-2] + centroide(d, v, i, last_city);
          }

          if(min == -1){
            min = aux;
          }
          else{
            min = minimo(aux, min);
          }
        }
      }
    }
  Matrix[last_city][n_stations-1] = min;
  
  return min;
}

double cmin_iterative(const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations){
  iniciar(last_city, n_stations);

  double min = -1;
  double aux;

  for(size_t j = 0; j <= last_city; j++){
    for(size_t i = 1; i <= n_stations; i++){
      if(i == 1){
        min = centroide(d, v, 0, j);
      }
      else{
        for(size_t a = 0; a < j; a++){
          aux = Matrix[a][i-2] + centroide(d, v, a, j);
          
          if(min == -1){
           min = aux;
          }
          else{
            //cout << min << " ";
            min = minimo(aux, min);
          }

        }
      }

      Matrix[j][i-1] = min;
    }
  }
  return Matrix[last_city][n_stations-1];
}



double cmin_iterative_v(const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations){
  iniciar(last_city, n_stations);
  
  vector<double> anterior;
  vector<double> nuevo;
  
  double min = -1;
  double aux;

  for(size_t i = 1; i <= n_stations; i++){
    for(size_t j = 1; j <= last_city; j++){
      min = -1;
      if(i == 1){
        min = centroide(d, v, 0, j);
      }
      else{
        for(size_t a = 0; a < last_city; a++){
          aux = anterior[a-1] + centroide(d, v, a, j);
          
          if(min == -1){
            min = aux;
          }
          else{
            min = minimo(aux, min);
          }
        }
      }
      nuevo.push_back(min);
    }
    anterior = nuevo;
    nuevo.clear();
  }
  return min;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

/*

vector<double> assigments(const vector<double> &d, const vector<int> &v, size_t last_city, size_t n_stations){
  vector<double> e; // EMPLACEMENT
      e.push_back(0);
          e.push_back(2);
              e.push_back(5);

  vector<double> a; // ASSIGNED
  double min = DBL_MAX;
  double distancia;
  size_t pos;
  for(size_t i = 0; i < last_city; i++){  
      distancia = 0;
      min = 10000;
      for(size_t j = 0; j < e.size(); j++){       
        distancia = absoluto(d[e[j]] - d[i]) * v[j];
        if(distancia < min){
          min = distancia;
          pos = e[j];
        }
      }
    a.push_back(pos);
    cout << a[i] << " ";
  }
  return a;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Ignorar(char * argv[], int argc) {

	for (int i = 0; i<argc; i++) {

		if (((strcmp(argv[i], "--ignore_recursive") == 0))){
      return true;
    }
	}

	return false;
}
bool Iterativo(char * argv[], int argc) {

	for (int i = 0; i<argc; i++) {

		if (((strcmp(argv[i], "-t") == 0))){
      return true;
    }
	}

	return false;
}

bool Distinto(char * argv[], int argc) {
  bool es = true;
	for (int i = 0; i<argc; i++) {
		if ((strcmp(argv[i], "-t") == 0) || (strcmp(argv[i], "--ignore_recursive") == 0)){
      es = true;
    }
    else{
      if((strcmp(argv[i], "-f") == 0)){
        es = true;
        i++;
      }
      else{
        es = false;
      }
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

int main(int argc, char * argv[]){
  size_t c = 0;
  size_t g = 0;

  vector <double> d;
  vector <int> v;

  if(Distinto(argv, argc)){
    
    ifstream fich(argv[posfichero(argv, argc)]);
    
    if(fich.is_open()){
      string linea;
      
      int contar=0;
      unsigned int Inicio;
      unsigned int Final;

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
        else if (contar == 2) {
          Inicio = 0;
          Final = 0;
          double aux1;
            
          for(size_t i=0; i < c; i++){
            Final = linea.find (" ", Inicio);
            aux1 = atof(linea.substr(Inicio, Final).c_str());
            d.push_back(aux1);
            Inicio = Final+1;
          }
        contar++;
        }
      }
      fich.close();

////////////////////////////////////////////////////////////////////////////////////////////////////

      Matrix = new double *[c];
      for(size_t i=0; i<=c; i++){
        Matrix[i] = new double[g];
      }       
      iniciar(c, g);

      if(!Ignorar(argv, argc)){
        cout << "Recursive: " << cmin(d, v, c, g) << endl;
      }
      cout << "Memoization: " << cmin_memorization(d, v, c, g) << endl 
          << "Iterative (table): " << cmin_iterative(d, v, c, g) << endl 
          << "Iterative (vector): " << cmin_iterative_v(d, v, c, g) << endl
          << "Emplacements: ¿?" << endl 
          << "Assignments: ¿?";
          //assigments(d, v, c, g); 
          cout  << endl 
          << "Assignment cost: " << cmin_iterative(d, v, c, g) << endl;

      if(Iterativo(argv, argc)){
        cmin_iterative(d, v, c, g);
        cout << "Iterative table: " << endl;
        mostrarMatrix(c, g);
      }  
    }
    else{
      cerr << "ERROR: can’t open file: " << argv[posfichero(argv, argc)] << "." << endl << "Usage:" 
      << endl <<"mca [-t] [--ignore_recursive] -f file";
    }
  }
  else{
    cerr << "ERROR: unknown option " << argv[Raro(argv, argc)] << "." << endl << "Usage:" 
      << endl << "mca [-t] [--ignore_recursive] -f file";
  }
}
