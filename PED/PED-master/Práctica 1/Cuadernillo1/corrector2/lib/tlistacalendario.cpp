#include "tlistacalendario.h"



/** \brief Constructor por Defecto
*
* Inicializa la variable pos a NULL
*
*/
TListaPos::TListaPos(){
	pos=NULL;
}
/** \brief Constructor Copia
*
* Copa el objeto que se pasa pro parametro en el objeto implicito
*
* \param p argumento del tipo TListaPos.
*
*/
TListaPos::TListaPos(const TListaPos &p){
	pos=p.pos;
}
/** \brief Destructor
*
* Reinicializa la variable pos a NULL
*
*/
TListaPos::~TListaPos(){
	pos=NULL;
}
/** \brief Operador Asignacion
*
* Copia la TListaPos de la derecha en la de la izquierda
*
* \param p del tipo TListaPos
*
* \return this, la TListaPos copiada
*/
TListaPos & TListaPos:: operator= (const TListaPos &p){
	pos=p.pos;
	return *this;
}
/** \brief Metodo Siguiente
*
* Nos da la posicion siguiente de la lista
*
* \return aux, un TListaPos con la posicion siguiente de la lista
*/
TListaPos TListaPos:: Siguiente() const{
	TListaPos aux;
	if(pos==NULL)
		aux.pos=NULL;
	else
		aux.pos=pos->siguiente;

	return aux;
}
/** \brief Metodo EsVacia
*
* Devuelve true si pos apunta a null
*
* \return vacia, del tipo bool, que devuelve true si pos apunta a null.
*/
bool TListaPos:: EsVacia() const{
	return pos==NULL;
}
/** \brief Operador igualdad
*
* Devuelve true, si los TListaPos son iguales
*
* \param p argumento del tipo TListaPos.
*
* \return iguales, devuelve true si son iguales
*/
bool TListaPos::operator== (const TListaPos &p) const{
	return pos==p.pos;
}

/** \brief Constructor por defecto de nodo
*
* Puntero siguiente a null
*
*/
TNodoCalendario::TNodoCalendario(){
	siguiente=NULL;
}
/** \brief Constructor parametrizado 
*
* Construye una lista pasandole como parametro una lista	
* haciendo uso del operador asignación.
*
* \param cal TlistaCalendario que contiene una lista.
*
*/
TNodoCalendario:: TNodoCalendario(const TNodoCalendario &cal){
	siguiente=cal.siguiente;
	c=cal.c;
}
/** \brief Destructor 
*
* Destruye los nodos de la lista y pone primera=NULL
*
*/
TNodoCalendario::~TNodoCalendario(){
	siguiente=NULL;
}
/** \brief Operador Asignacion
*
* Copia las lista de la derecha en la de la izquierda
*
* \param cal del tipo TListaCalendario que contiene una lista de calendarios
*
* \return this, la lista copiada
*/
TNodoCalendario & TNodoCalendario:: operator=(const TNodoCalendario &cal){
	siguiente=cal.siguiente;
	c=cal.c;
	return *this;
}



