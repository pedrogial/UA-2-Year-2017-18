#include "../include/tavlcalendario.h"

//TNodoAVL
TNodoAVL::TNodoAVL(){
	fe = 0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &o):iz(o.iz), de(o.de), item(o.item), fe(o.fe){

}

TNodoAVL &TNodoAVL::operator=(const TNodoAVL &n){
	if(this != &n){
		item = n.item;
		iz = n.iz;
		de = n.de;
		fe = n.fe;
	}
	return *this;
}

TNodoAVL::~TNodoAVL(){
	fe = 0;
}

//TAVLCalendario
TAVLCalendario::TAVLCalendario(){
	raiz = NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &o){
	if(o.raiz != NULL){
		raiz = new TNodoAVL();
		raiz->item = o.raiz->item;
		raiz->iz = o.raiz->iz;
		raiz->de = o.raiz->de;
		raiz->fe = o.raiz->fe;
	}
	else{
		raiz = NULL;
	}
}

TAVLCalendario::~TAVLCalendario(){
	if(raiz != NULL){
		delete raiz;
		raiz = NULL;
	}
}

void TAVLCalendario::clear(){
	if(raiz != NULL){
		delete raiz;
		raiz = NULL;
	}
}

TAVLCalendario &TAVLCalendario::operator=(const TAVLCalendario &o){
	if(this != &o){
		clear();
		if(o.raiz != NULL){
			raiz = new TNodoAVL();
			raiz->item = o.raiz->item;
			raiz->iz = o.raiz->iz;
			raiz->de = o.raiz->de;
			raiz->fe = o.raiz->fe;
		}
	}
	return *this;
}

bool TAVLCalendario::EsVacio() const{
	bool vacio = false;
	if(raiz == NULL){
		vacio = true;
	}
	return vacio;
}

bool TAVLCalendario::operator==(const TAVLCalendario &c) const{
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

bool TAVLCalendario::operator!=(const TAVLCalendario &de) const{
	return !(*this == de);
}

bool TAVLCalendario::Insertar(const TCalendario &c){
	bool insertado, crece;
	insertado = Insertar(c, crece);	
	return insertado;
}

bool TAVLCalendario::Buscar(const TCalendario &c) const{
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

bool TAVLCalendario::Borrar(const TCalendario &c){
	bool borrado, decrece;
	borrado = Borrar(c,decrece);
	return borrado;
}

TCalendario TAVLCalendario::Raiz() const{
	TCalendario c;
	if(raiz != NULL){
		c = raiz->item;
	}
	return c;
}

int TAVLCalendario::Nodos() const{
	int n;

	if(raiz == NULL){
		n = 0;
	}
	else{
		n = raiz->iz.Nodos() + raiz->de.Nodos() + 1;
	}
	return n;
}

int TAVLCalendario::NodosHoja() const {
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

int TAVLCalendario::Altura() const {
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

TVectorCalendario TAVLCalendario::Inorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	InordenAux(recorrido, pos);	
	return recorrido;
}

void TAVLCalendario::InordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		raiz->iz.InordenAux(c, p);
		c[p] = raiz->item;
		p++;
		raiz->de.InordenAux(c, p);
	}
}

TVectorCalendario TAVLCalendario::Preorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	PreordenAux(recorrido, pos);	
	return recorrido;
}

void TAVLCalendario::PreordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		c[p] = raiz->item;
		p++;
		raiz->iz.PreordenAux(c, p);
		raiz->de.PreordenAux(c, p);
	}
}

TVectorCalendario TAVLCalendario::Postorden() const{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;

	PostordenAux(recorrido, pos);	
	return recorrido;
}

void TAVLCalendario::PostordenAux(TVectorCalendario &c, int &p) const{
	if(raiz != NULL){
		raiz->iz.PostordenAux(c, p);
		raiz->de.PostordenAux(c, p);
		c[p] = raiz->item;
		p++;
	}
}

