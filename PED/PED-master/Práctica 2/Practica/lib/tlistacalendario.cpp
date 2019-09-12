#include <stdio.h>
#include "../include/tlistacalendario.h"


TNodoCalendario::TNodoCalendario(){
    siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &o){
    siguiente = o.siguiente;
    c = o.c;
}

TNodoCalendario::~TNodoCalendario(){
    siguiente = NULL;
}

TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &o){
    siguiente = o.siguiente;
    c = o.c;
    return *this;
}










TListaPos::TListaPos(){
    pos = NULL;
}

TListaPos::~TListaPos(){
    pos = NULL;
}

TListaPos::TListaPos(const TListaPos &o){
    pos = o.pos;
}

TListaPos & TListaPos::operator=(const TListaPos &o){
    pos = o.pos;
    return *this;
}

bool TListaPos::operator==(const TListaPos &o) const{
    bool es = false;
        if (pos == o.pos) {
            es = true;
        }
    return es;
}

bool TListaPos::operator!=(TListaPos &o){
    return !(pos == o.pos);
}

TListaPos TListaPos:: Siguiente() const{
	TListaPos lista;
	if(pos==NULL)
		lista.pos=NULL;
	else
		lista.pos=pos->siguiente;

	return lista;
}

bool TListaPos::EsVacia() const{
    bool es = false;
    if(pos == NULL){
        es = true;
    }
    return es;
}










TListaCalendario::TListaCalendario() {
    primero = NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario &o){
    primero = NULL;
    *this = o;
}

TListaCalendario::~TListaCalendario(){
    TNodoCalendario *ptP;
    ptP = primero;

    while(ptP != NULL){
        primero = primero->siguiente;
        delete ptP;
        ptP = NULL;
        ptP = primero;
    }
}

void TListaCalendario::clear(){
    TNodoCalendario *ptP;
    ptP = primero;

    while(ptP != NULL){
        primero = primero->siguiente;
        delete ptP;
        ptP = NULL;
        ptP = primero;
    }
}

TListaCalendario & TListaCalendario:: operator=(const TListaCalendario &o){
	TNodoCalendario *ptP,*ptN, *ptA;
    ptP=o.primero;
    ptN=new TNodoCalendario();
    
    if(this != &o && ptP != NULL){
		this->clear();

		if(&o!=NULL){
			while(ptP!=NULL){
				if(primero!=NULL){
                    ptA->siguiente=ptN;
                }
                else{
					primero=ptN;
                }
				ptN->c=ptP->c;
				ptA=ptN;
				ptP=ptP->siguiente;

                ptN=new TNodoCalendario();
			}
		}
	}
	return *this;
}

bool TListaCalendario::operator==(const TListaCalendario &o)const{
    bool es = false;
    TNodoCalendario *ptP1, *ptP2;
    ptP1 = primero;
    ptP2 = o.primero;

    while(ptP1 != NULL && ptP2 != NULL && ptP1->c == ptP2->c){
        ptP1 = ptP1->siguiente;
        ptP2 = ptP2->siguiente;
    }
    if(ptP1 == NULL && ptP2 == NULL){
        es = true;
    }

    return es;
}
TListaCalendario TListaCalendario::operator+(const TListaCalendario &o) const{
    TListaCalendario lista;
	TNodoCalendario *ptA;
    ptA=o.primero;
	lista=*this;
	
    while(ptA!=NULL){
		lista.Insertar(ptA->c);
		ptA=ptA->siguiente;
	}
	
	return lista;
}

TListaCalendario TListaCalendario::operator-(const TListaCalendario &o) const{
    TListaCalendario lista;
	TNodoCalendario *ptL;
	ptL=o.primero;
    lista=*this;

	while(ptL!=NULL){
		lista.Borrar(ptL->c);
		ptL=ptL->siguiente;
	}
	
	return lista;
}

bool TListaCalendario::Insertar(const TCalendario &c){
    TNodoCalendario *ptN, *ptA, *ptP;
    bool mayor, insertar;
    mayor=insertar=false;
    ptA = NULL;
    ptP = primero;
    //Creamos el nuevo nodo con los datos del calendario
    ptN = new TNodoCalendario();
    ptN->c=c;   
    while(ptP != NULL && !mayor){
        if(ptP->c > c){
            mayor = true;
        }
        else{
            if(ptP->c == c){ 
                mayor = false;
            }
            else{
                ptA = ptP;
                ptP = ptP->siguiente;
            }
        }
    }
    //Cuidao ahí
    if(ptP == NULL){
        mayor = true;
    }
    //Posiciones
    if(mayor){
        //Al final
        if(ptP == NULL && ptA != NULL){
            ptN->siguiente = ptP;
            ptA->siguiente = ptN;
        }
        else{
            //Al principio
            if(ptA == NULL){
                //cout << "hola" << endl;
                ptN->siguiente = ptP;
                primero = ptN;
            }
            else{
                //Por Medio :)
                if(ptP != NULL && ptA != NULL){
                    ptA->siguiente = ptN;
                    ptN->siguiente = ptP;
                }
                
            }
        }
        insertar = true;
    }
    return insertar;
}