/** \brief Constructor por defecto
*
* Construye un vector por defecto que pone la lista a NULL
*
*/
TListaCalendario::TListaCalendario(){
	primero=NULL;
}
/** \brief Constructor parametrizado 
*
* Construye una lista pasandole como parametro una lista	
* haciendo uso del operador asignación.
*
* \param cal TlistaCalendario que contiene una lista.
*
*/
TListaCalendario::TListaCalendario(const TListaCalendario &cal){
	primero=NULL;
	*this=cal;
}
/** \brief Destructor 
*
* Destruye los nodos de la lista y pone primera=NULL
*
*/
TListaCalendario::~TListaCalendario(){
	TNodoCalendario *ptA;
	ptA=primero;
	while(ptA!=NULL){
		primero=primero->siguiente;
		delete ptA;
		ptA=NULL;
		ptA=primero;
	}
}
/** \brief Operador Asignacion
*
* Copia las lista de la derecha en la de la izquierda
*
* \param cal del tipo TListaCalendario que contiene una lista de calendarios
*
* \return this, la lista copiada
*/
TListaCalendario & TListaCalendario:: operator=(const TListaCalendario &cal){
	if(this!=&cal){
		this->~TListaCalendario();
		if(&cal!=NULL){
			TNodoCalendario *ptL,*ptN, *ptF;
			ptL=cal.primero;
			while(ptL!=NULL){
				ptN=new TNodoCalendario();
				if(primero==NULL)
					primero=ptN;
				else
					ptF->siguiente=ptN;
				ptN->c=ptL->c;
				ptF=ptN;
				ptL=ptL->siguiente;
			}
		}
	}
	return *this;
}
/** \brief Operador Suma
*
* Junta los nodos de la primera lista y los junta con los de la segunda,
* evitando los duplicados
*
* \param cal del tipo TListaCalendario que contiene una lista de calendarios
*
* \return aux, la suma de las listas
*/
TListaCalendario TListaCalendario::operator +(const TListaCalendario &cal) const{
	TListaCalendario aux;
	TNodoCalendario *ptA;

	aux=*this;
	ptA=cal.primero;
	while(ptA!=NULL){
		aux.Insertar(ptA->c);
		ptA=ptA->siguiente;
	}
	
	return aux;
}
/** \brief Operador Resta
*
* Pone los nodos de la primera lista y pone los que no estan en la segunda
*
* \param cal del tipo TListaCalendario que contiene una lista de calendarios
*
* \return aux, la resta de las listas
*/
TListaCalendario TListaCalendario::operator -(const TListaCalendario &cal)const{
	TListaCalendario aux;
	TNodoCalendario *ptA;

	aux=*this;
	ptA=cal.primero;
	while(ptA!=NULL){
		aux.Borrar(ptA->c);
		ptA=ptA->siguiente;
	}
	
	return aux;
}
/** \brief Metodo Insertar
*
* Metodo que inserta un calendario que el pasamos en orden
*
* \param cal del tipo TCalendario que contiene un calendario
*
* \return insertado, del tipo bool, devuelve true si se ha insertado el calendario
*/

bool TListaCalendario::Insertar(const TCalendario &cal){
	TNodoCalendario *ptN, *ptA, *ptB;
	bool encontrado=false, mayor=false, insertado=false;
	
	ptA=ptB=primero;
	ptN=new TNodoCalendario();
	ptN->c=cal;
	
	//Busco donde Insertar el calendario
	if(primero==NULL){
			mayor=true;
	}
	else{
		while(ptB!=NULL && !encontrado && !mayor){
			if(ptB->c==ptN->c){
				encontrado=true;
			}
			else{
				if(ptB->c>ptN->c){
					mayor=true;
				}
				else{
					ptA=ptB;
					ptB=ptB->siguiente;
				}
			}
		}
	}
	
	//inserto en la posicion
	if(mayor==true || encontrado==false){
		if(primero==ptB){
			ptN->siguiente=primero;
			primero=ptN;
		}
		else{
			ptA->siguiente=ptN;
			ptN->siguiente=ptB;
		}
		insertado=true;
	}
	
	return insertado;
}
/** \brief Metodo Borrar que borra el calendario pasado como parametro
*
* Metodo que recorre la lista mientras el puntero sea distinto de NULL
* y para cuando encuentra un calendario igual al pasado como parametro
* en caso de encontrarlo lo borra.
*
* \param cal del tipo TCalendario que contiene un calendario
*
* \return borrado, del tipo bool, devuelve true si se ha borrado el calendario
*/

