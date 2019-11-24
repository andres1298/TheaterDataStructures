//
// Created by Andres on 11/23/2019.
//

#ifndef PROYECTOINDIVIDUAL_NUMERADO_H
#define PROYECTOINDIVIDUAL_NUMERADO_H


#include "Localidad.h"

class Numerado : public Localidad{

public:
    Numerado();

    Numerado(int pCantidadMaxima);

    virtual string agregarReserva(Reserva pReserva, int pAsiento) = 0;

    virtual string pagarReserva(int pAsiento) = 0;

    virtual bool validarPagoReserva(int pAsiento) = 0;
};


#endif //PROYECTOINDIVIDUAL_NUMERADO_H
