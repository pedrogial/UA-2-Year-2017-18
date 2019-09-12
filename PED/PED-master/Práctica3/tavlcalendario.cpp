#include "tavlcalendario.h"
#include <queue>

TCalendario TAVLCalendario::Raiz() const{
		if(raiz != NULL)
			return raiz->item;
		else
			return TCalendario();
}
		
TAVLCalendario::TAVLCalendario()
{
	raiz = NULL;
}

TAVLCalendario::~TAVLCalendario()
{
	if(raiz != NULL)
	{
		// (raiz->iz).~TAVLDir();
		// (nodo->de).~TAVLDir();
		delete raiz;
		raiz = NULL;
	}
	
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &de)
{
	if(!de.raiz)
		raiz = NULL;
	else
		raiz = new TAVLNodo(*de.raiz);
}


TAVLCalendario &TAVLCalendario::operator=(const TAVLCalendario &de)
{
	if(this != &de)
	{
		this->~TAVLCalendario();
		if(de.raiz != NULL)
		{
			raiz = new TAVLNodo;
			*raiz = *(de.raiz);
		}
	}
	return *this;
}

TVectorCalendario TAVLCalendario::Inorden() const
{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;
	
	InordenAux(recorrido, pos);	
	
	return recorrido;
}

void TAVLCalendario::InordenAux(TVectorCalendario &v, int &p) const
{
	if(raiz != NULL)
	{
		raiz->iz.InordenAux(v, p);
		v[p] = raiz->item;
		p++;
		raiz->de.InordenAux(v, p);
	}
	
	return;
}

TVectorCalendario TAVLCalendario::Preorden() const
{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;
	
	PreordenAux(recorrido, pos);	
	
	return recorrido;
}

void TAVLCalendario::PreordenAux(TVectorCalendario &v, int &p) const
{
	if(raiz != NULL)
	{
		v[p] = raiz->item;
		p++;
		raiz->iz.PreordenAux(v, p);
		raiz->de.PreordenAux(v, p);
	}
	
	return;
}

TVectorCalendario TAVLCalendario::Postorden() const
{
	TVectorCalendario recorrido(Nodos());
	int pos = 1;
	
	PostordenAux(recorrido, pos);	
	
	return recorrido;
}

void TAVLCalendario::PostordenAux(TVectorCalendario &v, int &p) const
{
	if(raiz != NULL)
	{
		raiz->iz.PostordenAux(v, p);
		raiz->de.PostordenAux(v, p);
		v[p] = raiz->item;
		p++;
	}
	
	return;
}


bool TAVLCalendario::Insertar(const TCalendario &c)
{
	bool insertado, crece;

	// el parametro crece indica si el arbol en el cual has insertado crece en altura.
	// en este metodo se ignora.
	insertado = Insertar(c, crece);
	
	return insertado;
}

bool TAVLCalendario::Insertar(const TCalendario &c, bool &crece)
{
	bool creceIz, creceDe;
	bool insertado;

	creceIz = creceDe = false;	
	insertado = false;
	
	if(EsVacio())
	{
		raiz = new TAVLNodo;
		raiz->fe = 0;
		raiz->item = c;
		crece = true;
		insertado = true;
	}
	else
		if( !(raiz->item == c) )
		{
			if(c < raiz->item)
				insertado = raiz->iz.Insertar(c, creceIz);
		
			else
				insertado = raiz->de.Insertar(c, creceDe);
			if(creceIz)
			{
				raiz->fe--;
				switch(raiz->fe)
				{
					case 0:
						crece = false;
					break;
					case -1:
						crece = true;
					break;
					case -2:
						crece = false;
						switch(raiz->iz.raiz->fe)
						{
							case -1:
								II();
							break;
							case +1:
								ID();
							break;						
						}
					break;
				}
			}
			else
				if(creceDe)
				{
					raiz->fe++;
					switch(raiz->fe)
					{
						case 0:
							crece = false;
						break;
						case 1:
							crece = true;
						break;
						case 2:
							crece = false;
							switch(raiz->de.raiz->fe)
							{
								case -1:
									DI();
								break;
								case +1:
									DD();
								break;
							}
						break;
					}
				}
		}
		
	return insertado;
}


bool TAVLCalendario::Buscar(const TCalendario &c) const
{
	bool encontrado;

	if(raiz != NULL)
		encontrado = raiz->iz.Buscar(c) || raiz->de.Buscar(c) || raiz->item == c;
	else
		encontrado = false;
	
	return encontrado;
}


int TAVLCalendario::Nodos() const
{
	int nodos;

	if(!raiz)
		nodos = 0;
	else
		nodos = 1 + raiz->iz.Nodos() + raiz->de.Nodos();
	return nodos;
}

int TAVLCalendario::NodosHoja() const
{
	int nodosHoja;

	if(!raiz)
		nodosHoja = 0;
	else	
		if(raiz->iz.EsVacio() && raiz->de.EsVacio())
			nodosHoja = 1;
		else
			nodosHoja = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
	
	return nodosHoja;
}

