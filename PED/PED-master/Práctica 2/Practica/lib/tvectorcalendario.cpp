#include <stdio.h>  
#include "../include/tvectorcalendario.h"


TVectorCalendario::TVectorCalendario(){
    c = NULL;
    tamano = 0;
}

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


TVectorCalendario::~TVectorCalendario(){
	if(c != NULL){
		delete [] c;
		c = NULL;
		tamano = 0;
	}
}

void TVectorCalendario::clear(){
	if(c != NULL){
		delete [] c;
		c = NULL;
		tamano = 0;
	}
}

TVectorCalendario& TVectorCalendario:: operator=(const TVectorCalendario &aux){
   if(this != &aux){
        (*this).clear();      
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


TCalendario& TVectorCalendario::operator[](int i){
    if(i >= 1 && i <= tamano){
        return c[i - 1];
    }
    else{
        return error;
    }
}

TCalendario TVectorCalendario::operator[](int i) const{
    if(i >= 1 && i <= tamano){
        return c[i - 1];
    }
    else{
        return error;
    }
}


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

bool TVectorCalendario::operator!=(const TVectorCalendario &o) const{
    return !(o == *this);
}

int TVectorCalendario::Tamano() const{
    return tamano;
}

int TVectorCalendario::Ocupadas() const{
    TCalendario vacio;
    int cant = 0;
    for(int i = 0; i < tamano; i++){
        if(vacio !=c[i]){
            cant++;
        } 
    }
    return cant;

}

bool TVectorCalendario::ExisteCal(const TCalendario &o)const{
    bool es = false;
	for (int i = 0; i < tamano && !es; i++){
		if(c[i] == o){
			es = true;
        }
	}
	return es;   
}

void TVectorCalendario::MostrarMensajes(int d,int m, int a) const{
    TCalendario o(d, m, a, NULL);
    int p = 0;
    cout << "[";
    for(int i = 0; i < tamano; i++){
        if(o < c[i]){
            if(p != 0){
                cout << ", ";
            }
            cout << c[i];
            p++;
        }
    }
    cout << "]";
}

bool TVectorCalendario::Redimensionar(int n){
    bool done = false;
    if(n>0 && n != tamano){
        done = true;
        TCalendario *co;
        co = new TCalendario[n];
        
        for(int i = 0; i < tamano && i < n; i++){
            co[i] = c[i];                                     
        }
        if(c!= NULL){
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

ostream & operator<<(ostream &os, const TVectorCalendario &v){
    int i;
    os << "[";
    if(v.tamano > 0){
        for(i = 1; i <= v.tamano; i++){
            if(i != 1){
                os << ", ";
            }
            os << "(" << i << ") " << v[i];
        }
    }
    os << "]";
    return os;
}