//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 3
///MATERIAL
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Material{
protected:
    int idMaterial;
    string titulo;

public:
    ///Constructores
    Material();
    Material(int idM, string t);

    ///ACCESO:
    int getidMaterial();
    string gettitulo();

    ///Modificacion
    void setidMaterial(int idMa);
    void settitulo(string ti);

    ///Metodos abstractos:
    virtual void muestraDatos()=0;//Muestra los datos del objeto (NO SE DEBE IMPLEMENTAR AQUI).
    virtual int cantidadDiasPrestamo()=0;//Regresa la cantidad de dias que permite prestar el material(NO SE DEBE IMPLEMENTAR AQUI).

};

///Constructores
    Material::Material(){
    idMaterial=0;
    titulo="###";
    }

    Material::Material(int idM, string t){
    idMaterial=idM;
    titulo=t;
    }

///ACCESO:
    int Material::getidMaterial(){
    return idMaterial;
    }

    string Material::gettitulo(){
    return titulo;
    }

///Modificacion
    void Material::setidMaterial(int idMa){
    idMaterial=idMa;
    }

    void Material::settitulo(string ti){
    titulo=ti;
    }