int TAVLCalendario::Altura() const
{
	int alturaTotal, alturaIz, alturaDe;
	
	if(!raiz)
		alturaTotal = 0;
	else
	{
		alturaIz = raiz->iz.Altura();
		alturaDe = raiz->de.Altura();
		if(alturaIz > alturaDe)
			alturaTotal = alturaIz + 1;
		else
			alturaTotal = alturaDe + 1;
	}
	
	return alturaTotal;
}

bool TAVLCalendario::EsVacio() const
{
	return !raiz;	
}

bool TAVLCalendario::operator!=(const TAVLCalendario &de) const
{
	return !(*this == de);
}

bool TAVLCalendario::operator==(const TAVLCalendario &de) const
{
	bool iguales;

	return Inorden() == de.Inorden();
}

void TAVLCalendario::DD()
{
	TAVLNodo *auxR;
	
	auxR = raiz;
	raiz = auxR->de.raiz;
	auxR->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = auxR;
	if(raiz->fe == 0)
	{
		raiz->fe = -1;
		raiz->iz.raiz->fe = 1;
	}
	else
	{
		raiz->fe = 0;
		raiz->iz.raiz->fe = 0;
	}
}

void TAVLCalendario::II()
{
	TAVLNodo *auxR;
	
	auxR = raiz;
	raiz = auxR->iz.raiz;
	auxR->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = auxR;
	if(raiz->fe == 0)
	{
		raiz->fe = 1;
		raiz->de.raiz->fe = -1;
	}
	else
	{
		raiz->fe = 0;
		raiz->de.raiz->fe = 0;
	}
}

void TAVLCalendario::ID()
{
	TAVLNodo *auxR, *auxIz, *auxDe;
	
	auxR = raiz;
	raiz = raiz->iz.raiz->de.raiz;
	auxIz = raiz->iz.raiz;
	auxDe = raiz->de.raiz;
	raiz->iz.raiz = auxR->iz.raiz;
	raiz->de.raiz = auxR;
	auxR->iz.raiz = auxDe;
	raiz->iz.raiz->de.raiz = auxIz;
	if(raiz->fe == 0)
		raiz->fe = raiz->iz.raiz->fe = raiz->de.raiz->fe = 0;
	else
		if(raiz->fe == -1)
		{
			raiz->fe = 0;
			raiz->iz.raiz->fe = 0;
			raiz->de.raiz->fe = 1;	
		}
		else
		{
			raiz->fe = 0;
			raiz->iz.raiz->fe = -1;	
			raiz->de.raiz->fe = 0;	
		}
}

void TAVLCalendario::DI()
{
	TAVLNodo *auxR, *auxIz, *auxDe;
	
	auxR = raiz;
	raiz = raiz->de.raiz->iz.raiz;
	auxIz = raiz->iz.raiz;
	auxDe = raiz->de.raiz;
	raiz->de.raiz = auxR->de.raiz;
	raiz->iz.raiz = auxR;
	auxR->de.raiz = auxIz;
	raiz->de.raiz->iz.raiz = auxDe;
	if(raiz->fe == 0)
		raiz->fe = raiz->iz.raiz->fe = raiz->de.raiz->fe = 0;
	else
		if(raiz->fe == -1)
		{
			raiz->fe = 0;
			raiz->iz.raiz->fe = 0;
			raiz->de.raiz->fe = 1;	
		}
		else
		{
			raiz->fe = 0;
			raiz->iz.raiz->fe = -1;
			raiz->de.raiz->fe = 0;	
		}
}

TAVLNodo::TAVLNodo()
{
	fe = 0;
}

TAVLNodo::TAVLNodo(const TAVLNodo &o)
:iz(o.iz), de(o.de), item(o.item), fe(o.fe)
{ }

TAVLNodo &TAVLNodo::operator=(const TAVLNodo &de)
{
	iz = de.iz;
	this->de = de.de;
	item = de.item;
	fe = de.fe;
	
	return *this;
}

TAVLNodo::~TAVLNodo()
{
	fe = 0;
}
/*
TVectorCalendario TAVLCalendario::Niveles() const
{
	TColaAVLCalendario cola;
	TVectorCalendario v(Nodos());
	TAVLCalendario *arbol;
	int numArbol;
	
	cola.Encolar((TAVLCalendario *)this);
	numArbol = 1;
	while(!cola.EsVacia())
	{
		arbol = cola.Cabeza();
		cola.Desencolar();
		if(!arbol->EsVacio())
		{
			v[numArbol] = arbol->raiz->item;
			numArbol++;
			cola.Encolar(&(arbol->raiz->iz));
			cola.Encolar(&(arbol->raiz->de));
		}
	}
	return v;
}
*/

bool TAVLCalendario::Borrar(const TCalendario &c)
{
	bool decrece = false;
	return Borrar(c, decrece);
}