TCalendario TAVLCalendario::Auxiliar() const{
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

ostream & operator<<(ostream &os, const TAVLCalendario &v){
	os << v.Inorden();
	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void TAVLCalendario::DD(){
	//Base
	TNodoAVL *ptB, *ptD;
	ptB = raiz;
	ptD = ptB->de.raiz;
	//Cambios
	raiz = ptD;
	ptB->de.raiz = ptD->iz.raiz;
	ptD->iz.raiz = ptB;
	//Cambios de fe
	raiz->fe = 0;
	raiz->iz.raiz->fe = 0;
	
}

void TAVLCalendario::II(){
	//Base
	TNodoAVL *ptB, *ptD;
	ptD = raiz;
	ptB = ptD->iz.raiz;
	//Cambios
	raiz = ptB;
	ptD->iz.raiz = ptB->de.raiz;
	ptB->de.raiz = ptD;
	//Cambios de fe
	raiz->fe = 0;
	raiz->de.raiz->fe = 0; 
}

void TAVLCalendario::ID(){
	//Base
	TNodoAVL *ptB, *ptD, *ptF;
	ptF = raiz;
	ptB = ptF->iz.raiz;
	ptD = ptB->de.raiz;
	//Cambios
	raiz = ptD;
	ptF->iz.raiz = ptD->de.raiz;
	ptD->de.raiz = ptF;
	ptB->de.raiz = ptD->iz.raiz;
	ptD->iz.raiz = ptB;
	//Cambios de fe
	if(ptD->fe == 1){
		ptD->fe = 0;
		ptD->iz.raiz->fe = -1;
		ptD->de.raiz->fe = 0;
	}
	else{
		if(ptD->fe == -1){
			ptD->fe = 0;
			ptD->iz.raiz->fe = 0;
			ptD->de.raiz->fe = 1;
		}
		else{
			ptD->fe = 0;
			ptD->iz.raiz->fe = 0;
			ptD->de.raiz->fe = 0;
		}
	}
}

void TAVLCalendario::DI(){
	//Base
	TNodoAVL *ptB, *ptD, *ptF;
	ptB = raiz;
	ptF = ptB->de.raiz;
	ptD = ptF->iz.raiz;
	//Cambios
	raiz = ptD;
	ptF->iz.raiz = ptD->de.raiz;
	ptD->de.raiz = ptF;
	ptB->de.raiz = ptD->iz.raiz;
	ptD->iz.raiz = ptB;
	//Cambios de fe
	if(ptD->fe == 1){
		ptD->fe = 0;
		ptD->iz.raiz->fe = -1;
		ptD->de.raiz->fe = 0;
	}
	else{
		if(ptD->fe == -1){
			ptD->fe = 0;
			ptD->iz.raiz->fe = 0;
			ptD->de.raiz->fe = 1;
		}
		else{
			ptD->fe = 0;
			ptD->iz.raiz->fe = 0;
			ptD->de.raiz->fe = 0;
		}
	}

}


bool TAVLCalendario::Insertar(const TCalendario &c, bool &crece){
	bool insertar, creceIz, creceDe;
	creceIz = creceDe = insertar = false;
	
	if(raiz == NULL){
		raiz = new TNodoAVL();
		raiz->fe = 0;
		raiz->item = c;
		crece = true;
		insertar = true;
	}
	else{
		if(raiz->item == c){
			insertar = false;
		}
		else{
			if(raiz->item > c){
				insertar = raiz->iz.Insertar(c, creceIz);
			}
			else{
				insertar = raiz->de.Insertar(c, creceDe);
			}
			//Cambio	
			if(creceIz == true){
				raiz->fe--;
				switch(raiz->fe){
					case 0: crece = false;
					break;
					case -1: crece = true;
					break;
					case -2: crece = false;
						switch(raiz->iz.raiz->fe){
							case -1: II();
							break;
							case +1: ID();
							break;
						}
					break;
				}
			}
			else{
				if(creceDe == true){
					raiz->fe++;
					switch(raiz->fe){
						case 0: crece = false;
						break;
						case 1: crece = true;
						break;
						case 2: crece = false;
							switch(raiz->de.raiz->fe){
								case +1: DD();
								break;
								case -1: DI();
								break;
							}
						break;
					}
				}
			}
		}
	}
	return insertar;
}

bool TAVLCalendario::Borrar(const TCalendario &c, bool &decrece){
	bool borrar, decreceIz, decreceDe;
	TCalendario mayorIz;
	decreceIz = decreceDe = borrar = false;
	TNodoAVL *ptB;

	if(raiz != NULL){
		if(raiz->item > c){
			borrar = raiz->iz.Borrar(c, decreceIz);
		}
		else{
			if(raiz->item < c){
				borrar = raiz->de.Borrar(c, decreceDe);
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
							mayorIz = raiz->iz.Auxiliar();
							raiz->item = mayorIz;
							raiz->iz.Borrar(mayorIz);
							
						}
					}
				}
			}
			//Cambio
			if(decreceDe == true){
				raiz->fe--;
				switch(raiz->fe){
					case 0: decrece = true;
					break;
					case -1: decrece = false;
					break;
					case -2: decrece = true;
						switch(raiz->iz.raiz->fe){
							case -1: II();
							break;
							case +1: ID();
							break;
						}
					break;
				}
			}
			else{
				if(decreceIz == true){
					raiz->fe++;
					switch(raiz->fe){
						case 0: decrece = true;
						break;
						case 1: decrece = false;
						break;
						case 2: decrece = true;
							switch(raiz->de.raiz->fe){
								case +1: DD();
								break;
								case -1: DI();
								break;
							}
						break;
					}
				}
			}
		}
	}
	return borrar;
}