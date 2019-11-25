//
// Created by Andres on 11/20/2019.
//

#include "GraderiaPreferencial.h"

/*
 * =================
 * CONSTRUCTORES
 * =================
 */

GraderiaPreferencial::GraderiaPreferencial() : Graderia(){
    setTope(nullptr);
}

GraderiaPreferencial::GraderiaPreferencial(int pCantidad) : Graderia(pCantidad) {
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
        //En caso de que no hayan espacios suficientes en la localidad, se agrega la reserva a la cola de espera
        return this->getColaEspera().agregarReserva(pReserva);
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

string GraderiaPreferencial::obtenerEstadisticas() {
    string informacion;
    int recaudacionTotal = 0, espaciosLibres = 0, espaciosPagados = 0;

    recaudacionTotal = getCantidadPagada() * 5500;
    espaciosLibres = getCantidadMaxima() - getCantidadPagada();
    espaciosPagados = getCantidadPagada();

    informacion.append("\n   Graderia Preferencial ");
    informacion.append("\n============================");
    informacion.append("\nEspacios disponibles: " + to_string(espaciosLibres));
    informacion.append("\nEspacios pagados: " + to_string(espaciosPagados));
    informacion.append("\nRecaudacion: " + to_string(recaudacionTotal));
    informacion.append("\n============================");

    return informacion;
}

/*
 * =================
 * LIBERAR RESERVACIONES
 * =================
 */

string GraderiaPreferencial::liberarReservaciones() {
    string informacion;
    int contador = 0;

    if(getCantidadReservada() > 0){
        NodoReserva* aux;

        while(getCantidadReservada() > 0){
            aux = getTope();
            tope = tope->getSiguiente();
            delete aux;
            contador++;
            setCantidadReservada( getCantidadReservada() - 1);
        }
        return "Fueron liberadas " + to_string(contador) + " reservas de la Graderia Preferencial";
    }
    else{
        return "No hay reservaciones pendientes en la Graderia Preferencial";
    }
}

//Se crea un ciclo para remover las reservas de la cola de espera y agregarlas a la localidad
string GraderiaPreferencial::liberarColaEspera() {
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

    return "Se han agregado " + to_string(cantidad) + " reservaciones de la cola de espera a la Graderia Preferencial";
}
