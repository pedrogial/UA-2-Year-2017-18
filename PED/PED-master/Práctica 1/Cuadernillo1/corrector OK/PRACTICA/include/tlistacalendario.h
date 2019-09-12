#ifndef _tlistacalendario
#define _tlistacalendario
#include <iostream>
#include "tcalendario.h"

using namespace std;

class TListaPos;
class TNodoCalendario;


class TListaCalendario{
    friend ostream & operator<<(ostream &os, const TListaCalendario &l);

    private:
        TNodoCalendario *primero;

    public:
        TListaCalendario();
        TListaCalendario(const TListaCalendario &o);
        ~TListaCalendario();
        TListaCalendario & operator=(const TListaCalendario &o);

        bool operator==(const TListaCalendario &o) const;
        TListaCalendario operator+(const TListaCalendario &o) const;
        TListaCalendario operator-(const TListaCalendario &o) const;

        bool Insertar(const TCalendario &o);

        bool Borrar (const TCalendario &o);
        bool Borrar (const TListaPos &o);
        bool Borrar (int d, int m, int a);

        bool EsVacia() const;

        TCalendario Obtener(const TListaPos &o) const;
        bool Buscar(const TCalendario &o) const;
        int Longitud() const;
        
        TListaPos Primera() const;
        TListaPos Ultima() const;

        TListaCalendario SumarSubl (int I_L1, int F_L1, const TListaCalendario &L2, int I_L2, int F_L2) const;
        TListaCalendario ExtraerRango (int n1, int n2);
};

class TNodoCalendario{
    friend ostream & operator<<(ostream &os, const TListaCalendario &l);
    friend class TListaPos;
    friend class TListaCalendario;
    

    private:
        TNodoCalendario *siguiente;
        TCalendario c;

    public:
        TNodoCalendario();
        TNodoCalendario(const TNodoCalendario &o);
        ~TNodoCalendario();

        TNodoCalendario & operator=(const TNodoCalendario &o);
};

class TListaPos{
    friend class TListaCalendario; 
	friend class TNodoCalendario;

    private:
        TNodoCalendario *pos;

    public:
        TListaPos();
        TListaPos(const TListaPos &o);
        ~TListaPos();

        TListaPos & operator=(const TListaPos &o);
        bool operator==(const TListaPos &o) const;
        bool operator!=(TListaPos &o);
        
        TListaPos Siguiente() const;
        bool EsVacia() const;
};
#endif

