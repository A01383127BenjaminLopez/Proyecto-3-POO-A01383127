//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 3
///Fecha

#include <iostream>
#pragma once

using namespace std;

class Fecha{
private:
    int dd;
    int mm;
    int aa;

public:
    ///Constructores:
    Fecha();
    Fecha(int d, int m, int a);

    ///ACCESO
    int getdd();
    int getmm();
    int getaa();

    ///Modificacion
    void setFecha(int d, int m, int a);

    ///Sobrecarga de operadores
    Fecha operator+(int m);//Calcula fecha agregandole Días.

    //Consulta de Fechas
    bool operator>=(Fecha F);
    bool operator<=(Fecha F);
    bool operator==(Fecha F);
    bool operator>(Fecha F);
    bool operator<(Fecha F);

    friend istream& operator>>(istream &i, Fecha &F);//Cin
    friend ostream& operator<<(ostream &o, Fecha &F);//Cout*/

    ///Nombre del Mes
    string nombreMes(int m);
};

///Constructores:
    Fecha::Fecha(){
    dd=0;
    mm=0;
    aa=0;
    }

    Fecha::Fecha(int d, int m, int a){
    dd=d;
    if(m<1 || m>12)
        cout<<"INTRODUZCA UN MES VALIDO (1 - 12)"<<endl;
    else
    mm=m;

    aa=a;
    }

///ACCESO
    int Fecha::getdd(){
    return dd;
    }

    int Fecha::getmm(){
    return mm;
    }

    int Fecha::getaa(){
    return aa;
    }

///Modificacion
    void Fecha::setFecha(int d, int m, int a){
    dd=d;
     if(m<1 || m>12)
        cout<<"INTRODUZCA UN MES VALIDO (1 - 12)"<<endl;
    else
    mm=m;

    aa=a;
    }

///Sobrecarga de operadores
    Fecha Fecha::operator+(int d){//Calcula fecha agregandole Días.
        int diasTemp=0;
        if(d>30||d<0){
            cout<<"SOLAMENTE se pueden SUMAR de 0 - 30 dias."<<endl;
            //return 0;///CHECAR QUE NO SE ACABE EL PROGRAMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
        }
        else{
        diasTemp=dd+d;
        }

        if (diasTemp>31&&mm==12)
        {
            aa=aa+1;
            mm=1;
            diasTemp=diasTemp-31;
            }

        else if (mm==1 && diasTemp>31 || mm==3 && diasTemp>31 || mm==5 && diasTemp>31 || mm==7 && diasTemp>31 || mm==8 && diasTemp>31 || mm==10 && diasTemp>31)
        {
            mm=mm+1;
            diasTemp=diasTemp-31;
            }
        else if (mm==4 && diasTemp>30|| mm==6 && diasTemp>30 || mm==9 && diasTemp>30 || mm==11 && diasTemp>30)
        {
            mm=mm+1;
            diasTemp=diasTemp-30;
            }

        else if(mm==2 && diasTemp>28){
            mm=mm+1;
            diasTemp=diasTemp-28;
        }

        Fecha T1(diasTemp, mm, aa);
        return T1;

   /* if(mm==01 && diasTemp>31 || mm==03 && diasTemp>31 || mm==05 && diasTemp>31 || mm==07 && diasTemp>31 || mm==07 && diasTemp>31 || mm==08 && diasTemp>31 || mm==10 && diasTemp>31 || mm==12 && diasTemp>31){
        for(int i=0; i<999; i++){

        }*/
    }

    //Consulta de Fechas
    bool Fecha::operator>=(Fecha F){
        if (aa>=F.aa)
            return true;
        else if(aa==F.aa && mm>=F.mm)
            return true;
        else if(aa==F.aa && mm==F.mm && dd>=F.dd)
            return true;
        else if(aa==F.aa && mm==F.mm && dd==F.dd)
            return true;
            else
        return false;
    }

    bool Fecha::operator<=(Fecha F){
        if (aa<=F.aa)
            return true;
        else if(aa==F.aa && mm<=F.mm)
            return true;
        else if(aa==F.aa && mm==F.mm && dd<=F.dd)
            return true;
        else if(aa==F.aa && mm==F.mm && dd==F.dd)
            return true;
            else
        return false;
    }

    bool Fecha::operator==(Fecha F){
    if (aa==F.aa && mm==F.mm && dd==F.dd)
        return true;
        else
        return false;
    }

    bool Fecha::operator>(Fecha F){
           if (aa>F.aa)
            return true;
        else if(aa==F.aa && mm>F.mm)
            return true;
        else if(aa==F.aa && mm==F.mm && dd>F.dd)
            return true;
            else
        return false;
    }

    bool Fecha::operator<(Fecha F){
    if (aa<F.aa)
            return true;
        else if(aa==F.aa && mm<F.mm)
            return true;
        else if(aa==F.aa && mm==F.mm && dd<F.dd)
            return true;
            else
        return false;
    }

    /// Cin / Cout
    istream& operator>>(istream &i, Fecha &F)//CIN
    {
    cout<<endl;
    cout<<"Dia : ";
    i>>F.dd;
    cout<<"Mes : ";
    i>>F.mm;
    cout<<"Anhio : ";
    i>>F.aa;
    return i;
    }

    ostream& operator<<(ostream &o, Fecha &F)//Cout
    {
    o<<"Dia : "<<F.dd<<endl;
    o<<"Mes : "<<F.nombreMes(F.mm)<<endl;
    o<<"Anhioo : "<<F.aa<<endl;
    return o;
    }

    ///Nombre del Mes
    string Fecha::nombreMes(int m){
    string mes;
    if(m==1)
        mes="Ene";
    else if(m==2)
        mes="Feb";
        else if(m==3)
        mes="Mar";
    else if(m==4)
        mes="Abr";
    else if(m==5)
        mes="May";
    else if(m==6)
        mes="Jun";
    else if(m==7)
        mes="Jul";
    else if(m==8)
        mes="Ago";
    else if(m==9)
        mes="Sep";
    else if(m==10)
        mes="Oct";
        else if(m==11)
        mes="Nov";
    else if(m==12)
        mes="Dic";

    return mes;
    }