bool TListaCalendario::Borrar(const TCalendario &cal){
	bool mayoroigual=false,borrado=false;
	TNodoCalendario *ptA,*ptL;
	ptL=primero;
	
	while(ptL!=NULL && mayoroigual==false){
		if(ptL->c>cal)
			mayoroigual=true;
		else{
			if(ptL->c==cal){
				mayoroigual=true;
			}
			else{
				ptA=ptL;
				ptL=ptL->siguiente;
			}
		}
		if(mayoroigual){
			if(ptL->c==cal){
				borrado=true;
				if(ptL==primero){
					primero=ptL->siguiente;
				}
				else{
					ptA->siguiente=ptL->siguiente;
				}
				delete ptL;
				ptL=NULL;
			}
		}
	}

	return borrado;
}
/** \brief Metodo Borrar que borra el calendario que se encuentra en la posicion
*
* Metodo que borra el calendario que se encuentra en la posicion
* pasada como parametro, para ello recorre la lista hasta encontrar la posicion
* y borra el calendario que se encuentre en ella
*
* \param p del tipo TListaPos que contiene una posición
*
* \return borrado, del tipo bool, devuelve true si se han borrado el calendario
*/
bool TListaCalendario::Borrar(const TListaPos &p){
	bool mayoroigual=false, borrado=false;
	TNodoCalendario *ptA,*ptL;

/*
ptL = primero;
while(ptL)
{
	if(ptL == p)
	{
		ptB = ptL;
		if(ptL == primero)
			primero = primero->sig;
		else
			ptA->sig = ptL->sig;
		ptL = ptL->sig;
		delete ptB;
	}
	else
	{
		ptA = ptL;
		ptL = ptL->sig;
	}
}
*/
	ptL=primero;
	while(ptL!=NULL && mayoroigual==false){
		if(ptL>p.pos)
			mayoroigual=true;
		else{
			if(ptL==p.pos){
				mayoroigual=true;
			}
			else{
				ptA=ptL;
				ptL=ptL->siguiente;
			}
		}
		if(mayoroigual){
			if(ptL==p.pos){
				borrado=true;
				if(ptL==primero){
					primero=ptL->siguiente;
				}
				else{
					ptA->siguiente=ptL->siguiente;
				}
				delete ptL;
				ptL=NULL;
			}
		}
	}
	return borrado;
}

/** \brief Metodo Borrar que borra los calendarios anteriores a la fecha pasada como parametro
*
* Metodo que borra los calendarios anteriores a la fecha pasada como parametro
* para ello mediante un calendario auxiliar construido con esa fecha
* vamos comprobando si el caledario de la lista tiene fecha menor al calendario
* aux, en caso de que sea asi lo borramos.
*
* \param dia int que contiene el dia
* \param mes int que contiene el mes
* \param anyo int que contiene el anyo
*
* \return borrar, del tipo bool, devuelve true si se han borrado calendarios anteriores.
*/

