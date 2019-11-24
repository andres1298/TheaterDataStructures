//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_DIRECTORCONSTRUCCION_H
#define PROYECTOINDIVIDUAL_DIRECTORCONSTRUCCION_H


#include "../Constructor Abstracto/ConstructorAbstracto.h"

class DirectorConstruccion {
public:
    DirectorConstruccion();

    void construirReserva(ConstructorAbstracto *constructor);
};


#endif //PROYECTOINDIVIDUAL_DIRECTORCONSTRUCCION_H
