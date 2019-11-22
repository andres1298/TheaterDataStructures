//
// Created by Andres on 11/20/2019.
//

#include "GraderiaPreferencial.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

GraderiaPreferencial::GraderiaPreferencial() : Localidad(){
    setTope(nullptr);
}

GraderiaPreferencial::GraderiaPreferencial(int pCantidad) : Localidad(pCantidad) {
    setTope(nullptr);
}

/*
 * =================
 * GETTER
 * =================
 */

NodoReserva *GraderiaPreferencial::getTope() const {
    return tope;
}

/*
 * =================
 * SETTER
 * =================
 */

void GraderiaPreferencial::setTope(NodoReserva *tope) {
    GraderiaPreferencial::tope = tope;
}

/*
 * =================
 * OVERWRITTEN
 * =================
 */

string GraderiaPreferencial::agregarReserva(Reserva pReserva) {
    if(validarEspacios()){
        NodoReserva* nodoReserva = new NodoReserva(pReserva);
        if(getTope() == nullptr){
            nodoReserva->setSiguiente(getTope());
            tope = nodoReserva;
        }
        else{
            nodoReserva->setSiguiente(getTope());
            tope = nodoReserva;
        }
        setCantidadReservada(getCantidadReservada() + 1);
        return "Reserva agregada";
    }
    else{
        //Agregar funcionalidad de agregar a la cola de espera
        return "Capacidad maxima alcanzada. Error al agregar la reserva";
    }
}

string GraderiaPreferencial::pagarReserva() {
    if(getTope() == nullptr) {
        return "No hay reservas pendientes en esta localidad";
    }
    else{
        if(validarPagoReserva()){
            NodoReserva* aux = getTope();
            tope = tope->getSiguiente();
            delete aux;
            setCantidadPagada(getCantidadPagada() + 1);
            setCantidadReservada(getCantidadReservada() - 1);
            return "Pago realizado";
        }
        else{
            return "El pago no pudo ser realizado. Favor revisar que hayan reservas pendientes";
        }
    }
}

string GraderiaPreferencial::mostrarEspacios() {
    return std::__cxx11::string();
}

bool GraderiaPreferencial::validarEspacios() {
    return getCantidadReservada() + 1 + getCantidadPagada() <= getCantidadMaxima();
}

bool GraderiaPreferencial::validarPagoReserva() {
    return getCantidadPagada() <= getCantidadMaxima();
}
