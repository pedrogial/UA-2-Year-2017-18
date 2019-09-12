#include "tcalendario.h"
#include <stdlib.h>
#include <cstring>
using namespace std;
ostream &operator << (ostream &o,const TCalendario &calendario)
{
	if(calendario.Dia() < 10)
		o << 0;
	o << calendario.Dia() << '/';
	if(calendario.Mes() < 10)
		o << 0;
	o << calendario.Mes() << '/';
	o << calendario.Anyo();
	o << ' ' << '"';
	if(calendario.Mensaje() != NULL)
		o << calendario.Mensaje();
	o << '"';
	return o;
}

bool TCalendario::EsFecha() const //true si fecha menor o igual a 01/01/1900
{
	bool es = false;

	if(anyo < 1900)
		es = true;
	else
		if(anyo == 1900  && dia == 1 && mes == 1){
			es = true;
		}
	return es;
}

TCalendario::TCalendario(){
	dia = 1;
	mes = 1;
	anyo = 1900;
	mensaje = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo,char *mens){
	if(!ModFecha(dia, mes, anyo)){
		this->dia = 1;
		this->mes = 1;
		this->anyo = 1900;
		this->mensaje = NULL;
	}
	else{
		mensaje = NULL;
		ModMensaje(mens);
	}
}

TCalendario::~TCalendario(){
	dia = 1;
	mes = 1;
	anyo = 1900;
	if(mensaje != NULL){
		delete []mensaje;
		mensaje = NULL;
	}
}

TCalendario::TCalendario(const TCalendario &calendario){
	this->dia = calendario.dia;
	this->mes = calendario.mes;
	this->anyo = calendario.anyo;
	if(calendario.mensaje != NULL){
		this->mensaje = new char[strlen(calendario.mensaje) + 1]; //para el '/0'
		strcpy(mensaje, calendario.mensaje);
	}
	else{
		this->mensaje=NULL;
	}
}


TCalendario &TCalendario::operator++(){
	if(dia == 30){
		if(mes==4|| mes==6 || mes==9 || mes==11){
			dia=1;
			mes++;
		}
		else
			dia++;
	}
	else
		if(dia==31){
			if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
				dia=1;             
				mes++;	   
				if(mes==13){	
					mes = 1;
					anyo = anyo + 1; 
				}
			}
		}
		else
			if(mes == 2){
				if((anyo%4==0 && anyo%100!=0) || (anyo%100==0 && anyo%400==0)){
					if(dia==29){
						dia = 1;
						mes++;
					}
					else
						dia++;
				}
				else
					if(dia == 28){
						dia = 1;
						mes++;
					}
					else
						dia++;
			}
			else 
				dia++;
		
	return *this;
}

TCalendario TCalendario::operator ++ (int fecha) //PostIncremento
{
	TCalendario auxiliar(*this);
	++(*this); 
	return auxiliar;
}

TCalendario TCalendario::operator -- (int fecha) //PostDecremento
{
	TCalendario auxiliar(*this);
	if(!(EsFecha()))
		--(*this); //Utilizar preincremento
	return auxiliar;
}


TCalendario &TCalendario::operator --()
{

	if(!(EsFecha()))
	{
		if(dia==1)
		{
			if(mes==3)
			{
				if((anyo%4==0 && anyo%100!=0) || (anyo%100==0 && anyo%400==0))
					dia=29;
					
				else
					dia=28;
				mes--;
			}
			else{ 
				if(mes==1)
			{
				anyo--;
				mes=12;
				dia=31;
			}
				else{ 
					if( mes==2 || mes==4 || mes==6 || mes==9 ||mes==8|| mes==11)
					{
						dia=31;
						mes--;
					}
					else
						{	
						dia=30;
						mes--;
						}
					}
				}
		}
		else
			dia--;
	}
	else{
			if(mensaje != NULL){
				delete [] mensaje;
				mensaje = NULL;
			}
	}
	return *this;

}

TCalendario TCalendario::operator + (int fecha)
{
TCalendario calendarioaux(*this);                 //se debe de añadir este aux por que sino los cambios tambien lo realizas sobre el propio objeto y no!
	if(fecha>0)
	{
		for(int i=0; i<fecha; i++)
			(calendarioaux)++;
	}

	
	return calendarioaux;

}

