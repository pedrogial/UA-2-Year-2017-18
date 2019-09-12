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

void iniciar(size_t ciudades){
  for(size_t i=0; i< ciudades; i++){
    for(size_t j=0; j< ciudades; j++){
        Matrix[j][i] = -1;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int menor_distancia(size_t c, size_t tam, int &pos){
  int menor = -1;
  if(Matrix[c][0] != 0){
    menor = Matrix[c][0];
    pos = 0;
  }
  else{
    menor = Matrix[c][1];
    pos = 1;
  }

  for(size_t i = 0; i < tam; i++){
    if(menor > Matrix[c][i] && Matrix[c][i] != 0){
      menor = Matrix[c][i];
      pos = i;
    }
  } 

  return menor;
}

int menor_coste(vector<int>& costes){
  int pos = 0;
  int menor = costes[0];

  for(int i = 0; i < costes.size(); i++){
    if(menor < costes[i]){
      menor = costes[i];
      pos = i;
    }
  }
  return pos;
}

void rellenar_costes(vector<int>& costes){

}
void Emplacements (int coste, vector<int>& rep, size_t cc, size_t g,  vector<double>& v, vector<int>& costes){
  int pos = 0;

  for(size_t i = 0; i < (cc-g); i++){

    if(i = 0){
      for(size_t j = 0; j < cc; j++){
        costes[j] = menor_distancia(j, cc, pos) * v[j];
      }
      menor_distancia(menor_coste(costes), cc, pos);
      rep[menor_coste(costes)] = pos;

    }
    else{
      for(size_t j = 0; j < cc; j++){
        
        costes[j] = menor_distancia(j, cc, pos) * v[j];
      }
      menor_distancia(menor_coste(costes), cc, pos);
      rep[menor_coste(costes)] = pos;
    }
  }
}



////////////////////////////////////////////////////////////////////////////////////////////////////

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

int main(int argc, char * argv[]){
  size_t c = 0;
  size_t g = 0;

  vector <double> d;
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
            for(size_t i=0; i<=c; i++){
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
      
      repostages [c];
      
      for (size_t i=0; i<c; i++){
        repostages [i] = i;
      }
      int coste = 0;

      costes [c];
      
      for (size_t i=0; i<c; i++){
        costes [i] = 0;
      }

////////////////////////////////////////////////////////////////////////////////////////////////////
      
      for(size_t i = 0; i < c; i++){
        for(size_t j = 0; j < c; j++){
          cout << Matrix[j][i] << " ";
        }
        cout << endl;
      }
      
      cout << c << endl;
      cout << g << endl;
      for(size_t i = 0; i < c; i++){
        cout << v[i] ;
        cout << " ";
      }
      cout << endl;
      cout << "Greedy: ";
      Emplacements(coste, repostages, c, g, d, costes); 
      cout << endl;
      cout << "Emplacements: " << endl;
    }
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
