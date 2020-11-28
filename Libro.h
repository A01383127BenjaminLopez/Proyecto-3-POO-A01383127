//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 3
///LIBRO
#include <iostream>
#include <string>
#include "Material.h"
#pragma once

class Libro: public Material{
private:
    int numPag;
    string Autor;

public:
///Constructores:
Libro();
Libro(int idM, string t, int nP, string A);

///Acceso:
int getnumPag();
string getAutor();

///Modificacion:
void setnumPag(int n);
void setAutor(string Au);


///Metodos abstractos:
    void muestraDatos();//Muestra los datos del objeto.
    int cantidadDiasPrestamo();//Regresa la cantidad de dias que permite prestar el material;
};

///Constructores:
Libro::Libro():Material(){
numPag=0;
Autor="N/Autor";
}

Libro::Libro(int idM, string t, int nP, string A):Material(idM, t){
numPag=nP;
Autor=A;
}

///Acceso:
int Libro::getnumPag(){
return numPag;
}

string Libro::getAutor(){
return Autor;
}


///Modificacion:
void Libro::setnumPag(int n){
numPag=n;
}

void Libro::setAutor(string Au){
Autor=Au;
}


///Metodods Abstractos:
void Libro::muestraDatos(){//Muestra los datos del objeto.
    cout<<"LIBRO"<<endl;
    cout<<"MATERIAL: "<<idMaterial<<endl;
    cout<<"TITULO: "<<titulo<<endl;
    cout<<"NUMERO PAGINAS: "<<numPag<<endl;
    cout<<"AUTOR: "<<Autor<<endl<<endl;
}

int Libro::cantidadDiasPrestamo(){
return 5;
}

