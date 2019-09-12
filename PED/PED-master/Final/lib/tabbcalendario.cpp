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

// Borra el elemento en el árbol
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

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
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
}

// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TABBCalendario::Nodos() const
{
	int n = 0;
	
	if(raiz)
		n = raiz->iz.Nodos() + raiz->de.Nodos() + 1;	

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

//////////////////////////////////////////////////////////////////////////////////////
/* Para cada TCalendario de la lista, se busca en el ABB; 
	si se encuentra se escribe exclusivamente en la posición correspondiente del vector, el año del nodo anterior según el
	recorrido Inorden. Si no se encuentra en el ABB o no tiene anterior según el recorrido Inorden se pone un 0 en la posición que
	corresponda del vector. La lista pasada como parámetro se recorre de izquierda a derecha. */
/*
int *TABBCalendario::BuscarLista(const TListaCalendario &de) const{
	int *devolver = NULL;
	TListaPos p;
	TVectorCalendario inorden = Inorden();
	int pos = 0; 
	
	if(de.Longitud() != 0){
			devolver = new int [de.Longitud()];
			p = de.Primera();
			while(p.EsVacia() == false){
					devolver[pos] = BuscarEnInorden(inorden, de.Obtener(p));
					p = p.Siguiente();
					pos++;
			}
	}
	
	return devolver;
}
int TABBCalendario::BuscarEnInorden(const TVectorCalendario &vc, const TCalendario &c) const{
	int i, pos;
	
	pos = 0;
	for(i = 1; i <= vc.Tamano(); i++){
			if(vc[i] == c){
					if(i != 1){
							pos = i-1;
					}
			}
	}
	if(pos != 0)
		pos = vc[pos].Anyo();
	return pos;
}

//////////////////////////////////////////////////////////////////////////////////////
/* Borra el camino que le pasas como lista al arbol implicito*/
/*
TListaCalendario TABBCalendario::listarNodos() const{
	TVectorCalendario v = Inorden();
	TListaCalendario lista;
	
	for(int i = 1; i <= v.Tamano(); i++){
		lista.Insertar(v[i]);
	}
	return lista;
}

TListaCalendario TABBCalendario::examen(const TListaCalendario &l) const{
	if(esCamino(l))
		return listarNodos() - l;
	else
		return listarNodos();
}

bool TABBCalendario::esCamino(const TListaCalendario &l) const{
	bool distinto, es;
	TNodoABB *paux;
	TListaPos pos;
	
	if(l.EsVacia()){
		es = true;	
	}
	else{
		distinto = false;
		pos = l.Primera();		
		paux = raiz;
		while(paux != NULL && distinto == false && pos.EsVacia() == false){
			if(paux->item != l.Obtener(pos))
				distinto = true;
			else{
				pos = pos.Siguiente();
				if(pos.EsVacia() == false){
					if(l.Obtener(pos) < paux->item)
						paux = raiz->iz.raiz;
					else
						paux = raiz->de.raiz;
				}			
			}
		}
		if(pos.EsVacia())
			es = true;
	}
	return es;
}
*/

//////////////////////////////////////////////////////////////////////////////////////

/*Elimina el último nivel*//*
int TABBCalendario::EliminarUltimoNivel(){
	return EliminarUltimoNivel(Altura(), 1);
}

int TABBCalendario::EliminarUltimoNivel(int h, int i){
	int eliminados = 0;
	if(raiz != NULL){
		if(i == h){
			eliminados = 1;
			delete raiz;
			raiz = NULL;
		}
		else{
			eliminados = raiz->iz.EliminarUltimoNivel(h, i + 1) +
							raiz->de.EliminarUltimoNivel(h, i + 1);
		}
	}
	return eliminados;
}
//////////////////////////////////////////////////////////////////////////////////////

*/
/*Inserta los elementos de la lista en el arbol// El numero de elementos insertados*/
/*
int TABBCalendario::lista2arbol(const TListaCalendario &li){
	TListaPos p;
	int r;
	r = 0;
	p = li.Primera();
	while(!p.EsVacia()){
		if(Insertar(li.Obtener(p))){
			r++;
		}
		p = p.Siguiente();		
	}
	return r;
}
*/

//////////////////////////////////////////////////////////////////////////////////////

/*Busca en el arbol el calendario de la lista y si esta pone un 1 y si no 0 en un vector de int*/
/*
int *TABBCalendario::marcar(const TListaCalendario &li) const{
	int *v = NULL;
	TListaPos p; // para recorrer la lista
	int pos; // pos para saber porque posicion voy en el vector.	

	if(li.Longitud() > 0){
		v = new int [li.Longitud()];
		p = li.Primera();
		pos = 0;
		while(!p.EsVacia()){
			if(Buscar(li.Obtener(p))){
				v[pos] = 1;
			}
			else{
				v[pos] = 0;
			}
			pos++;
			p = p.Siguiente();
		}
	}
	return v;	
}
[0,1,0,1]
*/

//////////////////////////////////////////////////////////////////////////////////////
/*Examen de 2017*/
/*
int TABBCalendario::examen2017(const TABBCalendario &ab) const{
	bool estructura, iguales;
	int nodosThis, nodosAb;
	int resultado;

	iguales = iguales2017(ab);
	if(iguales){
		resultado = 4;
	}
	else{
		estructura = estructura2017(ab);
		if(estructura){
			resultado = 3;
		}
		else{
			nodosThis = Nodos();
			nodosAb = ab.Nodos();
			if(nodosThis == nodosAb){
				resultado = 0;
			}
			else{
				if(nodosThis < nodosAb){
					resultado = 1;
				}
				else{
					resultado = 2;
				}
			}
		}
	}
	return resultado;	
}

// cierto si son iguales, todo estructura y nodos
bool TABBCalendario::iguales2017(const TABBCalendario &ab) const{
	bool iguales = false;
	if(raiz == NULL && ab.raiz == NULL){
		iguales = true;
	}
	else{
		if(raiz != NULL && ab.raiz != NULL){
			iguales = raiz->item == ab.raiz->item
						&& raiz->iz.iguales2017(ab.raiz->iz)
						&& raiz->de.iguales2017(ab.raiz->de);
		}
	}
	return iguales;
}

// cierto si misma estructura.
bool TABBCalendario::estructura2017(const TABBCalendario &ab) const{
	bool iguales = false;
	if(raiz == NULL && ab.raiz == NULL){
		iguales = true;
	}
	else{
		if(raiz != NULL && ab.raiz != NULL){
			iguales = raiz->iz.estructura2017(ab.raiz->iz)
						&& raiz->de.estructura2017(ab.raiz->de);
		}
	}
	return iguales;
}
*/
//////////////////////////////////////////////////////////////////////////////////////
/*Vector de enteros que almacena que es cada entero*//*
int *TABBCalendario::peral(const TListaCalendario &li) const{
	int *resultado = NULL;
	TListaPos p;
	int pos;	
	int altura = Altura();
	if(li.Longitud() != 0){
		resultado = new int [li.Longitud()];
		pos = 0;
		p = li.Primera();
		while(!p.EsVacia()){
			resultado[pos] = caso(li.Obtener(p), altura, 1);
			pos++;
			p = p.Siguiente(); 
		}
	}
	return resultado;
}*/

		////////////////////
		// para cada calendario del arbol, almacenar en la posicion
		// del vector:
		//		0 si el nodo calendario en el ultimo nivel
		//		1 si no esta en ultimo nivel pero es hoja
		//		2 si tiene dos hijos
		//		3 si tiene solo hijoizquierdo
		//		4 si solo tiene hijoderecho
		//		5 si no esta
/*
int TABBCalendario::caso(const TCalendario &c, int h, int n) const{
	int r;
	if(raiz == NULL){
		r = 5;
	}
	else{
		if(raiz->item == c){
			if(raiz->iz.raiz == NULL && raiz->de.raiz == NULL){
				if(h == n){
					r = 0;
				}
				else{
					r = 1;
				}
			}
			else{
				if(raiz->iz.raiz != NULL && raiz->de.raiz != NULL){
					r = 2;
				}
				else{
					if(raiz->iz.raiz != NULL){
						r = 3;
					}
					else{
						r = 4;
					}
				}
			}
		}
		else{
			if(c < raiz->item){
				r = raiz->iz.caso(c, h, n+1);
			}
			else{
				r = raiz->de.caso(c, h, n+1);
			}
		}
	}
	return r;
}
*/
//////////////////////////////////////////////////////////////////////////////////////
/*Inserta en una lista todos los nodos de un abb por debajo del nivel indicado*/
/*TListaCalendario TABBCalendario::porDebajo(int level) const{
	return porDebajo(level, 1);
}

TListaCalendario TABBCalendario::porDebajo(int level, int levelActual) const{
	TListaCalendario r;
	if(raiz != NULL){
		if(levelActual > level){
			r.Insertar(raiz->item);
		}
		r = r + raiz->iz.porDebajo(level, levelActual + 1) + 
				raiz->de.porDebajo(level, levelActual + 1);
	}
	return r;
}*/

//////////////////////////////////////////////////////////////////////////////////////
// devuelve una lista con los hijos de los nodos del vector
// pasado como parametro.
/*
TListaCalendario TABBCalendario::recogeHijos(const TVectorCalendario &v) const{
	TListaCalendario li;
	int i;

	for(i = 1; i <= v.Tamano(); i++){
		li = li + hijos(v[i]);
	}

	return li;
}

TListaCalendario TABBCalendario::hijos(const TCalendario &p) const{
	TListaCalendario li;

	if(raiz != NULL){
		if(raiz->item == p){
			if(raiz->iz.raiz != NULL){
				li.Insertar(raiz->iz.raiz->item);
			}
			if(raiz->de.raiz != NULL){
				li.Insertar(raiz->de.raiz->item);
			}
		}
		else{
			if(p < raiz->item){
				li = raiz->iz.hijos(p);
			}
			else{
				li = raiz->de.hijos(p);
			}
		}
	}	
	return li;
}*/
//////////////////////////////////////////////////////////////////////////////////////
//devuelve verdadero si el Com esta en el nivel i del arbol
/*
bool TABBCom::estaEnNivel(const TComplejo &lp, int niv)const
{
	bool esta;

	if(nodo == NULL)
		esta = false;
	else
		if(niv == 1){
			if(lp == nodo->item)
				esta = true;
			else 
				esta = false;
		}
		else{
			if(lp.Volumen() < nodo->item.Volumen())
				esta = nodo->iz.estaEnNivel(lp, niv-1);
			else
				esta = nodo->de.estaEnNivel(lp, niv-1);
		}
		return esta;
}*/

//////////////////////////////////////////////////////////////////////////////////////

// Te da una secuencia y si esta dentro del arbol de 
// FORMA CONSECUTIVA devuelve true
/*
bool TABBCom::esCamino(const TListaCom &lp)const
{
	bool es;

	if(esCaminoRaiz(lp))
		es = true;
	else
		es = nodo->iz.esCamino(lp) || nodo->de.esCamino(lp);	   
	return es;
}
*/

// comprueba si la lista de Coms pasada como parametro
// es camino desde la raiz del arbol.
/*
bool TABBCom::esCaminoRaiz(const TListaCom &lp)const
{
	bool es;
	if(nodo == NULL && lp.Longitud() == 0)
		es = true;
	else 
		if(nodo == NULL && lp.Longitud() != 0)
			es = false;
		else 
			if(nodo->item == lp.Obtener(lp.Primera())){
				TListaCom aux = lp;
				TListaPosicion auxPos = aux.Primera();
				aux.Borrar(auxPos);
				es = nodo->iz.esCaminoRaiz(aux);
			}
			else
				es = false;
	return es;	
}*/

//////////////////////////////////////////////////////////////////////////////////////
/*
Crea un vector de padres//busca el padre pasandole el calendario
TComplejo TABBCom::soyTuPadre(const TComplejo &p) const
{
	TComplejo vacio;

	if(nodo != NULL){
		if(nodo->iz.nodo != NULL && nodo->iz.nodo->item == p || 
			nodo->de.nodo != NULL && nodo->de.nodo->item == p)
				vacio = nodo->item;
		else{
			if(p.Volumen() < nodo->item.Volumen())
				vacio = nodo->iz.soyTuPadre(p);
			else
				vacio = nodo->de.soyTuPadre(p);
		}
	}	
	return vacio;
}

TVectorCom TABBCom::padresDe(const TListaCom &lp)const
{
	TVectorCom v(lp.Longitud());
	TListaPosicion pos;
	int i;

	i = 1;
	pos = lp.Primera();	
	while(!pos.EsVacia()) {
		v[i] = soyTuPadre( lp.Obtener(pos) );
		i++;
		pos = pos.Siguiente();
	}
	return v;
}
*/

//////////////////////////////////////////////////////////////////////////////////////

// devuelve una lista con los nodos que son hojas en el arbol
// de los nodos del vector pasado como parametro.
/*
TListaCom TABBCom::listaHojas(const TVectorCom &up)const
{
	TListaCom aux;
	int i;
	
	for(i = 1; i <= up.Longitud(); i++)
	    if(esHoja(up[i]))
			aux.Insertar(up[i]);
	return aux;
}*/
// auxiliar para la anterior, comprueba si el Com esta en un nodo
// que es hoja en el arbol.
/*
bool TABBCom::esHoja(const TComplejo &p)const
{
	bool es;
	if(nodo == NULL)
	   es = false;
	else if(p.Volumen() < nodo->item.Volumen())
	   es = nodo->iz.esHoja(p);
	else if(p.Volumen() > nodo->item.Volumen())
	   es = nodo->de.esHoja(p);
	else if(nodo->iz.nodo == NULL && nodo->de.nodo == NULL)
	   es = true;
	else
	   es = false;

	return es;
	   
}*/
//////////////////////////////////////////////////////////////////////////////////////

// implementar un metodo en el arbol que reciba una lista y para cada nodode 
// la lista almacene un vector de enteros, el numero de nodos del subarbol
// que lo tienen como raiz.
/* Volumen parametro de calendario
int TABBCom::contarHijosCom(const TComplejo &p) const
{
	int numHijos = 0;
	if(nodo != NULL)
	  {
		if(p == nodo->item)
		    numHijos = Nodos();
		else
		    if(p.Volumen() < nodo->item.Volumen())
				numHijos = nodo->iz.contarHijosPoro(p);
		    else
				numHijos = nodo->de.contarHijosPoro(p);
	  }
	return numHijos;
}

int *TABBCom::contarNodosSubarbol(const TListaPoro &lp)const {
	int *ve;
	TListaPosicion p;
	int i;

	if(lp.Longitud() == 0)
		ve = NULL;
	else{
		ve = new int [lp.Longitud()];
		p = lp.Primera();
		i = 0;
		while(!p.EsVacia()){
			ve[i] = contarHijosCom(lp.Obtener(p));
			i++;
			p = p.Siguiente();
		}
	}
	return ve;
}
*/
//////////////////////////////////////////////////////////////////////////////////////

/*
// Realizar la funcion EXTRAER_CAMINO que recibe un vector de booleanos (TRUE=IZQ, FALSE=DER) y devuelve
// el camino por el que hemos pasado

TVectorCalendario TABBCalendario::ExtraerCamino(bool mous[], int tm) const{
	TVectorCalendario c(tm);
	int pos = 1;
	ExtraerCamino(mous, tm, c, pos);
	return c;
}

void TABBCalendario::ExtraerCamino(bool mous[], int tm, TVectorCalendario &v, int &pos) const{
	if(raiz != NULL){
		v[pos] = raiz->item;
		pos++;
		if(p-2 < tm){
			if(m[p-2]){
				raiz->iz.ExtraerCamino(m, tm, v, p);
			}else{
				raiz->de.ExtraerCamino(m, tm, v, p);
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////

// funcion que diga si hay un camino desde la raiz
bool TABBCalendario::EsCamino(const TVectorCalendario &v) const{
	bool aux = false;
	aux = EsCamino(v, 1);
	return aux;
}

bool TABBCalendario::EsCamino(const TVectorCalendario &v, int p) const{
	bool es = false;
	if(p == v.Tamano()+1){
		es = true;
	}
	else{
		if(raiz!=NULL){
			if(raiz->item != v[p]){
				es = false;
			}else{
				es = raiz->iz.EsCamino(v, p+1) || raiz->de.EsCamino(v, p+1);
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////

// Método que recibe un vector de Calendarios y devuelve una lista con los hijos de los calendarios
// del vector 

TListaCalendario TABBCalendario::BuscarHijos(const TCalendario &c) const{
	TListaCalendario lis;
	if(raiz != NULL){
		if(raiz->iz.raiz != NULL){
			lis.Insertar(raiz->iz.raiz->item);
		}
		if(raiz->de.raiz != NULL){
			lis.Insertar(raiz->de.raiz->item);
		}
	}else{
		if(c < raiz->item){
			lis = raiz->iz.BuscarHijos(c);
		}else{
			lis = raiz->de.BuscarHijos(c);
		}
	}
	return lis;
}

// Lo mismo con TVector
TListaCalendario TABBCalendario::BuscarHijos(const TVectorCalendario &v) const{
	TListaCalendario resultado;
	for(int i = 1; i <= v.Tamano(); i++){
		resultado  = resultado + BuscarHijos(v[i]);
	}
	return resultado;
}

//////////////////////////////////////////////////////////////////////////////////////

// Método de ABB que devuelve un vector con las mismas hojas que tiene el árbol
TVectorCalendario TABBCalendario::ExtraerHojas() const{
	TVectorCalendario v(NodosHoja());
	if(raiz->de.raiz == NULL && raiz->iz.raiz == NULL){
		v.Insertar(raiz->item);
	}else{
		v.Insertar(raiz->iz.ExtraerHojas());
		v.Insertar(raiz->de.ExtraerHojas()); 
	}
	return v;
}


TVectorCalendario TABBCalendario::ExtraerHojas() const{
	TVectorCalendario v(nodosHoja());
	int pos = 1;
	ExtraerHojas(v, pos);
	return v;
}

void TABBCalendario::ExtraerHojas(TVectorCalendario &v, int &p) const{
	if (raiz != NULL){
		if(!(raiz->iz.raiz) && !(raiz->de.raiz)){
			v[p++] = raiz->item;
		}else{
			raiz->iz.ExtraerHojas(v, p);
			raiz->de.ExtraerHojas(v, p);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////

// Método de ABB que recibe un TVectorCalendario y devuelve un vector de booleanos donde la posicion i
// vale cierto si el elemento i del vector está en el arbol y falso si no

bool *VectorDeBooleanos(TVectorCalendario &v) const{
	bool * r = NULL;
	if(v.Tamano() != 0){
		r = new bool [v.Tamano()];
		for(int i = 1; i <= v.Tamano(); i++){
			r[i-1] = Buscar(v[i]);
		}
	}
	return r;
}

bool * TABBCalendario::Buscar(const TListaCalendario &lis) const{
	bool * v = NULL;
	if(lis.Longitud() > 0){
		v = new Bool[lis.Longitud()];
		TListaPos p = lis.Primera();
		int i = 0;
		while(!p.EsVacia()){
			v[i] = Buscar(lis.Obtener(p));
			p = p.siguiente();
			i++;
		}
	}
	return v;
}
//////////////////////////////////////////////////////////////////////////////////////

- Realizar un metodo del ABB que devuelva los nodos que se encuenran en el nivel i, en un tvector de IZQ-DER.

TVectorCalendario extraer-nivel-i(int i) const


TVectorCalendario extraer-nivel-i(int i) const{
	TVectorCalendario devolver(contar_nodos_nivel_i(i));
	int pos = 1;
	extraer-nivel-i(devolver, pos, i)
	return devolver;	
}

int contar-nodos-nivel-i(int i){
	int n;
	if(raiz == NULL){
		n = i;
	}
	else{
		if(i==1){
			n = 1;
		}else{
			n = raiz->iz.contar-nodos-nivel-i(i-1) +
				raiz->de.contar-nodos-nivel-i(i-1);
		}
	}
	return n;
}

void extraer-nivel-i(TVectorCalendario &v, int &p, int i){
	if(raiz != NULL){
		if(i == 1){
			v[p] = raiz->item;
			p++;
			raiz->iz.extraer-nivel-i(v, p, i-1);
			raiz->der.extraer-nivel-i(v, p, i-1);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////

TListaCalendario TABBCalendario::extraer-nivel-i(int i) const{
	TListaCalendario r;
	if(raiz != NULL && i > 0){
		if(i == 1){
			r.Insertar(raiz->item);
		}else{
			r = raiz->iz.extraer-nivel-i(i-1) + raiz->der.extraer-nivel-i(i-1);
		}
	}
	return r;
}
*/