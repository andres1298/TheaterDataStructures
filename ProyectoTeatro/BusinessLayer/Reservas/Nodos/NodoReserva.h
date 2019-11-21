//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_NODORESERVA_H
#define PROYECTOINDIVIDUAL_NODORESERVA_H


#include "../Reserva Concreta/Reserva.h"

class NodoReserva {

private:
    Reserva informacion;
    NodoReserva* siguiente;

public:
    NodoReserva(const Reserva &pInformacion);

    NodoReserva();

    const Reserva getInformacion() const;

    NodoReserva *getSiguiente() const;

    void setInformacion(const Reserva &informacion);

    void setSiguiente(NodoReserva *siguiente);
};


#endif //PROYECTOINDIVIDUAL_NODORESERVA_H
