#include "../include/tabbcalendario.h"
#include <queue>

//Nodo ABB
TNodoABB::TNodoABB(){

}

TNodoABB::TNodoABB(const TNodoABB &o) :iz(o.iz), de(o.de), item(o.item) { 

}

TNodoABB::~TNodoABB(){ 

}

TNodoABB &TNodoABB::operator=(const TNodoABB &o){ 
	if(this != &o){
		item = o.item;
		iz = o.iz;
		de = o.de;
	}
	return *this;
}


//Arbol ABB
void TABBCalendario::InordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		raiz->iz.InordenAux(c, p);
		c[p] = raiz->item;
		p++;
		raiz->de.InordenAux(c, p);
	}
}

void TABBCalendario::PreordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		c[p] = raiz->item;
		p++;
		raiz->iz.PreordenAux(c, p);
		raiz->de.PreordenAux(c, p);
	}
}

void TABBCalendario::PostordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		raiz->iz.PostordenAux(c, p);
		raiz->de.PostordenAux(c, p);
		c[p] = raiz->item;
		p++;
	}
}

TCalendario TABBCalendario::BuscarMayor() const{
	TCalendario c;
	if(raiz != NULL){
		if(raiz->de.raiz == NULL){
			c = raiz->item;
		}
		else{
			c = raiz->de.BuscarMayor();
		}
	}
	return c;
}

TABBCalendario::TABBCalendario(){
	raiz = NULL;
}

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

bool TABBCalendario::EsVacio() const{
	return raiz == NULL;
}

bool TABBCalendario::Insertar(const TCalendario &c){
	bool insertar;
	
	if(raiz == NULL){
		raiz = new TNodoABB;
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

bool TABBCalendario::Borrar(const TCalendario &c){
	bool borrado = false;
	TCalendario mayorIz;
	TNodoABB *ptB;

	if(raiz != NULL){
		if(raiz->item > c){
			borrado = raiz->iz.Borrar(c);
		}
		else{
			if(raiz->item < c){
				borrado = raiz->de.Borrar(c);
			}
			else{
				borrado = true;
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
								mayorIz = raiz->iz.BuscarMayor();
								raiz->item = mayorIz;
								raiz->iz.Borrar(mayorIz);
							}
						}
					}
				}
			}
		}
	}

	return borrado;
}

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

TCalendario TABBCalendario::Raiz() const{
	TCalendario c;
	if(raiz != NULL){
		c = raiz->item;
	}
	return c;
}
/*
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
*/
int TABBCalendario::Altura() const
{
	int h = 0, hiz = 0, hde = 0;
	
	if(raiz)
	{
		hiz = raiz->iz.Altura();
		hde = raiz->de.Altura();
		if(hiz > hde)
			h = hiz + 1;
		else
			h = hde + 1;
	}
	
	return h;
}/*
int TABBCalendario::Nodos() const{
	int n;

	if(raiz == NULL){
		n = 0;
	}
	else{
		n = raiz->iz.Nodos() + raiz->de.Nodos() + 1;
	}
	return n;
}*/

int TABBCalendario::Nodos() const
{
	int n = 0;
	
	if(raiz)
		n = raiz->iz.Nodos() + raiz->de.Nodos() + 1;	

	return n;
}

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

TVectorCalendario TABBCalendario::Inorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	InordenAux(recorrido, pos);	
	return recorrido;
}

TVectorCalendario TABBCalendario::Preorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	PreordenAux(recorrido, pos);	
	return recorrido;
}

TVectorCalendario TABBCalendario::Postorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	PostordenAux(recorrido, pos);	
	return recorrido;
}


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

TABBCalendario TABBCalendario::operator+(const TABBCalendario &a) const {
	TABBCalendario aux(*this);
	TVectorCalendario v = a.Inorden();
	int i;


	for(i = 1; i <= v.Tamano(); i++){
		aux.Insertar(v[i]);
	}
	return aux;
}

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

ostream &operator<<(ostream &os, TABBCalendario &abb){
	os << abb.Niveles() << endl;
	return os;
}