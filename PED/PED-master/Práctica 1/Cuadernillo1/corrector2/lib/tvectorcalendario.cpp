#include "tvectorcalendario.h"


TVectorCalendario::TVectorCalendario(){
	c = NULL;
	tamano = 0;
}

TVectorCalendario::TVectorCalendario(int tam){
	if(tam > 0){
		c = new TCalendario[tam];
		tamano = tam;
	}
	else{
		tamano = 0;
		c = NULL;
	}
}

TVectorCalendario::TVectorCalendario(const TVectorCalendario &aux){
	if(aux.tamano != 0){
		c = new TCalendario[aux.tamano];
		tamano = aux.tamano;
		for(int i = 0; i < tamano; i++){
			c[i] = aux.c[i];
		}
	}
	else{
		c = NULL;
		tamano = 0;
	}
}

TVectorCalendario::~TVectorCalendario(){
	if(c != NULL){
		delete [] c;
		c = NULL;
		tamano = 0;
	}
}

TVectorCalendario &TVectorCalendario::operator=(const TVectorCalendario &aux){
	if(this != &aux){
		if(c != NULL){
			delete [] c;
			c = NULL;
			tamano = 0;
		}
		if(aux.tamano != 0)
		{
			c = new TCalendario[aux.tamano];
			tamano = aux.tamano;
			for(int i = 0;i < tamano; i++)
				c[i]=aux.c[i];	
		}
	}
	return *this;
}

bool TVectorCalendario::operator==(const TVectorCalendario &aux) const{
	bool iguales = false;	
	if(tamano == aux.tamano){
		iguales = true;	
		for(int i = 0; i < tamano && iguales; i++)
			if(aux.c[i] != c[i]) 
				iguales = false;
	}
	return iguales;
}

bool TVectorCalendario::operator!=(const TVectorCalendario &aux) const{
	return !(aux == *this);
}

// left-hand operator
TCalendario &TVectorCalendario::operator[](int pos){
	if(pos >= 1 && pos <= tamano){	
		return c[pos-1];
	}
	else{
		return error;
	}
}

// right-hand operator
TCalendario TVectorCalendario::operator[](int pos) const{
	if(pos >= 1 && pos <= tamano){	
		return c[pos-1];
	}
	else
		return error;
}

int TVectorCalendario::Tamano() const{
	return tamano;	
}

int TVectorCalendario::Ocupadas() const{
	int cont = 0;
	
	for(int i = 0; i < tamano; i++)
		if(c[i].EsVacio() == false)
			cont++;
	return cont;
}

bool TVectorCalendario::ExisteCal(const TCalendario &cal) const{
	bool existe = false;
	for (int i = 0; i < tamano && !existe; i++){
		if(c[i] == cal)
			existe = true;
	}
	return existe;
}

bool TVectorCalendario::Redimensionar(int tam){
	bool exito = false;
	TCalendario *aux = NULL;
	
	if(tamano != tam && tam > 0){
		exito = true;
		aux = new TCalendario [tam];
		for(int i = 0; i < tam && i < tamano; i++){
			aux[i] = c[i];
		}
		if(c != NULL){
				delete []c;
				c = NULL;
		}
		c = aux;
		tamano = tam;
	} 
	return exito;
}

void TVectorCalendario::MostrarMensajes(int dia,int mes,int anyo) const{
	bool mostrar, primero;

	cout << "[";
	if(tamano > 0){
		primero = true;
		for(int i = 0; i < tamano; i++){
			mostrar = false;			
			if(c[i].Anyo() > anyo )
				mostrar = true;
			else {
				if(c[i].Anyo() == anyo){
					if(c[i].Mes() > mes)
						mostrar = true;
					else{
						if(c[i].Mes() == mes){
							if(c[i].Dia() >= dia)
								mostrar = true;
						}
					}
				}
			}
			if(mostrar){
				if(!primero){
					cout << ", ";
				}
				else{
					primero = false;
				}
				cout << c[i];
			}
			
		}
	}
	cout<<"]";
}

ostream &operator<<(ostream &o, const TVectorCalendario &t){
	o << "[";
	if(t.tamano > 0){
		for (int i = 0; i < t.tamano; i++){
			o << "(" << i + 1 << ") " << t.c[i];
			if(i < t.tamano-1)
				o<<", ";
		}
	}
	o << "]";
	return o;
}

