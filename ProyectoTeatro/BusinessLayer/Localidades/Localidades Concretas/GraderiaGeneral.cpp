//
// Created by Andres on 11/20/2019.
//

#include "GraderiaGeneral.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

GraderiaGeneral::GraderiaGeneral() : Graderia(){
    setCabeza(nullptr);
    setCola(nullptr);
}

GraderiaGeneral::GraderiaGeneral(int pCantidadMaxima) : Graderia(pCantidadMaxima) {
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

NodoReserva *GraderiaGeneral::getCola() const {
    return cola;
}

/*
 * =================
 * SETTER
 * =================
 */

void GraderiaGeneral::setCabeza(NodoReserva *cabeza) {
    GraderiaGeneral::cabeza = cabeza;
}

void GraderiaGeneral::setCola(NodoReserva *cola) {
    GraderiaGeneral::cola = cola;
}

/*
 * =================
 * OVERWRITTEN
 * =================
 */

string GraderiaGeneral::agregarReserva(Reserva pReserva) {
    if(validarEspacios()){
        NodoReserva* nodoReserva = new NodoReserva(pReserva);
        if(getCabeza() == nullptr){
            nodoReserva->setSiguiente(getCabeza());
            cabeza = nodoReserva;
            cola = nodoReserva;
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
    else{
        //Agregar funcionalidad de agregar a la cola de espera
        return "Capacidad maxima alcanzada. Error al agregar la reserva";
    }

}

string GraderiaGeneral::pagarReserva() {
    if(getCabeza() == nullptr) {
        return "No hay reservas pendientes en esta localidad";
    }
    else{
        if(validarPagoReserva()){
            NodoReserva* aux = getCabeza();
            cabeza = cabeza->getSiguiente();
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

bool GraderiaGeneral::validarPagoReserva() {
    return getCantidadPagada() <= getCantidadMaxima();
}

//Se valida si al sumar la cantidad de reservaciones pendientes mas el asiento requerido mas la cantidad de entradas pagadas
// es menor a la cantidad total de espacios disponibles
bool GraderiaGeneral::validarEspacios() {
    return getCantidadReservada() + 1 + getCantidadPagada() <= getCantidadMaxima();
}