bool TListaCalendario::Borrar(int dia, int mes , int anyo){
	TCalendario aux(dia,mes,anyo, NULL);
	bool borrado=false, borrar=false;
	TNodoCalendario *ptA,*ptL;
	
	ptL=primero;

	while(ptL!=NULL){

		if(ptL->c<aux){
			borrado=true;
		}
		else{
			ptA=ptL;
 			ptL=ptL->siguiente;
		}
		if(borrado==true){
			if(ptL==primero){
				primero=ptL->siguiente;
				ptA=primero;
			}
			else{
				ptA->siguiente=ptL->siguiente;
			}
			delete ptL;
			ptL=NULL;
			borrar=true;
			
		}
		if(borrado==true) ptL=ptA;borrado=false;
		
	}
	return borrar;
}
/** \brief Metodo EsVacia
*
* Devuelve true si primero apunta a null
*
* \return vacia, del tipo bool, que devuelve true si primero apunta a null.
*/
bool TListaCalendario::EsVacia() const{
	return primero==NULL;
}
/** \brief Metodo Obtener que obtiene el calendario que esta en la posicion
*
* Devuelve el calendario que se encuentra en la posición
* que se la pasa como parametro
*
* \param cal posición que queremos buscar
*
* \return aux, del tipo Tcalendario, calendario que se encuentra en la posición.
*/
TCalendario TListaCalendario::Obtener(const TListaPos &cal) const{
	TCalendario aux;
	TNodoCalendario *ptA;
	bool encontrado=false;

	ptA=primero;
	while(ptA!=NULL && encontrado==false){
		if(ptA==cal.pos){
			encontrado=true;
		}
		else{
			ptA=ptA->siguiente;
		}
	}
	if(encontrado==true)
		aux=ptA->c;

	return aux;
}
/** \brief Metodo Buscar que busca un calendario en la lista
*
* Devuelve true si el calendario se ha encontrado en la lista
*
* \param cal el calendarioq ue queremos encontrar
*
* \return encontrado, Devuelve true si el calendario se ha encontrado en la lista.
*/
bool TListaCalendario::Buscar(const TCalendario &cal) const{
	TNodoCalendario *ptA, *ptN;
	bool encontrado=false;
	
	ptN=new TNodoCalendario();
	ptN->c=cal;
	ptA=primero;

	while(ptA!=NULL && !encontrado){
		if(ptA->c==ptN->c){
			encontrado=true;
		}
		else{
			ptA=ptA->siguiente;
		}
	}
	return encontrado;
}
/** \brief Longitud que devuelve la longitud de la lista
*
* Devuelve la longitud de la lista, para ello vamos incrementado
* un contador mientras el puntero no apunte a NULL
*
* \return longitud, Un entero que contiene la longitud de la lista
*/
int TListaCalendario::Longitud() const{
	int longitud=0;
	TNodoCalendario *ptA;

	ptA=primero;	
	while(ptA!=NULL){
		ptA=ptA->siguiente;
		longitud++;
	}

	return longitud;
}
/** \brief Primera que devuelve la primera posición de la lista
*
* Devuelve la primera posicion de la lista, 
*
* \return aux, Se trata de la primera posición de la lista.
*/
TListaPos TListaCalendario::Primera() const{
	TListaPos aux;
	aux.pos=primero;
	return aux;
}
/** \brief Ultima que devuelve la ultima posición de la lista
*
* Devuelve la última posicion de la lista, recorriendola mientras
* el puntero a siguiente sea distinto de NULL.
*
*
* \return aux, Se trata de la última posición de la lista.
*/
TListaPos TListaCalendario::Ultima() const{
	TListaPos aux;
	TNodoCalendario *ptA;

	ptA=primero;
	if(ptA!=NULL){
		while(ptA->siguiente!=NULL){
			ptA=ptA->siguiente;
		}
		aux.pos=ptA;
	}
	return aux;
}
/** \brief Operador Salida que devuelve un istream
*
* Recibe un osteram o y una tlistacalendario y muestra el contenido de la lista
* desde la primera posicion hasta la última en una sola línea.
*
* \param o argumento del tipo ostream que contiene una cadena de caracteres
* \param cal argumento del tipo tlistacalendario que contiene una lista de calendarios
*
* \return o, salida de los parametros
*/
ostream & operator<<(ostream &o, const TListaCalendario &cal){
	TNodoCalendario *ptA;
	ptA=cal.primero;

	o<<"<";
	if(ptA){
		while(ptA!=NULL){
 			if(ptA->siguiente!=NULL)
 				o<<ptA->c<<" ";
 			else
 				o<<ptA->c;	
			ptA=ptA->siguiente;
 		}
 	}
 	o<<">";

	return o;
}


TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2){
	TListaCalendario aux;
	TNodoCalendario *ptL, *ptA;
	int i=1;

	if(n1<1)
		n1=1;

	ptL=primero;
	while(ptL!=NULL && i<n1){
		i++;
		ptL=ptL->siguiente;
	}

	while(ptL!=NULL && i<=n2){
		aux.Insertar(ptL->c);
		ptA=ptL;
		ptL=ptL->siguiente;
		Borrar(ptA->c);
		i++;
	}

	return aux;
}

bool TListaCalendario::operator==(const TListaCalendario &de) const{
	TNodoCalendario *ptL1, *ptL2;
	bool iguales;
	
	ptL1 = primero;
	ptL2 = de.primero;
	while(ptL1 && ptL2 && ptL1->c == ptL2->c){
			ptL1 = ptL1->siguiente;
			ptL2 = ptL2->siguiente;
	}
	if(!ptL1 && !ptL2)
		iguales = true;
	else
		iguales = false;
	
	
	return iguales;
}

TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, const TListaCalendario &l2, int I_L2, int F_L2)const{
	TListaCalendario auxI(*this), auxD(l2), ri, rd;

	ri = auxI.ExtraerRango(I_L1, F_L1);
	rd = auxD.ExtraerRango(I_L2, F_L2);

	return ri + rd;
}

