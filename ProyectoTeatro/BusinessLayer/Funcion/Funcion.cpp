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

Funcion::Funcion(string pNombreObra) {
    setNombreObra(pNombreObra);
    setZonaPreferencial(ZonaPreferencial(10));
    setGraderiaPreferencial(GraderiaPreferencial(50));
    setGraderiaGeneral(GraderiaGeneral(50));
    setDirectorReservas(DirectorConstruccion());
    setColaEsperaZonaPreferencial(ColaEspera());
    setColaEsperaGraderiaPreferencial(ColaEspera());
    setColaEsperaGraderiaGeneral(ColaEspera());
}

Funcion::Funcion() {
    setNombreObra("");
    setZonaPreferencial(ZonaPreferencial(0));
    setGraderiaPreferencial(GraderiaPreferencial(0));
    setGraderiaGeneral(GraderiaGeneral(0));
    setDirectorReservas(DirectorConstruccion());
    setColaEsperaZonaPreferencial(ColaEspera());
    setColaEsperaGraderiaPreferencial(ColaEspera());
    setColaEsperaGraderiaGeneral(ColaEspera());
}

/*
 * =================
 * GETTERS
 * =================
 */

const string &Funcion::getNombreObra() const {
    return nombreObra;
}

const ZonaPreferencial &Funcion::getZonaPreferencial() const {
    return zonaPreferencial;
}

const GraderiaPreferencial &Funcion::getGraderiaPreferencial() const {
    return graderiaPreferencial;
}

const GraderiaGeneral &Funcion::getGraderiaGeneral() const {
    return graderiaGeneral;
}

DirectorConstruccion &Funcion::getDirectorReservas() {
    return directorReservas;
}

 ColaEspera &Funcion::getColaEsperaZonaPreferencial() {
    return colaEsperaZonaPreferencial;
}

 ColaEspera &Funcion::getColaEsperaGraderiaPreferencial()  {
    return colaEsperaGraderiaPreferencial;
}

 ColaEspera &Funcion::getColaEsperaGraderiaGeneral()  {
    return colaEsperaGraderiaGeneral;
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

void Funcion::setColaEsperaZonaPreferencial(const ColaEspera &colaEsperaZonaPreferencial) {
    Funcion::colaEsperaZonaPreferencial = colaEsperaZonaPreferencial;
}

void Funcion::setColaEsperaGraderiaPreferencial(const ColaEspera &colaEsperaGraderiaPreferencial) {
    Funcion::colaEsperaGraderiaPreferencial = colaEsperaGraderiaPreferencial;
}

void Funcion::setColaEsperaGraderiaGeneral(const ColaEspera &colaEsperaGraderiaGeneral) {
    Funcion::colaEsperaGraderiaGeneral = colaEsperaGraderiaGeneral;
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
 * FUNCIONES ESPECIFICAS
 * =================
 */






