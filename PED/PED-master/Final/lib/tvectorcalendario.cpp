#include <stdio.h>  
#include "../include/tvectorcalendario.h"

// Constructor por defecto
TVectorCalendario::TVectorCalendario(){
    c = NULL;
    tamano = 0;
}

// Constructor a partir de un tamaño
TVectorCalendario::TVectorCalendario(int t){
   if(t > 0){
        c = new TCalendario[t];
	    tamano = t;
    }
    else{       
        c = NULL;
        tamano = 0;
    }
}

// Constructor de copia
TVectorCalendario::TVectorCalendario(const TVectorCalendario &o){
    if(o.tamano != 0){
		c = new TCalendario[o.tamano];
		tamano = o.tamano;

		for(int i = 0; i < tamano; i++){
			c[i] = o.c[i];
		}
	}
    else{
        c = NULL;
        tamano = 0;
    }
}

// Destructor
TVectorCalendario::~TVectorCalendario(){
	if(c != NULL){
		delete [] c;
		c = NULL;
		tamano = 0;
	}
}

// Sobrecarga del operador asignación
TVectorCalendario& TVectorCalendario:: operator=(const TVectorCalendario &aux){
   if(this != &aux){
        (*this).~TVectorCalendario();      
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

// Sobrecarga del operador corchete (parte IZQUIERDA)
// Las posiciones van desde 1 (no desde 0) hasta el tamaño del vector
TCalendario& TVectorCalendario::operator[](int i){
    if(i >= 1 && i <= tamano){ //Si i = 1 entonces c[0]
        return c[i - 1];
    }
    else{
        return error;
    }
}

// Sobrecarga del operador corchete (parte DERECHA)
TCalendario TVectorCalendario::operator[](int i) const{
    if(i >= 1 && i <= tamano){
        return c[i - 1];
    }
    else{
        return error;
    }
}

// Sobrecarga del operador igualdad
bool TVectorCalendario::operator==(const TVectorCalendario &o) const{
    bool es = false;	
    int i;
	if(o.tamano == tamano){
		es = true;

		for(i = 0; i < tamano && es; i++){
			if(c[i] != o.c[i]){
				es = false;
            }
        }
	}
	return es;
}

// Sobrecarga del operador desigualdad
bool TVectorCalendario::operator!=(const TVectorCalendario &o) const{
    return !(o == *this);
}

// Tamaño del vector (posiciones TOTALES)
int TVectorCalendario::Tamano() const{
    return tamano;
}

// Cantidad de posiciones OCUPADAS (no vacías) en el vector
int TVectorCalendario::Ocupadas() const{
    TCalendario vacio; //Calendario vacio con el que compara
    int cant = 0;
    for(int i = 0; i < tamano; i++){//**
        if(vacio !=c[i]){
            cant++;
        } 
    }
    return cant;

}

// Devuelve true si existe el calendario en el vector(Un buscar de toda la vida)
bool TVectorCalendario::ExisteCal(const TCalendario &o)const{
    bool es = false;
	for (int i = 0; i < tamano && !es; i++){
		if(c[i] == o){
			es = true;
        }
	}
	return es;   
}

// Mostrar por pantalla mensajes de TCalendario en el vector, de fecha IGUAL O POSTERIOR a la pasada
void TVectorCalendario::MostrarMensajes(int d,int m, int a) const{
    TCalendario o(d, m, a, NULL);
    int p = 0;
    cout << "[";
    for(int i = 0; i < tamano; i++){
        if(o < c[i]){//**
            if(p != 0){
                cout << ", ";
            }
            cout << c[i];
            p++;
        }
    }
    cout << "]";
}

// REDIMENSIONAR el vector de TCalendario
bool TVectorCalendario::Redimensionar(int n){
    bool done = false;
    if(n>0 && n != tamano){
        done = true;
        TCalendario *co;
        co = new TCalendario[n];
        
        for(int i = 0; i < tamano && i < n; i++){
            co[i] = c[i];//Pasamos los datos de c a co
        }
        if(c!= NULL){ //Enviamos los datos a c
            delete[] c;
            c = NULL;
            c = co;
            tamano = n;
        }
        else{
            c = co;
            tamano = n;
        }
        
    }
    return done;
}

// Sobrecarga del operador salida
ostream & operator<<(ostream &os, const TVectorCalendario &v){
    int i;
    os << "[";
    if(v.tamano > 0){
        for(i = 1; i <= v.tamano; i++){ //Empieza con 1 ya que el operador nuevo tambien
            if(i != 1){
                os << ", ";
            }
            os << "(" << i << ") " << v[i];
        }
    }
    os << "]";
    return os;
}