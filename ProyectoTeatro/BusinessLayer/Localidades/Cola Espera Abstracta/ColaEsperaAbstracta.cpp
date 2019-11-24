//
// Created by Andres on 11/23/2019.
//

#include "ColaEsperaAbstracta.h"
/*
* =================
* CONSTRUCTORES
* =================
*/

ColaEsperaAbstracta::ColaEsperaAbstracta() {
    setFrente(nullptr);
    setFinal(nullptr);
    setCantidadReservas(0);
}

/*
* =================
* GETTERS
* =================
*/

NodoReserva *ColaEsperaAbstracta::getFrente() const {
    return frente;
}

NodoReserva *ColaEsperaAbstracta::getFinal() const {
    return final;
}

int ColaEsperaAbstracta::getCantidadReservas() const {
    return cantidadReservas;
}

/*
* =================
* SETTERS
* =================
*/

void ColaEsperaAbstracta::setFrente(NodoReserva *frente) {
    ColaEsperaAbstracta::frente = frente;
}

void ColaEsperaAbstracta::setFinal(NodoReserva *final) {
    ColaEsperaAbstracta::final = final;
}

void ColaEsperaAbstracta::setCantidadReservas(int cantidadReservas) {
    ColaEsperaAbstracta::cantidadReservas = cantidadReservas;
}

/*
* =================
* FUNCIONES ESPECIFICAS
* =================
*/