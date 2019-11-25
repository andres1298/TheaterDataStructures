//
// Created by Andres on 11/23/2019.
//

#ifndef PROYECTOINDIVIDUAL_COLAESPERA_H
#define PROYECTOINDIVIDUAL_COLAESPERA_H


#include "../Cola Espera Abstracta/ColaEsperaAbstracta.h"

class ColaEspera : public ColaEsperaAbstracta{
public:
    ColaEspera();

    string agregarReserva(Reserva reserva) override;

    Reserva removerReserva() override;
};


#endif //PROYECTOINDIVIDUAL_COLAESPERA_H
