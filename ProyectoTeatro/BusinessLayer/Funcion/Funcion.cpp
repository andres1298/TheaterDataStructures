//
// Created by Andres on 11/20/2019.
//

#include "Funcion.h"
#include "../Reservas/ConstructorReservas/Constructores Concretos/ConsZonaPreferencial.h"
#include "../Reservas/ConstructorReservas/Constructores Concretos/ConsGraderialPreferencial.h"
#include "../Reservas/ConstructorReservas/Constructores Concretos/ConsGraderiaGeneral.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

Funcion::Funcion(string pNombreObra, int pCantidadZonaPreferencial, int pCantidadGraderiaPreferencial,
                 int pCantidadGraderiaGeneral) {
    setNombreObra(pNombreObra);
    setZonaPreferencial(ZonaPreferencial(pCantidadZonaPreferencial));
    setGraderiaPreferencial(GraderiaPreferencial(pCantidadGraderiaPreferencial));
    setGraderiaGeneral(GraderiaGeneral(pCantidadGraderiaGeneral));
    setDirectorReservas(DirectorConstruccion());
    setHaIniciado(false);
}

Funcion::Funcion() {
    setNombreObra("");
    setZonaPreferencial(ZonaPreferencial(0));
    setGraderiaPreferencial(GraderiaPreferencial(0));
    setGraderiaGeneral(GraderiaGeneral(0));
    setDirectorReservas(DirectorConstruccion());
    setHaIniciado(false);
}

/*
 * =================
 * GETTERS
 * =================
 */

const string &Funcion::getNombreObra() const {
    return nombreObra;
}

 ZonaPreferencial &Funcion::getZonaPreferencial()  {
    return zonaPreferencial;
}

 GraderiaPreferencial &Funcion::getGraderiaPreferencial()  {
    return graderiaPreferencial;
}

GraderiaGeneral &Funcion::getGraderiaGeneral()  {
    return graderiaGeneral;
}

DirectorConstruccion &Funcion::getDirectorReservas() {
    return directorReservas;
}

bool Funcion::isHaIniciado() const {
    return haIniciado;
}

/*
 * =================
 * SETTERS
 * =================
 */

void Funcion::setNombreObra(const string &nombreObra) {
    Funcion::nombreObra = nombreObra;
}

void Funcion::setZonaPreferencial(const ZonaPreferencial &zonaPreferencial) {
    Funcion::zonaPreferencial = zonaPreferencial;
}

void Funcion::setGraderiaPreferencial(const GraderiaPreferencial &graderiaPreferencial) {
    Funcion::graderiaPreferencial = graderiaPreferencial;
}

void Funcion::setGraderiaGeneral(const GraderiaGeneral &graderiaGeneral) {
    Funcion::graderiaGeneral = graderiaGeneral;
}

void Funcion::setDirectorReservas(const DirectorConstruccion &directorReservas) {
    Funcion::directorReservas = directorReservas;
}

void Funcion::setHaIniciado(bool haIniciado) {
    Funcion::haIniciado = haIniciado;
}

/*
 * =================
 * CONSTRUCCION RESERVAS
 * =================
 */

Reserva Funcion::procesarSolicitudReserva(int pOpcion) {
    Reserva reserva;

    switch ( pOpcion ){
        case 1:
            {
                ConsZonaPreferencial constructor = ConsZonaPreferencial();
                directorReservas.construirReserva(&constructor);
                reserva = constructor.getReserva();
                return reserva;
            }

        case 2:
            {
                ConsGraderialPreferencial constructor = ConsGraderialPreferencial();
                directorReservas.construirReserva(&constructor);
                reserva = constructor.getReserva();
                return reserva;
            }

        case 3:
            {
                ConsGraderiaGeneral constructor = ConsGraderiaGeneral();
                directorReservas.construirReserva(&constructor);
                reserva = constructor.getReserva();
                return reserva;
            }

        default:
            return  Reserva();
    }


}

