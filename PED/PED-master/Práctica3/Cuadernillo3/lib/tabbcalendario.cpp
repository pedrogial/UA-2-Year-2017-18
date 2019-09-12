#include "../include/tabbcalendario.h"
#include <queue>

//Nodo ABB
//Constructor por defecto
TNodoABB::TNodoABB(){

}
//Constructor copia
TNodoABB::TNodoABB(const TNodoABB &o) :iz(o.iz), de(o.de), item(o.item) { 

}

//Destructor
TNodoABB::~TNodoABB(){ 

}

// Sobrecarga del operador asignación
TNodoABB &TNodoABB::operator=(const TNodoABB &o){ 
	if(this != &o){
		item = o.item;
		iz = o.iz;
		de = o.de;
	}
	return *this;
}


//Arbol ABB
TCalendario TABBCalendario::Auxiliar() const{
	TCalendario aux;
	if(raiz != NULL){
		if(raiz->de.raiz != NULL){
			aux = raiz->de.Auxiliar();	
		}
		else{
			aux = raiz->item;
		}
	}
	return aux;
}

// AUXILIAR : d evuelve el recorrido en inorden
void TABBCalendario::InordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		raiz->iz.InordenAux(c, p);
		c[p] = raiz->item;
		p++;
		raiz->de.InordenAux(c, p);
	}
}

// AUXILIAR : d evuelve el recorrido en preorden
void TABBCalendario::PreordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		c[p] = raiz->item;
		p++;
		raiz->iz.PreordenAux(c, p);
		raiz->de.PreordenAux(c, p);
	}
}

// AUXILIAR : d evuelve el recorrido en postorden
void TABBCalendario::PostordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		raiz->iz.PostordenAux(c, p);
		raiz->de.PostordenAux(c, p);
		c[p] = raiz->item;
		p++;
	}
}

// Constructor por defecto
TABBCalendario::TABBCalendario(){
	raiz = NULL;
}

// Constructor de copia
TABBCalendario::TABBCalendario(const TABBCalendario &o){
	if(o.raiz != NULL){
		raiz = new TNodoABB();
		raiz->item = o.raiz->item;
		raiz->iz = o.raiz->iz;
		raiz->de = o.raiz->de;
	}
	else{
		raiz = NULL;
	}
}

// Destructor
TABBCalendario::~TABBCalendario(){
	if(raiz != NULL){
		delete raiz;
		raiz = NULL;
	}
}

void TABBCalendario::clear(){
	if(raiz != NULL){
		delete raiz;
		raiz = NULL;
	}
}

// Sobrecarga del operador asignación
TABBCalendario &TABBCalendario::operator=(const TABBCalendario &o){
	if(this != &o){	
		clear();
		if(o.raiz != NULL){
			raiz = new TNodoABB();
			raiz->item = o.raiz->item;
			raiz->iz = o.raiz->iz;
			raiz->de = o.raiz->de;
		}
	}
	return *this;
}

// Sobrecarga del operador igualdad
bool TABBCalendario::operator==(const TABBCalendario &c) const{
	bool iguales = false;

	if(raiz != NULL && c.raiz == NULL || raiz == NULL && c.raiz != NULL){
		iguales = false;
	}
	else{
		if(raiz == NULL && c.raiz == NULL){
			iguales = true;
		}
		else{
			TVectorCalendario inorden, inordenc;
			inorden = Inorden();
			inordenc = c.Inorden();
			if(inordenc != inorden){
				iguales = false;
			}
			else{
				iguales = true;
			}
		}
	}
	return iguales;
}

// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TABBCalendario::EsVacio() const{
	return raiz == NULL;
}

// Inserta el elemento en el árbol
bool TABBCalendario::Insertar(const TCalendario &c){
	bool insertar;
	
	if(raiz == NULL){
		raiz = new TNodoABB();
		raiz->item = c;
		insertar = true;
	}
	else{
		if(raiz->item > c){
			insertar = raiz->iz.Insertar(c);
		}
		else{
			if(raiz->item < c){
				insertar = raiz->de.Insertar(c);
			}
			else{
				insertar = false;
			}
		}
	}
	return insertar;
}

