//
// Created by Andres on 11/23/2019.
//

#ifndef PROYECTOINDIVIDUAL_GRADERIA_H
#define PROYECTOINDIVIDUAL_GRADERIA_H


#include "Localidad.h"

class Graderia : public Localidad{
private:

public:
    Graderia();

    Graderia(int pCantidadMaxima);

    virtual string agregarReserva(Reserva pReserva) = 0;

    virtual string pagarReserva() = 0;

    virtual bool validarPagoReserva() = 0;
};


#endif //PROYECTOINDIVIDUAL_GRADERIA_H
