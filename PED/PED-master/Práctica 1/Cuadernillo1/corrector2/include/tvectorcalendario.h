#ifndef __TVectorCalendario
#define __TVectorCalendario

#include "tcalendario.h"

class TVectorCalendario
{
private:
// PARTE PRIVADA
// Para implementar el VECTOR de TCalendario
          TCalendario *c;
          int tamano;
	  TCalendario error; //Uso de Layering
                              // FORMA CANÓNICA
public:
/// Constructor por defecto
          TVectorCalendario();
/// Constructor a partir de un tamaño
          TVectorCalendario(int);
/// Constructor de copia
          TVectorCalendario(const TVectorCalendario &);
/// Destructor
          ~TVectorCalendario();
/// Sobrecarga del operador asignación
          TVectorCalendario & operator=(const TVectorCalendario &);
                              //Métodos
/// Sobrecarga del operador igualdad
          bool operator==(const TVectorCalendario &)const;
/// Sobrecarga del operador desigualdad
          bool operator!=(const TVectorCalendario &)const;
/// Sobrecarga del operador corchete (parte IZQUIERDA)
          TCalendario & operator[](int);
/// Sobrecarga del operador corchete (parte DERECHA)
          TCalendario operator[](int) const;
/// Tamaño del vector (posiciones TOTALES)
          int Tamano() const;
/// Cantidad de posiciones OCUPADAS (no vacías) en el vector
          int Ocupadas() const;
/// Devuelve true si existe el calendario en el vector
          bool ExisteCal(const TCalendario &) const;
/// Mostrar por pantalla mensajes de TCalendario en el vector, de fecha IGUAL O POSTERIOR a la pasada
          void MostrarMensajes(int,int,int)const;

	bool Redimensionar(int tam);
                              //FUNCIONES AMIGAS
/// Sobrecarga del operador salida
          friend ostream & operator<<(ostream &,const  TVectorCalendario &);
};


#endif
