//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 3
///SOFTWARE
#include <iostream>
#include <string>
#include "Material.h"
#pragma once

class Software: public Material{
private:
    int Version;
    string SO;

public:
///CONSTRUCTORES
Software();
Software(int idM, string t, int V, string sis);

///Acceso
int getVersion();
string getSO();

///Modificacion
void setVersion(int V);
void setSO(string s);

///Metodos abstractos:
    void muestraDatos();//Muestra los datos del objeto.
    int cantidadDiasPrestamo();//Regresa la cantidad de dias que permite prestar el material;
};

///CONSTRUCTORES
Software::Software():Material(){
Version=0;
SO="###";
}

Software::Software(int idM, string t, int V, string sis):Material(idM, t){
Version=V;
SO=sis;
}

///Acceso
int Software::getVersion(){
return Version;
}

string Software::getSO(){
return SO;
}

///Modificacion
void Software::setVersion(int V){
Version=V;
}

void Software::setSO(string s){
SO=s;
}

///Metodods Abstractos:
void Software::muestraDatos(){//Muestra los datos del objeto.
    cout<<"SOFTWARE"<<endl;
    cout<<"MATERIAL: "<<idMaterial<<endl;
    cout<<"TITULO: "<<titulo<<endl;
    cout<<"VERSION: "<<Version<<endl;
    cout<<"SISTEMA OPERATIVO: "<<SO<<endl<<endl;
}

int Software::cantidadDiasPrestamo(){
return 1;
}
