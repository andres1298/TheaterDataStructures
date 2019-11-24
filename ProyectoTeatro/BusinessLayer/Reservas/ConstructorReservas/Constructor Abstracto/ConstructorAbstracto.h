//
// Created by Andres on 11/23/2019.
//

#ifndef PROYECTOINDIVIDUAL_CONSTRUCTORABSTRACTO_H
#define PROYECTOINDIVIDUAL_CONSTRUCTORABSTRACTO_H


#include "../../Reserva Concreta/Reserva.h"

class ConstructorAbstracto {

private:
    Reserva reserva;

public:
    ConstructorAbstracto();

     Reserva &getReserva();

    void setReserva(const Reserva &reserva);

    void construirReserva();

    virtual void construirLocalidad() = 0;

    virtual void construirPrecio() = 0;

    virtual void construirEstado() = 0;
};


#endif //PROYECTOINDIVIDUAL_CONSTRUCTORABSTRACTO_H
