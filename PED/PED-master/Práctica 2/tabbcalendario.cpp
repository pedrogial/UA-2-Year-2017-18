#include "tabbcalendario.h"
#include <queue>

TNodoABB::TNodoABB()
{ }

TNodoABB::TNodoABB(const TNodoABB &n)
:iz(n.iz), de(n.de), item(n.item) 
{ }

TNodoABB::~TNodoABB()
{ }

TNodoABB &TNodoABB::operator=(const TNodoABB &n)
{ 
	if(this != &n)
	{
		iz = n.iz;
		de = n.de;
		item = n.item;
	}
	return *this;
}

void TABBCalendario::InordenAux(TVectorCalendario &v, int &p) const
{
	if(raiz)
	{
		raiz->iz.InordenAux(v, p);
		v[p] = raiz->item;
		p++;
		raiz->de.InordenAux(v, p);
	}
}

void TABBCalendario::PreordenAux(TVectorCalendario &v, int &p) const
{
	if(raiz)
	{
		v[p] = raiz->item;
		p++;
		raiz->iz.PreordenAux(v, p);
		raiz->de.PreordenAux(v, p);
	}
}

void TABBCalendario::PostordenAux(TVectorCalendario &v, int &p) const
{
	if(raiz)
	{
		raiz->iz.PostordenAux(v, p);
		raiz->de.PostordenAux(v, p);
		v[p] = raiz->item;
		p++;
	}
}

TABBCalendario::TABBCalendario()
{
	raiz = NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &a)
{
	raiz = NULL;
	if(a.raiz)
		raiz = new TNodoABB(*a.raiz);
}

TABBCalendario::~TABBCalendario()
{
	if(raiz)
	{
		delete raiz;
		raiz = NULL;
	}
}

TABBCalendario &TABBCalendario::operator=(const TABBCalendario &a)
{
	if(this != &a)
	{	
		this->~TABBCalendario();
		if(a.raiz)
		{
			raiz = new TNodoABB;
			*raiz = *a.raiz;
		}
	}
	return *this;
}


TVectorCalendario TABBCalendario::Inorden() const
{
	int pos = 1;
	TVectorCalendario recorrido(Nodos());
	
	InordenAux(recorrido, pos);	

	return recorrido;
}

TVectorCalendario TABBCalendario::Preorden() const
{
	int pos = 1;
	TVectorCalendario recorrido(Nodos());
	
	PreordenAux(recorrido, pos);	

	return recorrido;
}

TVectorCalendario TABBCalendario::Postorden() const
{
	int pos = 1;
	TVectorCalendario recorrido(Nodos());
	
	PostordenAux(recorrido, pos);	

	return recorrido;
}

int TABBCalendario::Nodos() const
{
	int n = 0;
	
	if(raiz)
		n = raiz->iz.Nodos() + raiz->de.Nodos() + 1;	

	return n;
}

int TABBCalendario::NodosHoja() const
{
	int nh = 0;
	if(raiz)
	{
		if(raiz->iz.EsVacio() && raiz->de.EsVacio())
			nh = 1;
		else
		{
			nh += raiz->iz.NodosHoja();
			nh += raiz->de.NodosHoja();
		}
	}
	return nh;
}

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

bool TABBCalendario::EsVacio() const
{
	return raiz == NULL;
}

bool TABBCalendario::Buscar(const TCalendario &c) const
{
	bool encontrado = false;

	if(raiz)
		if(raiz->item == c)
			encontrado = true;
		else
			if(c < raiz->item)
				encontrado = raiz->iz.Buscar(c);
			else
				encontrado = raiz->de.Buscar(c);

	return encontrado;
}

bool TABBCalendario::Insertar(const TCalendario &c)
{
	bool insertado;
	
	if(!raiz)
	{
		raiz = new TNodoABB;
		raiz->item = c;
		insertado = true;
	}
	else
		if(c == raiz->item)
			insertado = false;
		else
			if(c > raiz->item)
				insertado = raiz->de.Insertar(c);
			else
				insertado = raiz->iz.Insertar(c);

	return insertado;
}

bool TABBCalendario::Borrar(const TCalendario &c)
{
	TCalendario mayorIz;
	TNodoABB *pBorrar;
	bool borrado = false;
	if(!raiz)
		borrado = false;
	else
		if(raiz->item == c)
		{
			borrado = true;
			if(raiz->iz.EsVacio() && raiz->de.EsVacio())
			{
				delete raiz;
				raiz = NULL;
			}
			else
				if(!raiz->iz.EsVacio() && !raiz->de.EsVacio())
				{
					mayorIz = raiz->iz.BuscarMayor();
					raiz->item = mayorIz;
					raiz->iz.Borrar(mayorIz);
				}
				else
				{
					pBorrar = raiz;
					if(raiz->iz.EsVacio()){	// solo hijo derecho.
						raiz = raiz->de.raiz;
						pBorrar->de.raiz = NULL;
					}
					else{			// solo hijo izquierdo.
						raiz = raiz->iz.raiz;
						pBorrar->iz.raiz = NULL;					
					}
					delete pBorrar;
				}	
		}
		else
			if(c < raiz->item)
				borrado = raiz->iz.Borrar(c);
			else
				borrado = raiz->de.Borrar(c);

	return borrado;
}

TABBCalendario TABBCalendario::operator+(const TABBCalendario &de) const
{
	TABBCalendario aux(*this);
	TVectorCalendario v;

	v = de.Inorden();
	for(int i = 1; i <= v.Tamano(); i++)
		aux.Insertar(v[i]);

	return aux;
}

TABBCalendario TABBCalendario::operator-(const TABBCalendario &de) const
{
	TABBCalendario aux;
	TVectorCalendario v;

	v = Inorden();
	for(int i = 1; i <= v.Tamano(); i++)
		if(!de.Buscar(v[i]))
			aux.Insertar(v[i]);
	return aux;
}

TCalendario TABBCalendario::BuscarMayor( ) const
{
	TCalendario aux;

	if(raiz)
	{
		if(!raiz->de.raiz)
			aux = raiz->item;
		else
			aux = raiz->de.BuscarMayor();
	}
	
	return aux;
}

bool TABBCalendario::operator==(const TABBCalendario &de) const{
	bool iguales;
	iguales = false;


	TVectorCalendario inordeniz, inordende;
	inordeniz = Inorden();
	inordende = de.Inorden();
	
	if(inordeniz == inordende)
		iguales = true;

	return iguales;
}

TVectorCalendario TABBCalendario::Niveles() const{
	queue<TNodoABB *> cola; // cola para hacer el recorrido
	TVectorCalendario niveles(Nodos()); // tantos calendarios como nodos tiene el arbol
	TNodoABB *paux; // puntero que recogera la cabeza de la cola.
	int pos;

	pos = 1;
	cola.push(raiz); // insertamos la raiz. (puede ser NULL)
	while(!cola.empty()){
		paux = cola.front(); // consulto la cabeza de la cola
		cola.pop(); // desncolo.
		if(paux != NULL){ // si no es vacio.
			niveles[pos] = paux->item;
			pos++;
			cola.push(paux->iz.raiz);
			cola.push(paux->de.raiz);
		}
	}
	return niveles;
}


/* Para cada TCalendario de la lista, se busca en
	el ABB; si se encuentra se escribe exclusivamente en la posición correspondiente del vector, el año del nodo anterior según el
	recorrido Inorden. Si no se encuentra en el ABB o no tiene anterior según el recorrido Inorden se pone un 0 en la posición que
	corresponda del vector. La lista pasada como parámetro se recorre de izquierda a derecha. */
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




