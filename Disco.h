//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 3
///DISCO
#include <iostream>
#include <string>
#include "Material.h"
#pragma once

class Disco: public Material{
private:
    int duracion;
    string Genero;
public:
///Constructores
Disco();
Disco(int idM, string t, int d, string G);

///Acceso
int getDuracion();
string getGenero();

///Modificacion
void setDuracion(int d);
void setGenero(string g);

///Metodos abstractos:
    void muestraDatos();//Muestra los datos del objeto.
    int cantidadDiasPrestamo();//Regresa la cantidad de dias que permite prestar el material;
};

///Constructores
Disco::Disco():Material(){
duracion=0;
Genero="###";
}

Disco::Disco(int idM, string t, int d, string G):Material(idM, t){
duracion=d;
Genero=G;
}

///Acceso
int Disco::getDuracion(){
return duracion;
}

string Disco::getGenero(){
return Genero;
}

///Modificacion
void Disco::setDuracion(int d){
duracion=d;
}

void Disco::setGenero(string g){
Genero=g;
}

///Metodods Abstractos:
void Disco::muestraDatos(){//Muestra los datos del objeto.
    cout<<"DISCO"<<endl;
    cout<<"MATERIAL: "<<idMaterial<<endl;
    cout<<"TITULO: "<<titulo<<endl;
    cout<<"DURACION: "<<duracion<<" min"<<endl;
    cout<<"GENERO: "<<Genero<<endl<<endl;
}

int Disco::cantidadDiasPrestamo(){
return 3;
}
