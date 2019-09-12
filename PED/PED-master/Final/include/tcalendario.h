#ifndef _tcalendario
#define _tcalendario
#include <iostream>
using namespace std;


class TCalendario{
    friend ostream & operator<<(ostream &os, const TCalendario &);
    
    private:
        int dia, mes, anyo;
        char* mensaje;
        bool Correcto(int dia, int mes, int anyo);

    public:
        TCalendario();
        TCalendario(int dia, int mes, int anyo, char * mens);
        TCalendario(const TCalendario &o);
        ~TCalendario();

        TCalendario &operator=(const TCalendario &o);
        TCalendario operator+(int o);
        TCalendario operator-(int o);
        TCalendario operator++(int o);
        TCalendario &operator++();
        TCalendario operator--(int o);
        TCalendario &operator--();

        
        bool ModFecha (int dia, int mes, int anyo);
        bool ModMensaje(char *m);
       
        bool operator==(const TCalendario &o) const;
        bool operator!=(const TCalendario &o) const;
        bool operator>(const TCalendario &o) const;
        bool operator<(const TCalendario &o) const;
        
        bool EsVacio();
        int Dia() const;
        int Mes() const;
        int Anyo() const;
        char *Mensaje() const;
};
#endif