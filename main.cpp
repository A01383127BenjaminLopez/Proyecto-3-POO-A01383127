#include <iostream>
#include <string>
#include <fstream>
#include "Fecha.h"
#include "Reserva.h"
#include "Material.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

using namespace std;

int main()
{
    ///Arreglo Apuntadores para Material
Material *arrM[30];

    ///Arreglo Reservaciones
Reserva arrR[60];

///Para abrir los archivos:
ifstream archMaterial;
ifstream archReserva;

///Asignando datos al arreglo de Material.
//Auxiliares de lectura...
string linea1;
int temp1;
int cont1=0;
int idMa;
string titulo;
string tipoMaterial;
int nPag;
int duracion;
int version;
string autor;
string genero;
string SO;
archMaterial.open("Material.txt");
while (getline(archMaterial, linea1)) {
    temp1 = linea1.find(" ");
    idMa =stoi(linea1.substr(0, temp1));
    linea1=linea1.erase(0, temp1+1);

    temp1 = linea1.find(" ");
    titulo =(linea1.substr(0, temp1));
    linea1=linea1.erase(0, temp1+1);

    temp1 = linea1.find(" ");
    tipoMaterial =(linea1.substr(0, temp1));
    linea1=linea1.erase(0, temp1+1);

    /*cout<<idMa<<endl;
    cout<<titulo<<endl;
    cout<<tipoMaterial<<endl;*/

    if (tipoMaterial=="L"){
    temp1 = linea1.find(" ");
    nPag =stoi(linea1.substr(0, temp1));
    linea1=linea1.erase(0, temp1+1);

    temp1 = linea1.find(" ");
    autor =(linea1.substr(0));

    arrM[cont1]= new Libro(idMa, titulo, nPag, autor);
    /*cout<<nPag<<endl;
    cout<<autor<<endl;*/
    }

    else if(tipoMaterial=="D"){
    temp1 = linea1.find(" ");
    duracion =stoi(linea1.substr(0, temp1));
    linea1=linea1.erase(0, temp1+1);

    temp1 = linea1.find(" ");
    genero =(linea1.substr(0));

    arrM[cont1]=new Disco(idMa, titulo, duracion, genero);
    /*cout<<duracion<<endl;
    cout<<genero<<endl;*/
    }

    else if(tipoMaterial=="S"){
    temp1 = linea1.find(" ");
    version =stoi(linea1.substr(0, temp1));
    linea1=linea1.erase(0, temp1+1);

    temp1 = linea1.find(" ");
    SO =(linea1.substr(0));

    arrM[cont1]=new Software(idMa, titulo, version, SO);
    /*cout<<version<<endl;
    cout<<SO<<endl;*/
    }

    //arrM[cont1]->muestraDatos();

    cont1++;

}
archMaterial.close();


///Asignando datos al arreglo de Reservas.
string linea2;
int temp2;
int cont2=0;
int d;
int m;
int a;
int idM;
int idC;
archReserva.open("Reserva.txt");


ofstream archSalida;
archSalida.open("Experimento.txt");


while (getline(archReserva, linea2)) {
    temp2 = linea2.find(" ");
    d =stoi(linea2.substr(0, temp2));
    linea2=linea2.erase(0, temp2+1);

    temp2 = linea2.find(" ");
    m =stoi(linea2.substr(0, temp2));
    linea2=linea2.erase(0, temp2+1);

    temp2 = linea2.find(" ");
    a =stoi(linea2.substr(0, temp2));
    linea2=linea2.erase(0, temp2+1);

    temp2 = linea2.find(" ");
    idM =stoi(linea2.substr(0, temp2));
    linea2=linea2.erase(0, temp2+1);

    temp2 = linea2.find(" ");
    idC =stoi(linea2.substr(0));
    linea2=linea2.erase(0, temp2+1);

    Fecha F(d, m, a);

    arrR[cont2].setfechaReservacion(F);
    arrR[cont2].setidMaterial(idM);
    arrR[cont2].setidCliente(idC);

    archSalida<<F.getdd()<<" "<<F.getmm()<<" "<<F.getaa()<<" "<<idM<<" "<<idC<<endl;

    /*cout<<F.getdd()<<endl;
    cout<<F.getmm()<<endl;
    cout<<F.getaa()<<endl;
    cout<<arrR[cont2].getidMaterial()<<endl;
    cout<<arrR[cont2].getidCliente()<<endl;*/

    cont2++;


}
archReserva.close();

///////////////////////////////////////////////////////////////////////////////////////////////////////

///Menu principal:
char opcion;
while (opcion != 'f'||opcion != 'F') {
cout<<endl;
cout<<"---MENU PRINCIPAL---"<<endl<<endl;
cout<<"a) Consultar lista de MATERIALES. "<<endl;
cout<<"b) Consultar lista de RESERVACIONES. "<<endl;
cout<<"c) Consultar las RESERVACIONES de un MATERIAL deseado. "<<endl;
cout<<"d) Consultar las RESERVACIONES de una FECHA deseada. "<<endl;
cout<<"e) Hacer una RESERVACION. "<<endl;
cout<<"f) Terminar. "<<endl<<endl;
cout<<"QUE DESEA HACER? ";
cin>>opcion;


///OPCION A.
if (opcion=='a' || opcion=='A'){
cout<<endl<<endl;
cout<<"Desplegando LISTA de MATERIALES..."<<endl;

for (int i=0; i<cont1; i++){
    arrM[i]->muestraDatos();
}

}

///OPCION B.
if (opcion=='b' || opcion=='B'){
cout<<endl<<endl;
cout<<"Desplegando LISTA de RESERVACIONES..."<<endl;

for (int i=0; i<cont2; i++){
    cout<<"ID CLIENTE: "<<arrR[i].getidCliente()<<endl;
    cout<<"ID MATERIAL: "<<arrR[i].getidMaterial()<<endl;

    for(int x=0; x<cont1; x++){
    if(arrR[i].getidMaterial()==arrM[x]->getidMaterial())
    cout<<"Nombre Material: "<<arrM[x]->gettitulo()<<endl;
    }
    Fecha F;
    F=arrR[i].getfechaReservacion();
    cout<<"Fecha de inicio de Reserva: "<<endl;
    cout<<F<<endl;
    cout<<"Fecha FIN de Reserva: "<<endl;
    Fecha F2;

    for(int x=0; x<cont1; x++){
    if(arrR[i].getidMaterial()==arrM[x]->getidMaterial()){
    int temp=arrM[x]->cantidadDiasPrestamo();
    F2=F+temp;
    cout<<F2<<endl;
    }
    }
}

}

///OPCION C.
if (opcion=='c' || opcion=='C'){
cout<<endl;
int idMat;
cout<<"Cual es el ID del MATERIAL que desea consultar? ";
cin>>idMat;

for (int i=0; i<cont2; i++){
    if(idMat==arrR[i].getidMaterial()){
        cout<<endl<<"El Material siguiente material se encuentra reservado..."<<endl;

    for(int x=0; x<cont1; x++){
    if(idMat==arrM[x]->getidMaterial())
    cout<<"Nombre Material: "<<arrM[x]->gettitulo()<<endl;
    }
        Fecha F;
    F=arrR[i].getfechaReservacion();
    cout<<"Fecha de inicio de Reserva: "<<endl;
    cout<<F<<endl;
    cout<<"Fecha FIN de Reserva: "<<endl;
    Fecha F2;

    for(int x=0; x<cont1; x++){
    if(arrR[i].getidMaterial()==arrM[x]->getidMaterial()){
    int temp=arrM[x]->cantidadDiasPrestamo();
    F2=F+temp;
    cout<<F2<<endl;
    }
    }
    }//del if
    /*for(int a=0; a<cont1; a++){
    if(idMat==arrM[a]->getidMaterial())
        cout<<"EL MATERIAL NO SE ENCUENTRA RESERVADO!!!"<<endl;
        else
            cout<<"EL ID ingreso no coincide con ninguno en la BASE DE DATOS..."<<endl;
    }*/

}//del for

}


///Opcion D.
if (opcion=='d' || opcion=='D'){
cout<<"En que fecha desea consultar? ";
Fecha F;
cin>>F;
cout<<endl;

for(int i=0; i<cont2; i++){
    Fecha arrFfin[cont2];

    for(int x=0; x<cont1; x++){
    if(arrR[i].getidMaterial()==arrM[x]->getidMaterial()){
    int temp=arrM[x]->cantidadDiasPrestamo();
    Fecha F1;
    F1=arrR[i].getfechaReservacion();
    arrFfin[i]=F1+temp;
    }
    }

    if((arrR[i].getfechaReservacion()<F && arrFfin[i]>F) || (arrR[i].getfechaReservacion()==F || arrFfin[i]==F) ){

        for(int x=0; x<cont1; x++){
    if(arrR[i].getidMaterial()==arrM[x]->getidMaterial()){
    cout<<"Nombre del Material RESERVADO: "<<arrM[x]->gettitulo()<<endl;
    }
    }

    cout<<"ID CLIENTE: "<<arrR[i].getidCliente()<<endl<<endl;

    }


}

}


///Opcion E.
if (opcion=='E' || opcion=='e'){
int idCl;
int idMater;
Fecha F;
cout<<"Dame tu idCliente: ";
cin>>idCl;
cout<<"Dame el idMaterial de lo que deseas RESERVAR: ";
cin>>idMater;
cout<<"Por ultimo dame la fecha en la que deseas RESERVAR: ";
cin>>F;
cout<<endl;

for(int z=0; z<cont1; z++){
    if(idMater==arrM[z]->getidMaterial()){
        cout<<"idMaterial VALIDADO!!!"<<endl;
        cout<<"NOMBRE: "<<arrM[z]->gettitulo()<<endl<<endl;
    archSalida<<F.getdd()<<" "<<F.getmm()<<" "<<F.getaa()<<" "<<idMater<<" "<<idCl<<endl;
    cout<<"Reservacion realizada......."<<endl;
    archSalida.close();

    }
}



    }

























///Opcion f.
if (opcion=='f' || opcion=='F'){
cout<<endl<<endl;
cout<< "Gracias por utilizar nuestro programa!"<<endl;

    return 0;

}


}//Menu



}//int main








    /*Fecha F1(25, 02, 1990);
    Fecha F2(20, 02, 2010);
    if (F1<F2){
    cout<<"La afirmacion es correcta";
    }
    cin>>F2;
    cout<<F1;
    cout<<F2;

    Reserva R1(100, 123, F2);
    R1.calculaFechaFinReserva(30);*/

    /*Libro L(5, "hola", 76, "XD");
    L.muestraDatos();
    cout<<endl;
    cout<<L.cantidadDiasPrestamo();
cout<<endl;

    Disco D(15, "Adios", 76, "KEASE");
    D.muestraDatos();
    cout<<endl;
    cout<<D.cantidadDiasPrestamo();

     Software S(-50, "carlitos", 698, "TOSTADO");
    S.muestraDatos();
    cout<<endl;
    cout<<S.cantidadDiasPrestamo();

    cout<<endl<<endl;
Fecha F(28, 12, 30);
Reserva R(100, 50, F);
cout<<"R: "<<R.getidMaterial()<<R.getidCliente();
cout<<F.getdd()<<F.getmm()<<F.getaa()<<endl;
/*


/*    Material Libro(1, "LOs");
    M.setidMaterial(50);
    M.settitulo("jejeje");
    cout<<M.getidMaterial()<<M.gettitulo();/*


Fecha F(10, 10, 10);
Reserva R;
cout<<"R: "<<R.getidMaterial()<<R.getidCliente();
F=R.getfechaReservacion();
cout<<F.getdd()<<F.getmm()<<F.getaa()<<endl;*/

/*Fecha F(10, 7, 99);
cout<<F.getdd()<<F.getmm()<<F.getaa()<<endl;
F.setFecha(7, 5, 88);
cout<<F.getdd()<<F.getmm()<<F.getaa()<<endl<<endl;
Fecha F1(20, 1, 20);
F1=F1+9;
cout<<F1.nombreMes(F1.getmm());
//F==F1;//Muestra la segunda fecha nomas.
//cout<<F1.getdd()<<" "<<F1.getmm()<<" "<<F1.getaa();
//cout<<F.getdd()<<F.getmm()<<F.getaa()<<endl;*/
