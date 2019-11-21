//
// Created by Andres on 11/20/2019.
//

#include "NodoReserva.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

NodoReserva::NodoReserva(const Reserva &pInformacion){
    setInformacion(pInformacion);
    setSiguiente(nullptr);
}

NodoReserva::NodoReserva() {
    setInformacion(Reserva());
    setSiguiente(nullptr);
}

/*
 * =================
 * GETTERS
 * =================
 */

const Reserva NodoReserva::getInformacion() const {
    return informacion;
}

NodoReserva *NodoReserva::getSiguiente() const {
    return siguiente;
}

/*
 * =================
 * SETTERS
 * =================
 */

void NodoReserva::setInformacion(const Reserva &informacion) {
    NodoReserva::informacion = informacion;
}

void NodoReserva::setSiguiente(NodoReserva *siguiente) {
    NodoReserva::siguiente = siguiente;
}
