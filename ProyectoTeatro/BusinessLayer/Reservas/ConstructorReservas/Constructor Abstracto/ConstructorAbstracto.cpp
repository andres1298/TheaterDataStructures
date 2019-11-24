//
// Created by Andres on 11/23/2019.
//

#include "ConstructorAbstracto.h"

/*
* =================
* CONSTRUCTORES
* =================
*/

ConstructorAbstracto::ConstructorAbstracto() {
    setReserva(Reserva());
}

/*
* =================
* GETTERS
* =================
*/

Reserva &ConstructorAbstracto::getReserva() {
    return reserva;
}

/*
* =================
* SETTERS
* =================
*/

void ConstructorAbstracto::setReserva(const Reserva &reserva) {
    ConstructorAbstracto::reserva = reserva;
}

/*
* =================
* FUNCIONES ESPECIFICAS
* =================
*/

void ConstructorAbstracto::construirReserva() {
    this->reserva = Reserva();
}