TCalendario TCalendario::operator - (int fecha)
{
TCalendario calendarioaux(*this); //aqui igual
	if(fecha>0)
	{
		for(int i=0; i<fecha; i++)
			(calendarioaux)--;
	}
	if(calendarioaux.EsFecha())  //comprueba que no se salga del rango al restar
	{
		if(calendarioaux.mensaje!=NULL)
			delete calendarioaux.mensaje;
		calendarioaux.mensaje=NULL;	//Si se sale pos volvemos a colocar el objeto
	}
	return calendarioaux;	
}

bool TCalendario::ModFecha (int dia, int mes, int anyo)
{
	bool correcta=true;

	if(anyo<1900 || dia < 0 || mes < 0)
		correcta=false;
	else
	if (mes<=0 || mes>12)
		correcta=false;
	else if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
		{
			if(dia<=0 || dia>31)
				correcta=false;
		}
		else if (mes==4|| mes==6 || mes==9 || mes==10)
		{
			if(dia<=0 || dia>30)
				correcta=false;
		}
			else if (mes==2)
			{
				if(anyo%4==0)
				{
					if(dia<=0 || dia>29)
							correcta=false;
				}
				else if(dia<=0 || dia>28)
							correcta=false;
			}
	
	if(correcta)
	{
		this->dia = dia;
		this->mes = mes;
		this->anyo = anyo;
	}
/*	
	else
	{
		this->dia = 1;
		this->mes = 1;
		this->anyo = 1900;	
	}
*/
	return correcta;
}

bool TCalendario::operator!=(const TCalendario &de) const{
	return !(*this == de);
}

bool TCalendario::ModMensaje (char *mens){
	bool done = false;
	if(mens != NULL){
		done = true;
		if(this->mensaje!=NULL){
			delete [] mensaje;
		}
		this->mensaje = NULL;
		this->mensaje = new char[(strlen(mens))+1];
		strcpy(this->mensaje,mens);
	}
	else{
		done = true;
		this->mensaje = NULL;
	}
	return done;
}

bool TCalendario::operator == (const TCalendario &calendario)	const	
{
	bool iguales=false;
if(&calendario && this){
	if(dia==calendario.dia && mes==calendario.mes && anyo==calendario.anyo)
		if(calendario.mensaje!=NULL && mensaje!=NULL)
		{
			if(strcmp(mensaje,calendario.mensaje)==0)
				iguales=true;
		}
		else
			if(calendario.mensaje==NULL && mensaje==NULL)
				iguales=true;
}
	return iguales;
}

bool TCalendario::operator > (const TCalendario &calendario) const
{
	bool mayor=false;
	if(anyo>calendario.anyo)
		mayor=true;
	else
		if(anyo==calendario.anyo)
			if(mes>calendario.mes)
				mayor=true;
			else
				if(mes==calendario.mes)
					if(dia>calendario.dia)
						mayor=true;
					else
						if(dia==calendario.dia)
							if( mensaje && calendario.mensaje==NULL )
								mayor=true;
							else
							if(mensaje && calendario.mensaje && strcmp(mensaje,calendario.mensaje) > 0)
								mayor=true;
	return mayor;
}

bool TCalendario::operator < (const TCalendario &calendario) const
{
		bool menor=false;
	if(anyo<calendario.anyo)
		menor=true;
	else
		if(anyo==calendario.anyo)
			if(mes<calendario.mes)
				menor=true;
			else
				if(mes==calendario.mes)
					if(dia<calendario.dia)
						menor=true;
					else
						if(dia==calendario.dia)
							if(mensaje==NULL && calendario.mensaje)
								menor=true;
							else
							if(mensaje && calendario.mensaje && strcmp(mensaje,calendario.mensaje)==-1)
								menor=true;
	return menor;
}

bool TCalendario::EsVacio() const
{
	bool vacio=false;
	if(EsFecha() && mensaje==NULL)
		vacio=true;
	return vacio;
}


	
int TCalendario::Dia() const
{
	return dia;
}

int TCalendario::Mes() const
{
	return mes;
}

int TCalendario::Anyo() const
{
	return anyo;
}

char *TCalendario::Mensaje() const
{
	if(mensaje!=NULL)
		return mensaje;
	else
		return '\0';
}



TCalendario & TCalendario::operator=(const TCalendario &c)
{
	if(this!=&c)
	{
		(*this).~TCalendario();
		dia=c.dia;
		mes=c.mes;
		anyo=c.anyo;
		if(c.mensaje!=NULL)
		{
			mensaje=new char[strlen(c.mensaje)+1]; 
			strcpy(mensaje,c.mensaje);
		}
		else
			mensaje=NULL;
	}
	return *this;
}
/***+++++++++***++*++++++++**+++**++++++++**++**+++++++***++**+++++++***++**++++++*****+++++*/
