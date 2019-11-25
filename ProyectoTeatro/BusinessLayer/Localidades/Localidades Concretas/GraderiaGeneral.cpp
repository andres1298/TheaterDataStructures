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
        //En caso de que no hayan espacios suficientes en la localidad, se agrega la reserva a la cola de espera
        return this->getColaEspera().agregarReserva(pReserva);
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

/*
 * =================
 * LIBERAR RESERVACIONES
 * =================
 */

string GraderiaGeneral::liberarReservaciones() {
    string informacion;
    int contador = 0;

    if(getCantidadReservada() > 0){
        NodoReserva* aux;

        while(getCantidadReservada() > 0){
            aux = getCabeza();
            cabeza = cabeza->getSiguiente();
            delete aux;
            contador++;
            setCantidadReservada( getCantidadReservada() - 1);
        }
        return "Fueron liberadas " + to_string(contador) + " reservas  de la Graderia General";
    }
    else{
        return "No hay reservaciones pendientes en la Graderia General";
    }
}

//Se crea un ciclo para remover las reservas de la cola de espera y agregarlas a la localidad
string GraderiaGeneral::liberarColaEspera() {
    int cantidad = 0;

    //Se repite mientras hayan reservas pendientes en la cola

    while(getColaEspera().getCantidadReservas() > 0){

        //Se valida si aun hay espacio en la localidad para agregar mas reservas de la cola

        if(validarEspacios()){

            //Si hay espacios, se agrega la reserva proveniente de la cola
            this->agregarReserva(getColaEspera().removerReserva());
            cantidad++;
        }
        else{

            //Si no hay mas espacios en la localidad, se retorna un string notificando la cantidad que pudieron ser agregadas y las que quedan pendientes
            return "Se han agregado " + to_string(cantidad) + " reservaciones de la cola de espera, pero se ha alcanzado el maximo de espacios. Pendientes: " + to_string(getColaEspera().getCantidadReservas());
        }
    }

    // En caso de que se pudieran agregar todas las reservas de la cola de espera, se retorna un mensaje con esta informacion.

    return "Se han agregado " + to_string(cantidad) + " reservaciones de la cola de espera a la Graderia General";
}
