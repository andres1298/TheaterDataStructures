//
// Created by Andres on 11/20/2019.
//

#include "GraderiaGeneral.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

GraderiaGeneral::GraderiaGeneral() {
    setCabeza(nullptr);
    setCola(nullptr);
}

GraderiaGeneral::GraderiaGeneral(int pCantidadMaxima) : Localidad(pCantidadMaxima) {
    setCabeza(nullptr);
    setCola(nullptr);
}

/*
 * =================
 * GETTER
 * =================
 */

NodoReserva *GraderiaGeneral::getCabeza() const {
    return cabeza;
}

/*
 * =================
 * SETTER
 * =================
 */

void GraderiaGeneral::setCabeza(NodoReserva *cabeza) {
    GraderiaGeneral::cabeza = cabeza;
}

/*
 * =================
 * OVERWRITTEN
 * =================
 */

string GraderiaGeneral::agregarReserva(NodoReserva* nodoReserva) {
    if(validarEspacios()){
        if(getCabeza() == nullptr){
            nodoReserva->setSiguiente(getCabeza());
            cabeza = nodoReserva;
            cola = nodoReserva;
            nodoReserva->setSiguiente(nullptr);
        }
        else{
            NodoReserva* temp = getCola();
            temp->setSiguiente(nodoReserva);
            setCola(nodoReserva);
            nodoReserva->setSiguiente(nullptr);
        }
        setCantidadReservada(getCantidadReservada() + 1);
        return "Reserva agregada";
    }
    return "Capacidad maxima alcanzada. Error al agregar la reserva";
}

void GraderiaGeneral::pagarReserva(int pCantidad) {

}

bool GraderiaGeneral::validarEspacios() {
    return getCantidadReservada() + 1 <= getCantidadMaxima();
}

NodoReserva *GraderiaGeneral::getCola() const {
    return cola;
}

void GraderiaGeneral::setCola(NodoReserva *cola) {
    GraderiaGeneral::cola = cola;
}

string GraderiaGeneral::mostrarEspacios() {
    if(getCabeza() == nullptr){
        return "Graderia General Vacia";
    }
    else{
        string informacion;
        NodoReserva* aux = getCabeza();
        while(aux != nullptr){
            informacion.append(aux->getInformacion().mostrarInformacion() + " ");
            aux = aux->getSiguiente();
        }
        return informacion;
    }
}