bool TListaCalendario::Borrar (const TCalendario &c){
    TNodoCalendario *ptN, *ptA, *ptP;
    bool mayor, borrar;
    mayor=borrar=false;
    ptA = NULL;
    ptP = primero;
    ptN = new TNodoCalendario();
    ptN->c=c;

    while(ptP && !mayor){
        if(ptP->c > ptN->c){
            mayor = true;
        }
        else{
            if(ptP->c == ptN->c){
                mayor = true;
            }
            else{
                ptA = ptP;
                ptP = ptP->siguiente;
            }
        }
    }

    if(mayor){
        if(ptP->c == ptN->c){
            if(ptP == NULL){
                ptA->siguiente = NULL;
            }
            else{
                if(ptP == primero){
                    primero = primero->siguiente;
                }else{
                    ptA->siguiente = ptP->siguiente;
                }
            }
            delete ptP;
            ptP = NULL;
            borrar = true;
        }
    }
    return borrar;
}

bool TListaCalendario::Borrar (const TListaPos &p){
TNodoCalendario *ptA, *ptP;
    bool mayor, borrar;
    mayor=borrar=false;
    ptA = NULL;
    ptP = primero;
    
    while(ptP != NULL && !mayor){
        if(ptP > p.pos){
            mayor = true;
        }
        else{
            if(ptP == p.pos){
                mayor = true;
            }
            else{
                ptA = ptP;
                ptP = ptP->siguiente;
            }
        }
    }
    if(mayor){
        if(ptP == p.pos){
            if(ptP == NULL){
                ptA->siguiente = NULL;
            }
            else{
                if(ptP == primero){
                    primero = primero->siguiente;
                }else{
                    ptA->siguiente = ptP->siguiente;
                }
            }
            delete ptP;
            ptP = NULL;
            borrar = true;
        }
    }
    return borrar;
}

bool TListaCalendario::Borrar (int dia, int mes, int anyo){
    TCalendario lista(dia, mes, anyo, NULL);
    TNodoCalendario *ptN, *ptA, *ptL;
    bool menor, borrar ;
    menor=borrar=false;
    ptA = NULL;
    ptL = primero;

    ptN = new TNodoCalendario();
    ptN->c=lista;

    while(ptL != NULL){
		if(ptL->c<ptN->c)
			menor = true;
		else{
			ptA=ptL;
			ptL=ptL->siguiente;
		}
		if(menor){
			borrar = true;
			if(ptL==primero){
				primero=ptL->siguiente;
                ptA = primero;
			}
			else{
				ptA->siguiente=ptL->siguiente;
			}
			delete ptL;
			ptL=NULL;
            menor = false;
            ptL = ptA;
		}
	}

	return borrar ;
}

bool TListaCalendario::EsVacia() const{
    bool esta = false;
    if(primero == NULL){
        esta = true;
    }
    return esta;
}

TCalendario TListaCalendario::Obtener(const TListaPos &o) const{
    bool es = false;
    TNodoCalendario *ptP;
    ptP = primero;

    while(ptP != NULL && !es){
        if(ptP == o.pos){
            es = true;
        }
        else{
            ptP = ptP->siguiente;
        }
    }
    return (ptP->c);
}

bool TListaCalendario::Buscar(const TCalendario &c) const{
    bool es = false;
    TNodoCalendario *ptP, *ptN;
    ptN = new TNodoCalendario();
    ptN->c=c;
    ptP = primero;

    while(ptP!=NULL && !es){
        if(ptP->c == c){
            es = true;
        }
        else{
            ptP=ptP->siguiente;
        }
    }
    return es;
}

int TListaCalendario::Longitud() const{
    TNodoCalendario *ptP;
    int contar = 0;
    ptP = primero;

    while(ptP != NULL){
        ptP = ptP->siguiente;
        contar++;
    }
    return contar;
}
     
TListaPos TListaCalendario::Primera() const{
    TListaPos lista;
    lista.pos = primero;
    return lista;
}

TListaPos TListaCalendario::Ultima() const{
    TListaPos lista;
    TNodoCalendario *ptP;
    ptP = primero;

    while(ptP !=NULL && ptP->siguiente !=NULL){
        ptP = ptP->siguiente;
    }
    lista.pos = ptP;
    return lista;
}

TListaCalendario TListaCalendario::ExtraerRango (int n1, int n2){
    TListaCalendario lista;
    TNodoCalendario *ptP, *ptA;
    ptP = primero;
    int i;

    for(i = 1; ptP != NULL && i<n1 ; i++){
        ptP=ptP->siguiente;
    }
    for(int j = i; ptP != NULL && i<=n2 ; i++){
        ptA=ptP;
        lista.Insertar(ptP->c); //Insertamos elemento
		Borrar(ptA->c); //Borrar tus pasos //probar con ptP->c
        ptP=ptP->siguiente;
    }

    return lista;
}

TListaCalendario TListaCalendario::SumarSubl (int I_L1, int F_L1, const TListaCalendario & L2, int I_L2, int F_L2) const{
    TListaCalendario lista1(*this), lista2(L2), sol;
    
    sol = lista1.ExtraerRango(I_L1, F_L1) + lista2.ExtraerRango(I_L2, F_L2);
    
    return sol;
}




ostream & operator<<(ostream &os, const TListaCalendario &l){
    TNodoCalendario *ptP;
    ptP = l.primero;

    os << "<";
    while(ptP != NULL){
        if(ptP->siguiente == NULL){
            os << ptP->c;
            ptP = ptP->siguiente;
        }
        else{
            os << ptP->c << " ";
            ptP = ptP->siguiente;
        }
    }
    os << ">";
    
    return os;
}
