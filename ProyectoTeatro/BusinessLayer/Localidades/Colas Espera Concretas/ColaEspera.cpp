//
// Created by Andres on 11/23/2019.
//

#include "ColaEspera.h"

ColaEspera::ColaEspera() : ColaEsperaAbstracta(){}

string ColaEspera::agregarReserva(Reserva reserva) {
    NodoReserva* nodoReserva = new NodoReserva(reserva);

    if(getFrente() == nullptr && getFinal() == nullptr){
        setFrente(nodoReserva);
        setFinal(nodoReserva);
    }
    else{
        getFinal()->setSiguiente(nodoReserva);
        setFinal(nodoReserva);
    }
    setCantidadReservas( getCantidadReservas() + 1);
    return "Reserva agregada a la cola de espera";
}

string ColaEspera::removerReserva() {
    if(getFrente() == nullptr && getFinal() == nullptr){
        return "Cola de espera vacia. No hay reservas pendientes";
    }
    else{
        NodoReserva* auxiliar = getFrente();
        setFrente(getFrente()->getSiguiente());
        setCantidadReservas( getCantidadReservas() - 1);
        delete auxiliar;
        return "Reserva removida de la lista de espera";
    }
}
