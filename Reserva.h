//Benjamin Guillermo Lopez Salinas A01383127
//Proyecto 3
///RESERVA

#include <iostream>
#include "Fecha.h"

using namespace std;

class Reserva{
    private:
        int idMaterial;
        int idCliente;
        Fecha fechaReservacion;

    public:
        ///Constructores
        Reserva ();
        Reserva (int idM, int idC, Fecha fR);

        ///ACCESO
        int getidMaterial();
        int getidCliente();
        Fecha getfechaReservacion();

        ///Modificacion
        void setidMaterial(int idM);
        void setidCliente(int idC);
        void setfechaReservacion(Fecha F);

        ///Calcular Fecha
        Fecha calculaFechaFinReserva(int cD);

};

    ///Constructores
    Reserva::Reserva (){
    idMaterial=0;
    idCliente=0;
    Fecha F;
    fechaReservacion=F;
    }

    Reserva::Reserva (int idM, int idC, Fecha fR){
    idMaterial=idM;
    idCliente=idC;
    fechaReservacion=fR;
    }

    ///ACCESO
    int Reserva::getidMaterial(){
    return idMaterial;
    }

    int Reserva::getidCliente(){
    return idCliente;
    }

    Fecha Reserva::getfechaReservacion(){
    return fechaReservacion;
    }

    ///Modificacion
    void Reserva::setidMaterial(int idM){
    idMaterial=idM;
    }

    void Reserva::setidCliente(int idC){
    idCliente=idC;
    }

    void Reserva::setfechaReservacion(Fecha F){
    fechaReservacion=F;
    }

///Calcular Fecha Fin de reserva
    Fecha Reserva::calculaFechaFinReserva(int cD){
    Fecha F3;
    F3=fechaReservacion+cD;
    }