/*
 * =================
 * SOLICITUDES CLIENTE
 * =================
 */

string Funcion::procesarAgregarReserva(int pOpcion) {
    Reserva reserva;

    switch ( pOpcion ){
        case 2:
            {
                reserva = procesarSolicitudReserva(pOpcion);
                return getGraderiaPreferencial().agregarReserva(reserva);
            }

        case 3:
            {
                reserva = procesarSolicitudReserva(pOpcion);
                return getGraderiaGeneral().agregarReserva(reserva);
            }

        default:
            {
                return "\nPor favor digite una opcion valida";
            }
    }
}

string Funcion::procesarAgregarReserva(int pOpcion, int pAsiento) {
    if(pAsiento > 10 || pAsiento < 1){
        return "Por favor digite un numero de asiento valido";
    }
    else{
        Reserva reserva = procesarSolicitudReserva(pOpcion);
        return getZonaPreferencial().agregarReserva(reserva, pAsiento);
    }
}

string Funcion::procesarPagarReserva(int pOpcion) {

    switch ( pOpcion ){
        case 2:
        {
            return getGraderiaPreferencial().pagarReserva();
        }

        case 3:
        {
            return getGraderiaGeneral().pagarReserva();
        }

        default:
        {
            return "\nPor favor digite una opcion valida";
        }
    }
}

string Funcion::procesarPagarReserva(int pOpcion, int pAsiento) {
    if(pAsiento > 10 || pAsiento < 1){
        return "Por favor digite un numero de asiento valido";
    }
    else{
        return getZonaPreferencial().pagarReserva(pAsiento);
    }
}

/*
 * =================
 * LIBERAR RESERVACIONES
 * =================
 */

//Este metodo permite centralizar los procesos de liberar las reservaciones que no fueron pagadas antes de la funcion
//Ademas de agregar las reservas pendientes que estan en las listas de espera a cada una de las localidades

string Funcion::liberarReservaciones() {
    string informacion;
    informacion.append("\nInformacion de reservas liberadas\n");
    informacion.append("==========================================\n");
    informacion.append(getZonaPreferencial().liberarReservaciones() + "\n");
    informacion.append(getGraderiaPreferencial().liberarReservaciones() + "\n");
    informacion.append(getGraderiaGeneral().liberarReservaciones() + "\n");

    informacion.append("\nInformacion de reservas en cola\n");
    informacion.append("==========================================\n");
    informacion.append(getZonaPreferencial().liberarColaEspera() + "\n");
    informacion.append(getGraderiaPreferencial().liberarColaEspera() + "\n");
    informacion.append(getGraderiaGeneral().liberarColaEspera() + "\n");
    return informacion;
}

/*
 * =================
 * INICIAR OBRA
 * =================
 */

string Funcion::iniciarObra() {
    string informacion;
    informacion.append(getZonaPreferencial().obtenerEstadisticas() + "\n");
    informacion.append(getGraderiaPreferencial().obtenerEstadisticas() + "\n");
    informacion.append(getGraderiaGeneral().obtenerEstadisticas() + "\n");

    informacion.append("\n    Total recaudado ");
    informacion.append("\n============================");
    informacion.append("\n" + to_string(calcularRecaudacionTotal()) + " colones");

    setHaIniciado(true);

    return informacion;
}

double Funcion::calcularRecaudacionTotal() {
    double recaudacion = 0;
    int recaudacionZonaPreferencial = 0, recaudacionGraderiaPreferencial = 0, recaudacionGraderiaGeneral = 0;

    recaudacionZonaPreferencial = getZonaPreferencial().getCantidadPagada() * 7000;
    recaudacionGraderiaPreferencial = getGraderiaPreferencial().getCantidadPagada() * 5500;
    recaudacionGraderiaGeneral = getGraderiaGeneral().getCantidadPagada() * 4000;

    recaudacion = recaudacionZonaPreferencial + recaudacionGraderiaPreferencial + recaudacionGraderiaGeneral;

    return recaudacion;
}







