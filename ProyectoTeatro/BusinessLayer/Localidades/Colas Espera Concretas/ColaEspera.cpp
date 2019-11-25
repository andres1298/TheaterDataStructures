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

Reserva ColaEspera::removerReserva() {
    if(getFrente() == nullptr && getFinal() == nullptr){
        return Reserva();
    }
    else{
        NodoReserva* auxiliar = getFrente();
        setFrente( auxiliar->getSiguiente() );
        setCantidadReservas( getCantidadReservas() - 1);

        if(getFrente() == nullptr) setFinal(nullptr);

        return auxiliar->getInformacion();
    }

}
