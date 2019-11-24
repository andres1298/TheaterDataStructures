//
// Created by Andres on 11/20/2019.
//

#ifndef PROYECTOINDIVIDUAL_CONSZONAPREFERENCIAL_H
#define PROYECTOINDIVIDUAL_CONSZONAPREFERENCIAL_H


#include "../Constructor Abstracto/ConstructorAbstracto.h"

class ConsZonaPreferencial : public ConstructorAbstracto{
public:
    ConsZonaPreferencial();

    void construirLocalidad() override;

    void construirPrecio() override;

    void construirEstado() override;
};


#endif //PROYECTOINDIVIDUAL_CONSZONAPREFERENCIAL_H