// Borra el elemento en el árbol
bool TABBCalendario::Borrar(const TCalendario &c){
	bool borrar = false;
	TCalendario mayorIz;
	TNodoABB *ptB;

	if(raiz != NULL){
		if(raiz->item > c){
			borrar = raiz->iz.Borrar(c);
		}
		else{
			if(raiz->item < c){
				borrar = raiz->de.Borrar(c);
			}
			else{
				borrar = true;
				if(raiz->iz.raiz == NULL && raiz->de.raiz == NULL){
					delete raiz;
					raiz = NULL;
				}
				else{
					//Solo hijo izq
					if(raiz->iz.raiz != NULL && raiz->de.raiz == NULL){
						ptB = raiz;
						raiz = raiz->iz.raiz;
						ptB->iz.raiz = NULL; 
						delete ptB;
					}
					else{
						//Solo hijo der
						if(raiz->iz.raiz == NULL && raiz->de.raiz != NULL){
							ptB = raiz;
							raiz = raiz->de.raiz;
							ptB->de.raiz = NULL; 
							delete ptB;
						}
						else{
							//Los dos
							if(raiz->iz.raiz != NULL && raiz->de.raiz != NULL){
								mayorIz = raiz->iz.Auxiliar();
								raiz->item = mayorIz;
								raiz->iz.Borrar(mayorIz);
							}
						}
					}
				}
			}
		}
	}

	return borrar;
}

// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TABBCalendario::Buscar(const TCalendario &c) const{
	bool buscar = false;

	if(raiz != NULL){
		if(raiz->item == c){
			buscar = true;
		}
		else{
			if(raiz->item > c){
				buscar = raiz->iz.Buscar(c);
			}
			else{
				buscar = raiz->de.Buscar(c);
			}
		}
	}
	return buscar;
}

// Devuelve el elemento de la raíz del árbol
TCalendario TABBCalendario::Raiz() const{
	TCalendario c;
	if(raiz != NULL){
		c = raiz->item;
	}
	return c;
}

int TABBCalendario::Altura() const {
	int a, iz, de;
	
	if(raiz != NULL) {
		iz = raiz->iz.Altura();
		de = raiz->de.Altura();
		if(iz > de){
			a = iz + 1;
		}
		else{
			a = de + 1;
		}
	}
	else{
		a = 0;
	}
	
	return a;
}

int TABBCalendario::Nodos() const{
	int n;

	if(raiz == NULL){
		n = 0;
	}
	else{
		n = raiz->iz.Nodos() + raiz->de.Nodos() + 1;
	}
	return n;
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TABBCalendario::NodosHoja() const {
	int nh = 0;
	if(raiz != NULL){
		if(raiz->iz.raiz == NULL && raiz->de.raiz == NULL){
			nh = 1;
		}
		else{
			nh += raiz->iz.NodosHoja();
			nh += raiz->de.NodosHoja();
		}
	}
	return nh;
}	

// Devuelve el recorrido en inorden sobre un vector
TVectorCalendario TABBCalendario::Inorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	InordenAux(recorrido, pos);	
	return recorrido;
}

// Devuelve el recorrido en preorden sobre un vector
TVectorCalendario TABBCalendario::Preorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	PreordenAux(recorrido, pos);	
	return recorrido;
}

// Devuelve el recorrido en postorden sobre un vector
TVectorCalendario TABBCalendario::Postorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	PostordenAux(recorrido, pos);	
	return recorrido;
}

// Devuelve el recorrido en niveles
TVectorCalendario TABBCalendario::Niveles() const{
	queue<TNodoABB *> cola; 
	TVectorCalendario vector(Nodos()); 
	TNodoABB *paux; 
	int p = 1;

	cola.push(raiz);
	while(cola.empty() == false){
		paux = cola.front();
		cola.pop();

		if(paux != NULL){
			cola.push(paux->iz.raiz);
			cola.push(paux->de.raiz);
			vector[p++] = paux->item;
		}
	}
	return vector;
}

// Suma de dos ABB
TABBCalendario TABBCalendario::operator+(const TABBCalendario &a) const {
	TABBCalendario aux(*this);
	TVectorCalendario v = a.Inorden();
	int i;

	for(i = 1; i <= v.Tamano(); i++){
		aux.Insertar(v[i]);
	}
	return aux;
}

// Resta de dos ABB
TABBCalendario TABBCalendario::operator-(const TABBCalendario &a) const {
	TABBCalendario aux;
	TVectorCalendario v = this->Inorden();
	int i;

	for(i = 1; i <= v.Tamano(); i++){
		if(a.Buscar(v[i]) == false){
			aux.Insertar(v[i]);			
		}
	}	
	return aux;
}

// Sobrecarga del operador salida
ostream &operator<<(ostream &os, TABBCalendario &abb){
	os << abb.Niveles() << endl;
	return os;
}