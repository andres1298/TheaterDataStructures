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
}

Funcion::Funcion() {
    setNombreObra("");
    setZonaPreferencial(ZonaPreferencial(0));
    setGraderiaPreferencial(GraderiaPreferencial(0));
    setGraderiaGeneral(GraderiaGeneral(0));
    setDirectorReservas(DirectorConstruccion());
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
                break;
            }

        case 2:
            {
                ConsGraderialPreferencial constructor = ConsGraderialPreferencial();
                directorReservas.construirReserva(&constructor);
                reserva = constructor.getReserva();
            }

            break;

        case 3:
            {
                ConsGraderiaGeneral constructor = ConsGraderiaGeneral();
                directorReservas.construirReserva(&constructor);
                reserva = constructor.getReserva();
                break;
            }

        default:
            reserva = Reserva();
            break;
    }

    return reserva;
}

/*
 * =================
 * LIBERAR RESERVACIONES
 * =================
 */

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