bool TAVLCalendario::Borrar(const TCalendario &c, bool &decrece)
{
	bool borrado, decreceIz, decreceDe;
	TCalendario mayorIz;
	TAVLNodo *ptB, *raizAux;

	// si el arbol esta vacio o llegamos a arbol vacio, no se puede borrar.
	decrece = false;
	decreceIz = decreceDe = false;
	if(!raiz)
		decrece = borrado = false;
	else	// si encontramos el nodo.
		if(c < raiz->item)
			borrado = raiz->iz.Borrar(c, decreceIz);
		else
			if(c > raiz->item)
				borrado = raiz->de.Borrar(c, decreceDe);
			else
				if(raiz->item == c)
					if(raiz->iz.EsVacio() && raiz->de.EsVacio())	// NODO HOJA
					{
						delete raiz;
						raiz = NULL;
						decrece = borrado = true;
					}
					else
						if(!raiz->iz.EsVacio() && raiz->de.EsVacio())	// SOLO HIJO IZQUIERDO
						{
							ptB = raiz;
							raiz = raiz->iz.raiz;
							ptB->iz.raiz = ptB->de.raiz = NULL;
							delete ptB;
							decrece = borrado = true;
						}
						else
							if(raiz->iz.EsVacio() && !raiz->de.EsVacio())	// SOLO HIJO DERECHO	
							{
								ptB = raiz;
								raiz = raiz->de.raiz;
								ptB->iz.raiz = ptB->de.raiz = NULL;
								delete ptB;
								decrece = borrado = true;	
							}
							else	// DOS HIJOS.
							{
								mayorIz = raiz->iz.BuscarMayor();
								// OJO OJO OJO OJO !!!!!!!!!!!!!
								// hago esto porque la rotacion puede cambiar la raiz ;)
								raizAux = raiz;
								borrado = Borrar(mayorIz, decrece);
								raizAux->item = mayorIz;
							}
	// En el proceso de vuelta comprobamos si es necesario hacer
	// reestructuraciones.
	if(borrado)
	{
		if(decreceIz)
		{
			raiz->fe++;
			switch(raiz->fe)
			{
				case 0:
					decrece = true;
					break;
				case 1:
					decrece = false;	
					break;
				case 2:
					switch(raiz->de.raiz->fe)
					{
						case -1:
							DI();
							decrece = true;	
						break;
						case 0:
							DD();
							decrece = false;
						break;
						case 1:
							DD();
							decrece = true;
						break;
					}
				break;
	
			}
		}
		else
			if(decreceDe)
			{
				raiz->fe--;
				switch(raiz->fe)
				{
					case 0:
						decrece = true;
						break;
					case -1:
						decrece = false;
						break;
					case -2:
						switch(raiz->iz.raiz->fe)
						{
							case -1:
								II();
								decrece = true;
								break;
							case 0:
								II();
								decrece = false;
								break;
							case 1:
								ID();
								decrece = true;
								break;
						}
				}
			}
	}
	return borrado;
}


TCalendario TAVLCalendario::BuscarMayor() const
{
	TCalendario mayor;
	if(raiz)
		if(raiz->de.raiz)
			mayor = raiz->de.BuscarMayor();
		else
			mayor = raiz->item;
	return mayor;
}

ostream & operator<<(ostream &os, const TAVLCalendario &avl){
		os << avl.Inorden();
		return os;
}


TVectorCalendario TAVLCalendario::Niveles() const{
	queue<TAVLNodo *> cola; // cola para hacer el recorrido
	TVectorCalendario niveles(Nodos()); // tantos calendarios como nodos tiene el arbol
	TAVLNodo *paux; // puntero que recogera la cabeza de la cola.
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


int TAVLCalendario::BuscaNodo(const TCalendario &c) const{
	int resultado;
	
	if(raiz == NULL){
		resultado = 0;
	}
	else{
		if(raiz->iz.raiz != NULL && raiz->iz.raiz->item == c)
			resultado = 1;
		else
			if(raiz->de.raiz != NULL && raiz->de.raiz->item == c)
				resultado = 2;
			else{
				if(c < raiz->item)
					resultado = raiz->iz.BuscaNodo(c);
				else
					resultado = raiz->de.BuscaNodo(c);
			}
	}
	return resultado;
}

int *TAVLCalendario::BuscaAVL(const TListaCalendario &lista) const{
	int *v = NULL;
	TListaPos posicion;
	TCalendario actual;
	int i;

	if(lista.Longitud() != 0){
		posicion = lista.Primera();
		i = 0;
		v = new int [lista.Longitud()];
		while(posicion.EsVacia() == false){
			actual = lista.Obtener(posicion);
			if(raiz->item == actual)
				v[i] = 3;
			else
				v[i] = BuscaNodo(actual);
			i++;
			posicion = posicion.Siguiente();
		}
	}
	return v;
}

