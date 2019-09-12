#ifndef _tvectorcalendario
#define _tvectorcalendario
#include <iostream>
#include "tcalendario.h"
using namespace std;

class TVectorCalendario{
    friend ostream & operator<<(ostream &os, const TVectorCalendario &v);

    private:
        TCalendario *c;
        int tamano;
        TCalendario error;

    public:
        TVectorCalendario();
        TVectorCalendario(int t);
        TVectorCalendario(const TVectorCalendario &o);
        ~TVectorCalendario();
        void clear();

        TVectorCalendario & operator=(const TVectorCalendario &o);
        TCalendario & operator[](int o);
        TCalendario operator[](int o) const;

        bool operator==(const TVectorCalendario &o) const; 
        bool operator!=(const TVectorCalendario &o) const;

        int Tamano() const;
        int Ocupadas() const;
        bool ExisteCal(const TCalendario &o) const;
        void MostrarMensajes(int d,int m,int a) const;
        bool Redimensionar(int t);
};
#endif